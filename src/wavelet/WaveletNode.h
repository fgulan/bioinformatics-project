//
// Created by Bartol Freskura on 30/12/2017.
//

#ifndef BIOINFORMATICS_PROJECT_WAVELETNODE_H
#define BIOINFORMATICS_PROJECT_WAVELETNODE_H

#include <vector>
#include "../shared/common.h"
#include "../rrr/RRRSequence.h"

/**
 * WaveletNode is a node representation of a binary wavelet tree implemented using RRR structure.
 * @author Bartol Freskura
 */
class WaveletNode
{
public:

    /**
     * Class constructor
     * @param sequence sequence used to create the node
     * @param alphabet alphabet of the whole sequence
     * @param alphabet_start start position in the alphabet for the given sequence
     * @param alphabet_end end position in the alphabet for the given sequence
     * @param rrr_table Reference to the rrr table instance
     * @param parent parent of this node
     */
    WaveletNode(std::string const &sequence,
                alphabet_t const &alphabet,
                size_t alphabet_start,
                size_t alphabet_end,
                RRRTable const &rrr_table,
                WaveletNode const *parent = nullptr);

    /**
     * Calculates rank of 1s to index
     * @param index position to count 1s to, included
     * @return rank 1 till the given index
     */
    class_t rank1(size_t index) const;

    /**
     * Calculates rank of 0s to index
     * @param index position to count 0s to, included
     * @return rank 0 till the given index
     */
    class_t rank0(size_t index) const;

    /**
     * Calculates the index at which count-th 1 appears
     * @param count number of 1s
     * @return index at which count-th 1 appears
     */
    size_t select1(uint64_t count) const;

    /**
     * Calculates the index at which count-th 0 appears
     * @param count number of 0s
     * @return index at which count-th 0 appears
     */
    size_t select0(uint64_t count) const;

    /**
     * Returns the character of the sequence at specified index
     * @param index index in the sequence
     * @return character in the sequence at the specified index
     */
    char_t access(size_t index) const;

    /**
     * Index of the middle of alphabet
     * @return index of the middle of alphabet
     */
    size_t alphabet_mid_index() const;

    /**
     * Index of the start of alphabet
     * @return index of the start of alphabet
     */
    size_t alphabet_start_index() const;

    /**
     * Index of the end of alphabet
     * @return index of the end of alphabet
     */
    size_t alphabet_end_index() const;

    /**
     * Returns parent of the node
     * @return parent of the node
     */
    WaveletNode const *parent() const;

    /**
     * Returns left child of the node
     * @return left child of the node
     */
    WaveletNode const *left() const;

    /**
     * Returns right child of the node
     * @return right child of the node
     */
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
