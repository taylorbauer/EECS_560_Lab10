//
//  Author: Taylor Bauer
//  Date:   11.17.2019
//          EECS 560
//          Lab 10
//

#ifndef NODE_H
#define NODE_H


//  This class is just a struct used by BinaryTree.h
class Node {
    public:
    Node(int key);

    int key;
    Node* leftSib;
    Node* rightSib;
    Node* firstChild;
};

#endif