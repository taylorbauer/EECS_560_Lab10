#include "Node.h"

Node::Node(int value) {
    key = value;

    leftSib = nullptr;
    rightSib = nullptr;
    firstChild = nullptr;
}