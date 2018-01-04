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

    explicit WaveletTree(std::string const &sequence);

    size_t rank(char_t symbol, size_t index) const;
    size_t select(char_t symbol, size_t count) const;
    char_t access(size_t index) const;
private:

    alphabet_t alphabet_;
    WaveletNode const *root_;

private:

    size_t symbol_index_in_alphabet(char_t symbol) const;
    WaveletNode const * starting_node_for_symbol_index(size_t symbol_index) const;
};

#endif //BIOINFORMATICS_PROJECT_WAVELETTREE_H
