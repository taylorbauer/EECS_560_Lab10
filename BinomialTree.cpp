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

void BinomialTree::print(int depth, Node* root) {
    cout << root->key << endl;
    Node* temp = root->firstChild;
    for (int i = 1; i < depth; i++) {
        if (temp != nullptr) {
            cout << temp->key << ' ';
            Node* nextSibling = temp->rightSib;
            while (nextSibling != nullptr) {
                cout << nextSibling->key << ' ';
                nextSibling = nextSibling->rightSib;
            }
        }
        temp = temp->firstChild;
        cout << endl;
    }
    cout << "_______\n";
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