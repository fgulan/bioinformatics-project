#include <iostream>
#include "utility/bioinf_utility.h"
#include "rrr/RRRSequence.h"
#include "wavelet/WaveletTree.h"

int main()
{
    std::string bact = read_fasta_file("tests/sequences/bact.fa");

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    auto tree = WaveletTree(bact);

    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "Time difference (ms) = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;
    return 0;
}