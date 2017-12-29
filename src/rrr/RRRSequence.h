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

    RRRSequence(block_vector_t const &sequence,
                uint8_t blocks_in_superblock,
                block_size_t block_size,
                RRRTable const &table);

    RRRSequence(block_vector_t const &sequence, RRRTable const &table);

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
};


#endif //BIOINFORMATICS_PROJECT_RRRSEQUENCE_H
