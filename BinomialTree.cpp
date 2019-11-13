#include "BinomialTree.h"
#include "Node.h"
#include <iostream>
using namespace std;

BinomialTree::BinomialTree() {
    root = nullptr;
    order = -1;
}

BinomialTree::BinomialTree(int value) {
    Node* r = new Node(value);
    root = r;
    order = 0;
}

void BinomialTree::print(int depth, Node* r) {
    for (int i = 0; i < depth; i++) {
        printLevel(r, i);
        cout << endl;
    }
    cout << "_______\n";
}

void BinomialTree::printLevel(Node* r, int level) {
    if (r == nullptr) {
        return;
    }
    if (level == 0) {
        cout << r->key << ' ';
    }
    else {
        Node* temp = r->firstChild;
        while (temp != nullptr) {
            printLevel(temp, level - 1);
            temp = temp->rightSib;
        }
        
    }
}

int BinomialTree::getDepth() {
    Node* temp = root;
    int depth = 0;
    while (temp != nullptr) {
        depth++;
        temp = temp->firstChild;
    }
    return depth;
}