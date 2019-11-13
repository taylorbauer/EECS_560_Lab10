#ifndef BINOMIAL_TREE_H
#define BINOMIAL_TREE_H
#include "Node.h"

class BinomialTree {
    public:
    BinomialTree();
    BinomialTree(int value);
    void print(int depth, Node* root);
    int getDepth();
    Node* root;
    int order;
};

#endif