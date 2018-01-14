//
// Created by Filip Gulan on 29/12/2017.
//

#ifndef BIOINFORMATICS_PROJECT_RRRSEQUENCE_H
#define BIOINFORMATICS_PROJECT_RRRSEQUENCE_H

#include "../shared/common.h"
#include "RRRTable.h"
/**
 * RRRSequence is a structure which offers O(1) rank queries and
 * zeroth-order entropy compression for binary strings.
 * @author Jure Cular
 */
class RRRSequence
{
public:
    /**
    * Default class constructor, constructs an empty RRR sequence.
    */
    RRRSequence() = default;

    /**
    * Default move constructor.
    */
    RRRSequence(RRRSequence &&) = default;

    /**
    * Default copy constructor.
    */
    RRRSequence(RRRSequence const &) = default;

    /**
    * Default copy assignment.
    */
    RRRSequence &
    operator=(RRRSequence const &) = default;

    /**
    * Default move assignment.
    */
    RRRSequence &
    operator=(RRRSequence &&) = default;

    /**
     * Class constructor
     * @param sequence sequence of 1s and 0s
     * @param blocks_in_superblock number of blocks in superblock
     * @param block_size block size
     * @param table instance of RRR table
     */
    RRRSequence(block_vector_t const &sequence,
                uint8_t blocks_in_superblock,
                block_size_t block_size,
                RRRTable const &table);

    /**
     * Class constructor calculates sizes for blocks and
     * superblocks from the length of sequence
     * @param sequence sequence of 1s and 0s
     * @param table instance of RRR table
     */
    RRRSequence(block_vector_t const &sequence, RRRTable const &table);

    /**
     * Rank1 query over sequence
     * @param index index in the containing sequence
     * @return rank1 at given index
     */
    class_t
    rank1(size_t index) const;

    /**
     * Rank0 query over sequence
     * @param index index in the containing sequence
     * @return rank0 at given index
     */
    class_t
    rank0(size_t index) const;

    /**
     * Select1 query over sequence
     * @param count number of 1s
     * @return index at count-th 1 appears
     */
    size_t
    select1(uint64_t count) const;

    /**
     * Select0 query over sequence
     * @param count number of 0s
     * @return index at count-th 0 appears
     */
    size_t
    select0(uint64_t count) const;
    /**
     * Access query over sequence
     * @param index index in the seuence
     * @return value at the index
     */
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
