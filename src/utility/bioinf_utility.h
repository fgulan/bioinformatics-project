//
// Created by Filip Gulan on 02/01/2018.
//

#ifndef BIOINFORMATICS_PROJECT_BIOINF_UTILITY_H
#define BIOINFORMATICS_PROJECT_BIOINF_UTILITY_H

#include <string>
#include "../shared/common.h"

std::string read_fasta_file(char const* filename);
measured_memory_t get_current_memory();

#endif //BIOINFORMATICS_PROJECT_BIOINF_UTILITY_H
