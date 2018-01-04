//
// Created by Filip Gulan on 29/12/2017.
//

#ifndef BIOINFORMATICS_PROJECT_RRRSEQUENCE_H
#define BIOINFORMATICS_PROJECT_RRRSEQUENCE_H

#include "../shared/common.h"
#include "RRRTable.h"

class RRRSequence
{
public:

    RRRSequence() = default;

    RRRSequence(RRRSequence &&) = default;

    RRRSequence(RRRSequence const &) = default;

    RRRSequence &
    operator=(RRRSequence const &) = default;

    RRRSequence &
    operator=(RRRSequence &&) = default;

    RRRSequence(block_vector_t const &sequence,
                uint8_t blocks_in_superblock,
                block_size_t block_size,
                RRRTable const &table);

    RRRSequence(block_vector_t const &sequence, RRRTable const &table);

    class_t
    rank1(size_t index) const;

    class_t
    rank0(size_t index) const;

    size_t
    select1(uint64_t count) const;

    size_t
    select0(uint64_t count) const;

    char_t
    access(size_t index) const;

private:

    RRRTable table;

    block_size_t block_size;

    uint8_t blocks_in_superblock;

    superblock_sequence_t superblocks;

    rrr_sequence_t rrr_sequence;

private:

    std::pair<class_t, offset_t> create_rank_offset_pair(block_vector_t block_begin) const;

    class_t popcount_for_block(block_vector_t block_begin) const;

    uint8_t get_blocks_in_superblock(size_t sequence_length) const;

    block_size_t get_block_size(size_t sequence_length) const;

    size_t get_superblock0_index_for_count(uint64_t count) const;
};


#endif //BIOINFORMATICS_PROJECT_RRRSEQUENCE_H
