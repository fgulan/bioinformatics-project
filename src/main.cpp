#include <iostream>
#include "utility/bioinf_utility.h"

int main()
{
    std::string file = read_fasta_file("tests/sequences/ecoli.fa");
    auto len = file.length();
    return 0;
}