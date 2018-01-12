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

public:

    /**
     * Class constructor
     * @param block_size size of blocks used to initialize RRR table
     */
    explicit RRRTable(block_size_t block_size);

    /**
     * Default class contructor
     */
    RRRTable() = default;

    /**
     * Default copy constructor
     */
    RRRTable(RRRTable const &) = default;

    /**
     * Default move constructor
     */

    RRRTable(RRRTable &&) = default;

    /**
     * Default copy assignment
     */
    RRRTable &
    operator=(RRRTable const &) = default;

    /**
     * Default move assignment
     * @return
     */
    RRRTable &
    operator=(RRRTable &&) = default;

    /**
    * Offset in the table for given rank and block vector
    * @param rank rank of the block vector
    * @param block_vector block vector value
    * @return offset in the table of the block vector of given rank
    */
    offset_t
    get_offset_for_rank(class_t rank, block_vector_t const &block_vector) const;

    /**
     * Calculates number of bits used to store the offsets for given rank
     * @param rank rank value
     * @return number of bits used to store the offsets for given rank
     */
    bit_offset_t
    get_bit_offset(class_t rank) const;

    /**
     * Calculates the rank inside the block at the given index
     * @param block_rank rank of the whole block
     * @param offset offset of the block
     * @param index index in the block
     * @return
     */
    class_t
    get_rank_at_index(class_t block_rank, offset_t offset, uint64_t index) const;

    /**
     * Calculates the index at which rank of 1s appears in the block
     * @param block_rank rank of the block
     * @param offset offset of the block in the table
     * @param rank rank value searched for
     * @return index of the searched rank
     */
    size_t
    index_with_rank1(class_t block_rank, offset_t offset, class_t rank) const;

    /**
     * Calculates the index at which rank of 0s appears in the block
     * @param block_rank rank of the block
     * @param offset offset of the block in the table
     * @param rank rank value searched for
     * @return index of the searched rank
     */
    size_t
    index_with_rank0(class_t block_rank, offset_t offset, class_t rank) const;

private:

    table_t table;

    std::vector<bit_offset_t> bit_offset_vector;

private:

    rank_vector_per_bit_t
    rank_per_bit(block_vector_t const &vector) const;

    block_bit_t
    block_vector_to_bit_block(block_vector_t const &block_vector) const;
};


#endif //BIOINFORMATICS_PROJECT_RRRTABLE_H
