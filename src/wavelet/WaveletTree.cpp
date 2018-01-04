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

size_t WaveletTree::rank(char_t symbol, size_t index) const
{
    auto const *current_node = root_;
    auto current_rank = index;
    size_t symbol_index = symbol_index_in_alphabet(symbol);

    while (current_node) {
        // Due to 0-biasing (n-th bit, but we count
        // indexes from 0, so -1 to current index)
        if (current_node != root_) {
            current_rank -= 1;
        }

        if (symbol_index < current_node->alphabet_mid_index()) {
            current_rank = current_node->rank0(current_rank);
            current_node = current_node->left();
        } else {
            current_rank = current_node->rank1(current_rank);
            current_node = current_node->right();
        }

        // Break point, makes no sense to access < 0 indexes
        // since they do not exist...
        if (current_rank == 0) {
            break;
        }
    }
    return current_rank;
}

size_t WaveletTree::select(char_t symbol, size_t count) const
{
    size_t symbol_index = symbol_index_in_alphabet(symbol);
    WaveletNode const *current_node = starting_node_for_symbol_index(symbol_index);
    auto select_val = symbol_index < current_node->alphabet_mid_index()
                      ? current_node->select0(count)
                      : current_node->select1(count);

    while (current_node != root_) {
        // Due to 0-biasing (n-th bit, but we count
        // indexes from 0, so +1 to current select value)
        select_val++;
        WaveletNode const *parent = current_node->parent();
        select_val = current_node == parent->left()
                     ? parent->select0(select_val) : parent->select1(select_val);
        current_node = parent;
    }
    return select_val;
}

char_t WaveletTree::access(size_t index) const
{
    auto const *current_node = root_;
    size_t current_index = index;
    char_t symbol= 0;

    while (current_node) {
        // Due to 0-biasing (n-th bit, but we count
        // indexes from 0, so -1 to current index)
        if (current_node != root_) {
            current_index -= 1;
        }

        if (current_node->access(current_index) == 0) {
            current_index = current_node->rank0(current_index);
            if (!current_node->left()) {
                symbol = alphabet_[current_node->alphabet_start_index()];
                break;
            }
            current_node = current_node->left();
        } else {
            current_index = current_node->rank1(current_index);
            if (!current_node->right()) {
                symbol = alphabet_[current_node->alphabet_end_index()];
                break;
            }
            current_node = current_node->right();
        }
    }
    return symbol;
}

// MARK: - Private methods -

size_t WaveletTree::symbol_index_in_alphabet(char_t symbol) const
{
    // Good job C++, really nice and expressive...
    auto it_symbol = std::lower_bound(alphabet_.begin(), alphabet_.end(), symbol);
    return static_cast<size_t>(std::distance(alphabet_.begin(), it_symbol));
}

WaveletNode const *WaveletTree::starting_node_for_symbol_index(size_t symbol_index) const
{
    WaveletNode const *return_node, *current_node = root_;
    while (current_node) {
        return_node = current_node;
        current_node = symbol_index < current_node->alphabet_mid_index()
                       ? current_node->left()
                       : current_node->right();
    }
    return return_node;
}
