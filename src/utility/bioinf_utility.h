//
// Created by Filip Gulan on 02/01/2018.
//

#ifndef BIOINFORMATICS_PROJECT_BIOINF_UTILITY_H
#define BIOINFORMATICS_PROJECT_BIOINF_UTILITY_H

#include <string>
#include "../shared/common.h"
/**
 * Used to reac FASTA files
 * @param filename name of the FASTA file
 * @return contents of the FASTA file
 */
std::string read_fasta_file(char const* filename);

/**
 * Returns current memory used
 */
#ifdef __APPLE__
measured_memory_t get_current_memory();
#elif __linux__
double get_current_memory();
#endif

#endif //BIOINFORMATICS_PROJECT_BIOINF_UTILITY_H
