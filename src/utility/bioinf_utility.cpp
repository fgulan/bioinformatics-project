//
// Created by Filip Gulan on 02/01/2018.
//

#include <fstream>
#include "bioinf_utility.h"

#ifdef __APPLE__
#include <mach/mach.h>
#endif

std::string read_fasta_file(char const* filename)
{
    std::ifstream fasta_stream(filename);

    if (!fasta_stream.is_open()) {
        throw std::invalid_argument(std::string("File not found: ") + filename);
    } else if (!fasta_stream.good()) {
        throw std::runtime_error(std::string("Invalid file: ") + filename);
    }

    std::string content, line;
    while (std::getline(fasta_stream, line)) {
        if (line.empty() || line[0] == '>' || line[0] == ',') {
            continue;
        }
        content += line;
    }
    return content;
}

measured_memory_t get_current_memory()
{
#ifdef __APPLE__
    struct task_basic_info t_info;
    mach_msg_type_number_t t_info_count = TASK_BASIC_INFO_COUNT;

    if (KERN_SUCCESS != task_info(mach_task_self(),
                                  TASK_BASIC_INFO, (task_info_t)&t_info,
                                  &t_info_count)) {
        return 0;
    }
    return t_info.resident_size;
#elif __linux
    return 0;
#else
    return 0;
#endif
}