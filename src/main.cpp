#include <iostream>
#include "utility/bioinf_utility.h"
#include "rrr/RRRSequence.h"
#include "wavelet/WaveletTree.h"

int main()
{
    std::string fasta = read_fasta_file("tests/sequences/bact.fa");

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    auto mem_before = get_current_memory();
    auto tree = WaveletTree(fasta);
    auto mem_after = get_current_memory();

    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "Time difference (ms) = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;
    std::cout << "Tree size (kB) = " << (mem_after - mem_before) / 1024 << std::endl;

    return 0;
}