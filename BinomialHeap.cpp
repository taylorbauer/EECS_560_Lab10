#include "BinomialHeap.h"
#include "BinomialTree.h"
#include <iostream>
using namespace std;

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
        arr[index].order = arr[index].order + 1;                         // Increment the order

        tree = arr[index];                                   // Copy newly merge tree to call in recursion

        BinomialTree emptyTree;                             // Make an empty binomial tree to store in our array of trees
        arr[index] = emptyTree;                             // Erase the old tree

        mergeUp(index + 1, tree);                           // Keep on merging up
        return;
    }
}

void BinomialHeap::deleteMin() {
    int minIndex = 0;
    int minKey = 100000;                            // hacky
    bool minFound = false;
    for (int i = 0; i < 50; i++) {
        if (arr[i].order != -1) {                   // As long as the tree isn't empty
            if (arr[i].root->key < minKey) {
                minFound = true;
                minKey = arr[i].root->key;
                minIndex = i;
            }
        }
    }
    if (!minFound) {
        return;
    }
    else { 
        int maxOrder = arr[minIndex].order;

        BinomialTree tempTree = arr[minIndex];
        BinomialTree emptyTree;
        arr[minIndex] = emptyTree;
        Node* sibling = nullptr;
        Node** array = new Node*[maxOrder];

        for (int i = 0; i < maxOrder; i++) { // Counting up to the order of the deleted tree, so from B0 to BK
            sibling = tempTree.root->firstChild;
            cout << "\ni = " << i << endl;
            for (int j = 0; j < i; j ++) {
                sibling = sibling->rightSib;
            }
            cout << "root of tree to be inserted is " << sibling->key << endl;

            BinomialTree toBeMerged(sibling);
            array[i] = toBeMerged.root;
            // mergeUp(i, toBeMerged);

        }

        for (int i = 0; i < maxOrder; i++) {
            cout << "Merging tree of root " << array[i]->key << " to index " << maxOrder - i - 1 << endl;
            mergeUp(maxOrder - i - 1, array[i]);
        }

        delete[] array;
    }

    return;
}