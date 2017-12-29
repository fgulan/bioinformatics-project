//
// Created by Filip Gulan on 29/12/2017.
//

#include <cmath>
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
