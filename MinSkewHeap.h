//
//  Author: Taylor Bauer
//  Date:   11.10.2019
//          EECS 560
//          Lab 09
//

#ifndef MIN_Skew_HEAP
#define MIN_Skew_HEAP
#include "Node.h"

class MinSkewHeap {
public:

    //  Default constructor, creates an empty heap
    MinSkewHeap();

    ~MinSkewHeap();

    //  Creates a new node with passed value as its key, merges it with the rest of the heap
    Node* insert (int value);

    //  Deletes the root and merges its children (if applicable)
    Node* deleteMin();

    bool remove(int value);

    //  Returns the root, used for merging
    Node* getRoot();

    //  Prints the heap in level order (this is a helper function that calls a recursive function)
    void levelOrder();

    //  Prints the heap in pre-order
    void preOrder(Node* node);

    //  Prints the heap in in-order
    void inOrder(Node* node);

    //  Prints the heap in post-order
    void postOrder(Node* node);

    //  Returns the height of the node (this should be true height, not just down the left)
    int getHeight(Node* node);

    //  Merges H1 and H2.  Ususally, H1 is the root of this object
    Node* merge(Node* H1, Node* H2);

    //  Searches for the value starting from node as root, returns true if it is found on the heap, false otherwise
    bool find(int value, Node* node);

    //  A pointer to the root.  This needs to be public for certain menu function calls to work
    Node* root;
private:

    //  The recursive function that prints the heap in level order
    void levelOrder(Node* node, int level);

    //  Finds the parent of the node that contains the passed value
    //  This is a helper function of remove()
    Node* findParentOfKey(Node* node, int value);
};

#endif