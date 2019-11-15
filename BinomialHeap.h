//
//  Author: Taylor Bauer
//  Date:   11.17.2019
//          EECS 560
//          Lab 10
//

#ifndef BINOMIAL_HEAP_H
#define BINOMIAL_HEAP_H
#include "BinomialTree.h"

class BinomialHeap {
    public:

        //  A basic constructor
        BinomialHeap();

        //  Prints the heap in level order.  It prints the tree of order 0 first, then 1, then 2 up to k
        //  It skips a tree if it has an order of 0
        void print();

        //  Creates a new node with a key equal to passed value and inserts it in the heap
        //  This calls some functions in BinomialTree
        void insert(int value);

        //  Searches for and deletes the minimum value from the heap
        //  This deletes the node and creates new trees of its children, and then inserts them into the heap
        void deleteMin();
    private:

        //  A helper function for both insert and deleteMin
        void mergeUp(int index, BinomialTree tree);


        int size;               // The size of the heap
        BinomialTree arr[50];   // Our list of BinomialTrees
};

#endif