//
// Created by Filip Gulan on 30/12/2017.
//

#ifndef BIOINFORMATICS_PROJECT_WAVELETTREE_H
#define BIOINFORMATICS_PROJECT_WAVELETTREE_H

#include <string>
#include "WaveletNode.h"
#include "../shared/common.h"

class WaveletTree
{
public:

    /**
     * Class constructor
     * @param sequence sequence used to initialize wavelet tree instance
     */
    explicit WaveletTree(std::string const &sequence);

    /**
     * Rank query of the character in the sequence till index
     * @param symbol character used to query
     * @param index index till characters are counted, included
     * @return number of characters in the sequence untill index
     */
    size_t rank(char_t symbol, size_t index) const;

    /**
     * Select query of the character in the sequence for the count
     * @param symbol character used to query
     * @param count count of characters
     * @return index of the count-th character
     */
    size_t select(char_t symbol, size_t count) const;

    /**
     * Returns the character in the sequence at the index
     * @param index index of character
     * @return character at the index in the sequence
     */
    char_t access(size_t index) const;
private:

    alphabet_t alphabet_;
    WaveletNode const *root_;

private:

    size_t symbol_index_in_alphabet(char_t symbol) const;
    WaveletNode const * starting_node_for_symbol_index(size_t symbol_index) const;
};

#endif //BIOINFORMATICS_PROJECT_WAVELETTREE_H
