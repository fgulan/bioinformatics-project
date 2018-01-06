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
                                                  table(table),
                                                  rank_bit_size(static_cast<bit_rank_t>(std::ceil(std::log2(block_size + 1))))
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

    size_t index = 0;
    uint8_t filled_bits = 0;

    for (size_t i = 0; i < superblock_number; ++i) {
        superblock_offset_t superblock_offset = coding_size * index + filled_bits + rank_bit_size;
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
            pack(rank_offset_pair.first, rank_bit_size, rank_offset_pair.second, index, rrr_sequence, filled_bits, table);

            global_rank += rank_offset_pair.first;

            // Offset at what index in RRR sequence this superblock begins.
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
    superblock_offset_t offset = superblocks[superblock_index].second;
    for(size_t i = superblock_index * blocks_in_superblock; i < block_index; ++i) {
        // TODO: decode bits and add rank
        class_t rank = unpack(offset, rank_bit_size, table, rrr_sequence).first;
        result += rank;
        offset += rank_bit_size + table.get_bit_offset(rank);
    }

    class_t rank;
    offset_t table_offset;
    std::tie(rank, table_offset) = unpack(offset, rank_bit_size, table, rrr_sequence);

    // Accumulate rank from last block
    result += table.get_rank_at_index(rank,
                                      table_offset,
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
    // So found_index - 1
    std::pair<class_t, offset_t> superblock{count, 0};
    auto superblock_iterator = std::lower_bound(superblocks.begin(), superblocks.end(), superblock);
    auto distance = std::distance(superblocks.begin(), superblock_iterator);
    auto superblock_index = static_cast<size_t>(std::max<class_t>(0, distance - 1));

    // Get current superblock with whose cumulative rank is smaller than count
    class_t current_rank = superblocks[superblock_index].first;
    superblock_offset_t offset = superblocks[superblock_index].second;
    size_t sequence_size = rrr_sequence.size();

    size_t block_index = superblock_index * blocks_in_superblock;
    size_t block_end_index = (superblock_index + 1) * blocks_in_superblock;

    for (; block_index < block_end_index; ++block_index) {
        class_t rank = unpack(offset, rank_bit_size, table, rrr_sequence).first;
        if (current_rank + rank >= count) {
            break;
        }
        offset += rank_bit_size + table.get_bit_offset(rank);
        current_rank += rank;
    }

    // TODO: decode bits and add rank
    class_t rank;
    offset_t offset_table;
    std::tie(rank, offset_table) = unpack(offset, rank_bit_size, table, rrr_sequence);

    // Get the index in block whose rank is equal to count - current_rank
    size_t result = table.index_with_rank1(rank,
                                           offset_table,
                                           static_cast<class_t>(count) - current_rank);
    // Index to this superblock
    result += block_index * block_size;
    return result;
}

size_t RRRSequence::select0(uint64_t count) const
{
    // Get superblock with whose cumulative rank0 is smaller than count
    size_t superblock_index = get_superblock0_index_for_count(count);
    class_t current_rank0 = superblock_index * blocks_in_superblock * block_size
                            - superblocks[superblock_index].first;
    superblock_offset_t offset = superblocks[superblock_index].second;

    size_t block_index = superblock_index * blocks_in_superblock;
    size_t block_end_index = (superblock_index + 1) * blocks_in_superblock;

    for (; block_index < block_end_index; ++block_index) {
        class_t rank = unpack(offset, rank_bit_size, table, rrr_sequence).first;
        class_t rank0_in_block = block_size - rank;//rrr_sequence[block_index].first;
        if (current_rank0 + rank0_in_block >= count) {
            break;
        }
        offset += rank_bit_size + table.get_bit_offset(rank);
        current_rank0 += rank0_in_block;
    }

    // TODO: decode bits and add rank sequence

    class_t rank;
    offset_t offset_table;
    std::tie(rank, offset_table) = unpack(offset, rank_bit_size, table, rrr_sequence);

    // Get the index in block whose rank is equal to count - current_rank0
    size_t result = table.index_with_rank0(rank,
                                           offset_table,
                                           static_cast<class_t>(count - current_rank0));
    // Index to this superblock
    result += block_index * block_size;
    return result;
}

char_t
RRRSequence::access(size_t index) const
{
    char_t value;
    if (index == 0) {
        value = static_cast<char_t>(rank1(index));
    } else {
        value = static_cast<char_t>(rank1(index) - rank1(index - 1));
    }
    return value;
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
    for (char &it : block) {
        if (it == ONE) {
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

size_t RRRSequence::get_superblock0_index_for_count(uint64_t count) const
{
    size_t begin = 1;
    size_t end = superblocks.size() - 1;
    while (begin <= end) {
        size_t mid = (begin + end) / 2;
        auto rank0_mid = mid * blocks_in_superblock * block_size - superblocks[mid].first;

        if (rank0_mid >= count) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return begin - 1;
}

void
RRRSequence::pack(class_t rank, bit_rank_t rank_bit_size, offset_t offset, size_t &index, rrr_sequence_t &sequence, uint8_t &filled_bits, RRRTable const &rrrTable)
{
    uint8_t offset_size = rrrTable.get_bit_offset(rank);

    uint64_t coded = (rank << offset_size) | offset;

    uint8_t coded_bit_size = rank_bit_size + offset_size;

    auto pack_bits = static_cast<int64_t>(coding_size - filled_bits - coded_bit_size);

    if (sequence.size() <= index) {
        sequence.emplace_back(0);
    }

    if (pack_bits < 0) {
        sequence[index] |= coded >> std::abs(pack_bits);

        uint64_t rest_of_coded = coded << (2 * coding_size - filled_bits - coded_bit_size);
        sequence.emplace_back(rest_of_coded);
        filled_bits = coded_bit_size + filled_bits - coding_size;

        index++;
    } else {
        sequence[index] |= coded << pack_bits;
        filled_bits += coded_bit_size;
    }
}

std::pair<class_t, offset_t> RRRSequence::unpack(size_t index, bit_rank_t rank_bit_size, RRRTable const &rrrTable, rrr_sequence_t const &sequence)
{
    size_t begin = index - rank_bit_size;
    size_t rank_end = index;

    class_t rank = 0;
    offset_t offset = 0;

    size_t sequence_index = begin / coding_size;

    if (!(begin / coding_size != rank_end / coding_size && rank_end % coding_size != 0)) {
        // codded seqeunce doesn't overflow

        // shift sequence to the left to get rid of predecesing 1s
        auto shift_seq = sequence[sequence_index] << (begin % coding_size);

        rank = shift_seq >> (coding_size - rank_bit_size);
        uint8_t offset_bit_size = rrrTable.get_bit_offset(rank);

        offset = (shift_seq << rank_bit_size) >> (coding_size - offset_bit_size);
    } else {
        // codded seqeunce overflows
        size_t first_part_offset = begin % coding_size;
        size_t first_part_size = coding_size - first_part_offset;
        uint64_t first_part = sequence[sequence_index] << first_part_offset;

        uint64_t partial_second_part = sequence[sequence_index+1] >> (coding_size - first_part_offset);

        // get rank from first part and the partial second part
        rank = (first_part | partial_second_part) >> (coding_size - rank_bit_size);

        uint8_t offset_bit_size = rrrTable.get_bit_offset(rank);
        size_t second_part_size = rank_bit_size + offset_bit_size - first_part_size;

        // get offset by calculating second part
        uint64_t second_part = sequence[sequence_index+1] >> (coding_size - second_part_size);

        uint64_t full_coded_part = first_part | second_part;

        offset = (full_coded_part << rank_bit_size) >> (coding_size - offset_bit_size);
    }

    return std::make_pair(rank, offset);
}