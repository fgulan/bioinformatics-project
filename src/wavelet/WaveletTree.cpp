//
// Created by Filip Gulan on 30/12/2017.
//

#include <array>
#include <cmath>
#include "WaveletTree.h"

#define ALPHABET_SIZE 256

// MARK: - Constructors -

WaveletTree::WaveletTree(std::string const &sequence)
{
    // Assume that alphabet symbol is 2-byte type (char)
    // MAYBE: Find better solution
    std::array<int8_t, ALPHABET_SIZE> alphabet_indexes;
    std::fill(alphabet_indexes.begin(), alphabet_indexes.end(), -1);

    for (auto symbol : sequence) {
        alphabet_indexes[symbol] = 1;
    }

    // Create index based alphabet
    for (size_t i = 0, count = alphabet_indexes.size(); i < count; ++i) {
        if (alphabet_indexes[i] == 1) {
            alphabet_.push_back(i);
        }
    }

    auto block_size = static_cast<block_size_t>(
            std::max<double>(std::floor(std::log2(sequence.size()) / 2), 1));
    root_ = new WaveletNode(sequence, alphabet_, 0, alphabet_.size(), RRRTable(block_size));
}

// MARK: - Public methods -

// MARK: - Private methods -
