//
//  Author: Taylor Bauer
//  Date:   11.10.2019
//          EECS 560
//          Lab 09
//

#ifndef NODE_H
#define NODE_H

class Node {
public:

    //  Creates a node with the passed value as its key
    Node(int value);

    //  Calculates (recursively) the rank of the node
    int getRank();

    //  The stored key (or value)
    int key;

    //  The rank of the node
    int rank;

    //  A pointer to each child
    Node* leftChild;
    Node* rightChild; 

    //  Returns the number of children that the node has
    int childrenCount();
};

#endif