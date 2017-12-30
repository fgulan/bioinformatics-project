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

private:
    alphabet_t alphabet_;
    WaveletNode const *root_;

};

#endif //BIOINFORMATICS_PROJECT_WAVELETTREE_H
