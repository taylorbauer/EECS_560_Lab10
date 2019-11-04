//
//  Author: Taylor Bauer
//  Date:   11.10.2019
//          EECS 560
//          Lab 09
//

#include "Node.h"

Node::Node(int value) {
        key = value;
        leftChild = nullptr;
        rightChild = nullptr;
}

int Node::getRank() {
    if (leftChild == nullptr || rightChild == nullptr) {
        return 1;
    }
    else {
        int leftRank = leftChild->getRank();
        int rightRank = rightChild->getRank();
        if (leftRank < rightRank) {
            return leftRank + 1;
        }
        else {
            return rightRank+1;
        }

    }
}

int Node::childrenCount() {
    if (leftChild == nullptr && rightChild == nullptr) {
        return 0;
    }
    else if (leftChild == nullptr || rightChild == nullptr) {
        return 1;
    }
    else {
        return 2;
    }
}