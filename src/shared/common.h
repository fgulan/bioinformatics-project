//
// Created by Jure Cular on 28/12/2017.
//

#ifndef BIOINFORMATICS_PROJECT_COMMON_H
#define BIOINFORMATICS_PROJECT_COMMON_H

#include <cstdint>
#include <string>
#include <vector>

#define ONE '1'
#define ZERO '0'

/**
 * Block size type
 */
using block_size_t = size_t;

/**
 * Rank type
 */
using class_t = uint32_t;

/**
 * Block offset in the RRR table type
 */
using offset_t = uint32_t;

/**
 * Block offset in the superblock type
 */
using superblock_offset_t = size_t;

/**
 * Block type
 */
using block_bit_t = uint64_t;

/**
 * Vector of ranks per bit type
 */
using rank_vector_per_bit_t = std::vector<class_t>;

/**
 * Bit size of rank type
 */
using bit_rank_t = uint8_t;

/**
 * Bit size of offset type
 */
using bit_offset_t = uint8_t;

/**
 * Block vector type
 */
using block_vector_t = std::string;

/**
 * RRR table type
 */
using table_t = std::vector<std::vector<std::pair<block_bit_t, rank_vector_per_bit_t>>>;

/**
 * Superblock size type
 */
using superblock_size_t = size_t;

/**
 * RRR sequence type
 */
using rrr_sequence_t = std::vector<uint64_t>;
/**
 * Superblock sequence type
 */
using superblock_sequence_t = std::vector<std::pair<class_t, superblock_offset_t>>;

/**
 * Char type
 */
using char_t = char;

/**
 * Alphabet type
 */
using alphabet_t = std::vector<char_t>;

/**
 * Measured time type
 */
using measured_time_t = long long;

/**
 * Measured memory type
 */
using measured_memory_t = unsigned long;

#endif //BIOINFORMATICS_PROJECT_COMMON_H
