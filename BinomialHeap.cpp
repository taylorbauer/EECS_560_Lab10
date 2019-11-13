#include "BinomialHeap.h"
#include "BinomialTree.h"

BinomialHeap::BinomialHeap() {
    size = 0;
}

void BinomialHeap::print() {
    for (int i = 0; i < 50; i ++) {     // For each tree in the heap
        if (arr[i].order != -1) {       // If the heap is not empty 
            arr[i].print(arr[i].getDepth(), arr[i].root);
        }
    }
}

void BinomialHeap::insert(int value) {
    BinomialTree newTree(value);
    mergeUp(0, newTree);
}

void BinomialHeap::mergeUp(int index, BinomialTree tree) {
    if (arr[index].order == -1) {
        arr[index] = tree;
        return;
    }
    else {
        if (arr[index].root->key > tree.root->key) {        // Swap if key of H1 is greater than that of H2
            BinomialTree tempTree = arr[index];
            arr[index] = tree;
            tree = tempTree;
        }
        tree.root->rightSib = arr[index].root->firstChild;  // Merge the two trees
        arr[index].root->firstChild = tree.root;
        tree.order = tree.order + 1;                         // Increment the order

        tree = arr[index];                                   // Copy newly merge tree to call in recursion

        BinomialTree emptyTree;                             // Make an empty binomial tree to store in our array of trees
        arr[index] = emptyTree;                             // Erase the old tree

        mergeUp(index + 1, tree);                           // Keep on merging up
        return;
    }
}