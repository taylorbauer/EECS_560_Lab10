#ifndef BINOMIAL_HEAP_H
#define BINOMIAL_HEAP_H
#include "BinomialTree.h"

class BinomialHeap {
    public:
        BinomialHeap();
    private:
        int size;
        BinomialTree arr[100];
};

#endif