#ifndef BINOMIAL_HEAP_H
#define BINOMIAL_HEAP_H
#include "BinomialTree.h"

class BinomialHeap {
    public:
        BinomialHeap();
        void print();
        void insert(int value);
    private:
        void mergeUp(int index, BinomialTree tree);
        int size;
        BinomialTree arr[50];
};

#endif