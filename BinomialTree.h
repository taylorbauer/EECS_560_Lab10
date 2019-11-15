#ifndef BINOMIAL_TREE_H
#define BINOMIAL_TREE_H
#include "Node.h"

class BinomialTree {
    public:
    BinomialTree();
    BinomialTree(int value);
    BinomialTree(Node* r);
    ~BinomialTree();
    void print(int depth, Node* r);
    void printLevel(Node* r, int level);
    void deleteMin();
    int getDepth();
    Node* root;
    int order;
};

#endif