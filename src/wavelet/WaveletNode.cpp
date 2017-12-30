//
// Created by Bartol Freskura on 30/12/2017.
//

#include <unordered_set>
#include "WaveletNode.h"

// MARK: - Constructors -

WaveletNode::WaveletNode(std::string const &sequence,
                         alphabet_t const &alphabet,
                         size_t alphabet_start,
                         size_t alphabet_end,
                         RRRTable const &rrr_table,
                         const WaveletNode *parent) : parent_{parent},
                                                      alphabet_mid_{alphabet_start + (alphabet_end - alphabet_start + 1) / 2},
                                                      alphabet_start_{alphabet_start},
                                                      alphabet_end_{alphabet_end - 1},
                                                      left_{nullptr}, right_{nullptr}
{
    std::string left_sequence;
    std::string right_sequence;

    std::unordered_set<char_t> left_alphabet;
    std::unordered_set<char_t> right_alphabet;

    size_t child_seq_len = sequence.size() / 2;
    left_sequence.reserve(child_seq_len);
    right_sequence.reserve(child_seq_len);

    // Get alphabet mid value (left and right separator)
    char_t alphabet_mid_value = alphabet[alphabet_mid_];

    std::string rrr_string;
    rrr_string.reserve(sequence.size());

    // Fill left and right children
    for (char_t symbol : sequence) {
        if (symbol < alphabet_mid_value) {
            left_sequence.push_back(symbol);
            left_alphabet.insert(symbol);
            rrr_string.push_back(ZERO);
        } else {
            right_sequence.push_back(symbol);
            right_alphabet.insert(symbol);
            rrr_string.push_back(ONE);
        }
    }

    rrr_sequence_ = RRRSequence(rrr_string, rrr_table);

    // TODO: Need to test/check this
    if (left_alphabet.size() > 1) {
        left_ = new WaveletNode(left_sequence, alphabet, alphabet_start, alphabet_mid_, rrr_table, this);
    }

    if (right_alphabet.size() > 1) {
        right_ = new WaveletNode(right_sequence, alphabet, alphabet_mid_, alphabet_end, rrr_table, this);
    }
}

// MARK: - Public methods -

class_t WaveletNode::rank1(size_t index) const
{
    return rrr_sequence_.rank0(index);
}

class_t WaveletNode::rank0(size_t index) const
{
    return rrr_sequence_.rank1(index);
}

size_t WaveletNode::select1(uint64_t count) const
{
    return rrr_sequence_.select1(count);
}

size_t WaveletNode::select0(uint64_t count) const
{
    return rrr_sequence_.select0(count);
}

// MARK: - Getters

size_t WaveletNode::alphabet_mid_index() const
{
    return alphabet_mid_;
}

size_t WaveletNode::alphabet_start_index() const
{
    return alphabet_start_;
}

size_t WaveletNode::alphabet_end_index() const
{
    return alphabet_end_;
}

WaveletNode const *WaveletNode::parent() const
{
    return parent_;
}

WaveletNode const *WaveletNode::left() const
{
    return left_;
}

WaveletNode const *WaveletNode::right() const
{
    return right_;
}

// MARK: - Private methods -
