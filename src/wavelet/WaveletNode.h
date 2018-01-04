//
// Created by Bartol Freskura on 30/12/2017.
//

#ifndef BIOINFORMATICS_PROJECT_WAVELETNODE_H
#define BIOINFORMATICS_PROJECT_WAVELETNODE_H

#include <vector>
#include "../shared/common.h"
#include "../rrr/RRRSequence.h"

class WaveletNode
{
public:

    WaveletNode(std::string const &sequence,
                alphabet_t const &alphabet,
                size_t alphabet_start,
                size_t alphabet_end,
                RRRTable const &rrr_table,
                WaveletNode const *parent = nullptr);

    class_t rank1(size_t index) const;
    class_t rank0(size_t index) const;

    size_t select1(uint64_t count) const;
    size_t select0(uint64_t count) const;

    char_t access(size_t index) const;

    size_t alphabet_mid_index() const;
    size_t alphabet_start_index() const;
    size_t alphabet_end_index() const;

    WaveletNode const *parent() const;
    WaveletNode const *left() const;
    WaveletNode const *right() const;

private:

    RRRSequence rrr_sequence_;

    WaveletNode const *parent_;
    WaveletNode const *left_;
    WaveletNode const *right_;

    size_t alphabet_mid_;
    size_t alphabet_start_;
    size_t alphabet_end_;
};

#endif //BIOINFORMATICS_PROJECT_WAVELETNODE_H
