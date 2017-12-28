//
// Created by Jure Cular on 28/12/2017.
//

#include <cassert>
#include <cmath>
#include "RRRTable.h"

RRRTable::RRRTable(block_size_t block_size) : table{block_size + 1},
                                              bit_offset_vector(block_size + 1, 0),
                                              block_size{block_size}
{
    assert(block_size != 0);

    for (size_t i = 0; i < block_size; ++i) {
        block_vector_t block(block_size, ZERO);

        for (auto it = block.end() - i; it != block.end(); ++it) {
            *it = ONE;
        }

        do {
            table[i].emplace_back(block_vector_to_bit_block(block), rank_per_bit(block));
        } while (std::next_permutation(block.begin(), block.end()));

        bit_offset_vector[i] = static_cast<bit_offset_t>(std::ceil(std::log2(table[i].size())));
    }
}

rank_vector_per_bit_t RRRTable::rank_per_bit(block_vector_t const &vector) const
{
    rank_vector_per_bit_t rank_per_bit_vector(vector.size());
    uint8_t rank = 0;

    for (size_t i = 0, size = rank_per_bit_vector.size(); i < size; ++i) {
        rank += vector[i] - ZERO;
        rank_per_bit_vector[i] = rank;
    }

    return rank_per_bit_vector;
}

block_bit_t RRRTable::block_vector_to_bit_block(block_vector_t const &block_vector) const
{
    block_bit_t block = 0;

    size_t i = 0, size = block_vector.size();
    for (; i < size; ++i) {
        block |= block_vector[i] - ZERO;
        block <<= 1;
    }

    block <<= block_size - i;
    block >>= 1;

    return block;
}
