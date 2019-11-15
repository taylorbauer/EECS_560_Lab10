//
//  Author: Taylor Bauer
//  Date:   11.17.2019
//          EECS 560
//          Lab 10
//

#include "Node.h"

Node::Node(int value) {
    key = value;

    leftSib = nullptr;
    rightSib = nullptr;
    firstChild = nullptr;
}