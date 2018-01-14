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
    using std::ios_base;
    using std::ifstream;
    using std::string;

    // 'file' stat seems to give the most reliable results
    //
    ifstream stat_stream("/proc/self/stat",ios_base::in);

    // dummy vars for leading entries in stat that we don't care about
    //
    string pid, comm, state, ppid, pgrp, session, tty_nr;
    string tpgid, flags, minflt, cminflt, majflt, cmajflt;
    string utime, stime, cutime, cstime, priority, nice;
    string O, itrealvalue, starttime;

    // the two fields we want
    //
    unsigned long vsize;

    stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
                >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
                >> utime >> stime >> cutime >> cstime >> priority >> nice
                >> O >> itrealvalue >> starttime >> vsize; // don't care about the rest

    stat_stream.close();

    return vsize;
#else
    return 0;
#endif
}