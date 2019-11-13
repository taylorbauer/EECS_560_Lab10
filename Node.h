#ifndef NODE_H
#define NODE_H

class Node {
    public:
    Node(int key);

    int key;
    Node* leftSib;
    Node* rightSib;
    Node* firstChild;
};

#endif