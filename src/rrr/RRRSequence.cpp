//
// Created by Filip Gulan on 29/12/2017.
//

#include <cmath>
#include <cassert>
#include "RRRSequence.h"

// MARK: - Constructors -

RRRSequence::RRRSequence(block_vector_t const &sequence,
                         uint8_t blocks_in_superblock,
                         block_size_t block_size,
                         RRRTable const &table) : blocks_in_superblock(blocks_in_superblock),
                                                  block_size(block_size),
                                                  table(table)
{
    // Number of blocks in sequence
    size_t block_number = static_cast<size_t>(std::ceil(
            static_cast<float_t>(sequence.size()) / block_size));

    // Number of superblocks in sequence
    size_t superblock_number = static_cast<size_t>(std::ceil(
            static_cast<float_t>(block_number) / blocks_in_superblock));

    // Number of bits in one superblock
    superblock_size_t superblock_size = block_size * blocks_in_superblock;

    // Current global rank
    class_t global_rank = 0;
    // Current superblock offset
    offset_t superblock_offset = 0;

    for (size_t i = 0; i < superblock_number; ++i) {
        superblocks.emplace_back(global_rank, superblock_offset);

        for (size_t j = 0; j < blocks_in_superblock; ++j) {
            auto block_begin = sequence.begin() + superblock_size * i + block_size * j;

            // Block begin out of bounds
            if (block_begin >= sequence.end()) { break; }

            auto block_end = block_begin + block_size;

            // If block goes over the sequence end, reduce it to sequence end
            block_end = std::distance(block_end, sequence.end()) < 0 ? sequence.end() : block_end;

            block_vector_t block = block_vector_t(block_begin, block_end);

            std::pair<class_t, offset_t> rank_offset_pair = create_rank_offset_pair(block);
            rrr_sequence.push_back(rank_offset_pair);

            global_rank += rank_offset_pair.first;

            // Offset at what index in RRR sequence this superblock begins.
            superblock_offset++;
        }
    }
}

RRRSequence::RRRSequence(block_vector_t const &sequence,
                         RRRTable const &table) : RRRSequence::RRRSequence(sequence,
                                                                           get_blocks_in_superblock(sequence.size()),
                                                                           get_block_size(sequence.size()),
                                                                           table) {};

// MARK: - Public methods -

class_t
RRRSequence::rank1(size_t index) const
{
    // Caculate block/superblock index
    size_t block_index = index / block_size;
    size_t superblock_index = block_index / blocks_in_superblock;

    // Index is out of bounds
    assert(superblock_index < superblocks.size());

    // Accumulate rank from previous superblocks
    class_t result = superblocks[superblock_index].first;
    auto i = superblock_index * blocks_in_superblock;
    for (; i != block_index; ++i) {
        result += rrr_sequence[i].first;
    }

    // Accumulate rank from last block
    result += table.get_rank_at_index(rrr_sequence[i].first,
                                      rrr_sequence[i].second,
                                      index % block_size);
    return result;
}

class_t
RRRSequence::rank0(size_t index) const
{
    return static_cast<class_t>(index - rank1(index) + 1);
}

size_t
RRRSequence::select1(uint64_t count) const
{
    // Get superblock with whose cumulative rank is smaller than count
    // Start from second superblock since we will use one before (first possibility)
    size_t superblock_index = 1, size = superblocks.size();
    for (; superblock_index < size; ++superblock_index) {
        if (count <= superblocks[superblock_index].first) {
            break;
        }
    }
    --superblock_index;

    // Get current superblock with whose cumulative rank is smaller than count
    class_t current_rank = superblocks[superblock_index].first;
    offset_t offset = superblocks[superblock_index].second;
    size_t sequence_size = rrr_sequence.size();

    for (; offset < sequence_size; ++offset) {
        if (current_rank + rrr_sequence[offset].first >= count) {
            break;
        }
        current_rank += rrr_sequence[offset].first;
    }

    // Take care if we are at sequence_last_index + 1 in
    // case that break isn't executed in previous for loop
    if (offset == sequence_size) {
        offset--;
    }

    // Get the index in block whose rank is equal to count - current_rank
    size_t result = table.index_with_rank1(rrr_sequence[offset].first,
                                           rrr_sequence[offset].second,
                                           static_cast<class_t>(count) - current_rank);
    // Index to this superblock
    result += offset * block_size;
    return result;
}

size_t RRRSequence::select0(uint64_t count) const
{
    // TODO: Implement this
    return 0;
}

// MARK: - Private methods -

std::pair<class_t, offset_t>
RRRSequence::create_rank_offset_pair(block_vector_t block) const
{
    class_t rank = popcount_for_block(block);
    offset_t offset = table.get_offset_for_rank(rank, block);
    return std::pair<class_t, offset_t>(rank, offset);
}

class_t
RRRSequence::popcount_for_block(block_vector_t block) const
{
    class_t rank = 0;
    for (auto it = block.begin(), end = block.end(); it != end; ++it) {
        if (*it == ONE) {
            rank++;
        }
    }
    return rank;
}

uint8_t
RRRSequence::get_blocks_in_superblock(size_t sequence_length) const
{
    auto block_size = get_block_size(sequence_length);
    return static_cast<uint8_t>(std::pow(std::floor(std::log2(sequence_length)), 2) / block_size);
}

block_size_t
RRRSequence::get_block_size(size_t sequence_length) const
{
    auto log_sequence_len = std::log2(sequence_length);
    return static_cast<block_size_t>(static_cast<block_size_t>(
            std::max<double>(std::floor(log_sequence_len / 2), 1)));
}
