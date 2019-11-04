//
//  Author: Taylor Bauer
//  Date:   11.10.2019
//          EECS 560
//          Lab 09
//

#include <iostream>
#include "MinSkewHeap.h"
using namespace std;

MinSkewHeap::MinSkewHeap() {
    root = nullptr;
}

MinSkewHeap::~MinSkewHeap() {
    while (root != nullptr) {
        deleteMin();
    }
}

Node* MinSkewHeap::merge(Node* H1, Node* H2) {
    if (H1 == nullptr) {
        return H2;
    }
    else if (H2 == nullptr) {
        return H1;
    }
    else if (H1->key > H2->key) {       // swap so the lesser is "on the left"
        Node* temp = H2;
        H2 = H1;
        H1 = temp;
    }

    H1->rightChild = merge(H1->rightChild, H2);     // this is where the "merging" happens


    // We no longer need to do check before we do these rotations because we are working in a skew heap, not a leftist heap
    Node* temp = H1->rightChild;
    H1->rightChild = H1->leftChild;
    H1->leftChild = temp;

    // if (H1->rightChild == nullptr) {
    //     // Do not rotate
    // }
    // else if (H1->leftChild == nullptr && H1->rightChild != nullptr) {
    //     Node* temp = H1->rightChild;
    //     H1->rightChild = H1->leftChild;
    //     H1->leftChild = temp;
    // }
    // else if (H1->leftChild->getRank() < H1->rightChild->getRank()) {         // this is what differentiates the Skew heap from a skew heap
    //      Node* temp = H1->rightChild;
    //      H1->rightChild = H1->leftChild;
    //      H1->leftChild = temp;
    // }

    return H1;
}

Node* MinSkewHeap::insert(int value) {
    Node* newNode = new Node(value);
    root = merge(root, newNode);
    return root;
}

Node* MinSkewHeap::deleteMin() {
    if (root == nullptr) {
        return nullptr;
    }
    
    Node* left = root->leftChild;
    Node* right = root->rightChild;
    delete root;
    root = merge(left, right);
    return root;
}

void MinSkewHeap::levelOrder() {
    int height = getHeight(root);
    for (int i = 0; i < height; i++) {
        levelOrder(root, i);
    }
}

void MinSkewHeap::levelOrder(Node* node, int level) {
    if (node == nullptr) {
        return;
    }
    else if (level == 0) {
            cout << node->key << ' ';
    }
    else {
        levelOrder(node->leftChild, level - 1);
        levelOrder(node->rightChild, level - 1);
    }
}

int MinSkewHeap::getHeight(Node* node) {
    int height = 0;
    while (node != nullptr) {
        height ++;
        if (getHeight(node->leftChild) > getHeight(node->rightChild)){
            node = node->leftChild;
        }
        else {
            node = node->rightChild;
        }
    }
    return height;
}

Node* MinSkewHeap::getRoot() {
    return root;
}

void MinSkewHeap::preOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->key << ' ';
    preOrder(node->leftChild);
    preOrder(node->rightChild);
    return;
}

void MinSkewHeap::inOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    inOrder(node->leftChild);
    cout << node->key << ' ';
    inOrder(node->rightChild);
    return;
}

void MinSkewHeap::postOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    postOrder(node->leftChild);
    postOrder(node->rightChild);
    cout << node->key << ' ';
    return;
}

bool MinSkewHeap::find(int value, Node* node) {
    if (node->key == value) {
        return true;
    }
    else if (node->childrenCount() == 2) {
        return (find(value, node->leftChild) || find(value, node->rightChild));
    }
    else if (node->childrenCount() == 0) {
        return false;
    }
    else {
        if (node->leftChild == nullptr) {
            return find(value, node->rightChild);
        }
        else {
            return find(value, node->leftChild);
        }
    }
}

bool MinSkewHeap::remove(int value) {
    if (!find(value, root)) {
        return false;
    }
    else if (root->key == value) {
        deleteMin();
        return true;
    }
    else {
        Node* parent = findParentOfKey(root, value);

        Node* toBeDeleted = nullptr;

        if (parent->leftChild->key == value) {
            toBeDeleted = parent->leftChild;
            parent->leftChild = nullptr;   
        }
        else {
            toBeDeleted = parent->rightChild;
            parent->rightChild = nullptr;
        }

        Node* leftChild = toBeDeleted->leftChild;
        Node* rightChild = toBeDeleted->rightChild;

        delete toBeDeleted;

        merge(root, leftChild);
        merge(root, rightChild);

        return true;
    }
}

Node* MinSkewHeap::findParentOfKey(Node* node, int value) {
    if (node->childrenCount() == 0) {
        return nullptr;
    }
    else if (node->childrenCount() == 2) {
        if (node->leftChild->key == value || node->rightChild->key == value) {
            return node;
        }    
        else {
            if (findParentOfKey(node->leftChild, value) != nullptr) {
                return (findParentOfKey(node->leftChild, value));
            }
            else if (findParentOfKey(node->rightChild, value) != nullptr) {
                return findParentOfKey(node->rightChild, value);
            }
        }
    }
    else {  //Node has 1 child
        if (node->rightChild == nullptr) {
            if (node->leftChild->key == value) {
                return node;
            }
            else {
                return findParentOfKey(node->leftChild, value);
            }
        }
        else {      
            if (node->rightChild->key == value) {
                return node;
            }
            else {
                return findParentOfKey(node->rightChild, value);
            }
        }
    }

    return nullptr;
}