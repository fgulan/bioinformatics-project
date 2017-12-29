//
// Created by Jure Cular on 28/12/2017.
//

#ifndef BIOINFORMATICS_PROJECT_RRRTABLE_H
#define BIOINFORMATICS_PROJECT_RRRTABLE_H

#include "../shared/common.h"

class RRRTable
{
public:

    block_size_t block_size;

    explicit RRRTable(block_size_t block_size);

    RRRTable() = default;

    RRRTable(RRRTable const &) = default;

    RRRTable(RRRTable &&) = default;

    RRRTable &
    operator=(RRRTable const &) = default;

    RRRTable &
    operator=(RRRTable &&) = default;

    offset_t
    get_offset_for_rank(class_t rank, block_vector_t const &block_vector) const;

    bit_offset_t
    get_bit_offset(class_t rank) const;

    class_t
    get_rank_at_index(class_t block_rank, offset_t offset, uint64_t index) const;

    size_t
    index_with_rank1(class_t block_rank, offset_t offset, class_t rank) const;

    size_t
    index_with_rank0(class_t block_rank, offset_t offset, class_t rank) const;

private:

    table_t table;

    std::vector<bit_offset_t> bit_offset_vector;

    rank_vector_per_bit_t
    rank_per_bit(block_vector_t const &vector) const;

    block_bit_t
    block_vector_to_bit_block(block_vector_t const &block_vector) const;
};


#endif //BIOINFORMATICS_PROJECT_RRRTABLE_H
