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

using block_size_t = size_t;

using class_t = uint64_t;
using offset_t = uint64_t;

using block_bit_t = uint64_t;
using rank_vector_per_bit_t = std::vector<class_t>;

using bit_offset_t = uint64_t;

using block_vector_t = std::string;

using table_t = std::vector<std::vector<std::pair<block_bit_t, rank_vector_per_bit_t>>>;

using rank_vector_per_bit_t = std::vector<class_t>;

using superblock_size_t = size_t;

using rrr_sequence_t = std::vector<std::pair<class_t, offset_t>>;
using superblock_sequence_t = std::vector<std::pair<class_t, offset_t>>;

#endif //BIOINFORMATICS_PROJECT_COMMON_H
