//
//  Author: Taylor Bauer
//  Date:   11.17.2019
//          EECS 560
//          Lab 10
//

#ifndef BINOMIAL_TREE_H
#define BINOMIAL_TREE_H
#include "Node.h"

class BinomialTree {
    public:

    //  Basic constructor, when making an empty tree
    BinomialTree();

    //  Constructor used by insert, creates a new node of key = value
    BinomialTree(int value);

    //  Constructor used by deleteMin, takes a node and uses it as root
    //  This keeps the node's siblings, children, etc.
    BinomialTree(Node* r);

    //  Destructor
    ~BinomialTree();

    //  Prints the tree in level order.
    //  This is called by the print function of BinomialHeap
    void print(int depth, Node* r);

    //  A recursive helper function for print()
    void printLevel(Node* r, int level);

    //  Called by BinomialHeap's deleteMin
    void deleteMin();

    //  Returns the largest depth of the tree
    int getDepth();

    
    Node* root;
    int order;
};

#endif