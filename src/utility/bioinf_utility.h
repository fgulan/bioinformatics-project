//
// Created by Filip Gulan on 02/01/2018.
//

#ifndef BIOINFORMATICS_PROJECT_BIOINF_UTILITY_H
#define BIOINFORMATICS_PROJECT_BIOINF_UTILITY_H

#include <string>
#include "../shared/common.h"

/**
 * Used to read FASTA files
 * @param filename name of the FASTA file
 * @return contents of the FASTA file
 * @author Filip Gulan
 */
std::string read_fasta_file(char const* filename);

/**
 * Returns current memory used
 * @authors Jure Cular, Filip Gulan
 */
measured_memory_t get_current_memory();

#endif //BIOINFORMATICS_PROJECT_BIOINF_UTILITY_H
