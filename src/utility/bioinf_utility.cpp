//
// Created by Filip Gulan on 02/01/2018.
//

#include <fstream>
#include "bioinf_utility.h"

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
        line.erase(line.find_last_not_of(" \n\r\t") + 1);
        content += line;
    }
    return content;
}