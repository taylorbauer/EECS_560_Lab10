//
//  Author: Taylor Bauer
//  Date:   11.10.2019
//          EECS 560
//          Lab 09
//

#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(MinSkewHeap heap) {
    h = heap;
}

void Menu::run() {
    cin.clear();
    int selection = 0;
    cout << "\nWelcome!\n";
    while (selection < 9 && selection >= 0) {
        cout << "\nPlease choose one of the following commands:\n"
            << "1. Insert\n"
            << "2. Merge\n"
            << "3. Delete\n"
            << "4. Find\n"
            << "5. Preorder\n"
            << "6. Inorder\n"
            << "7. Postorder\n"
            << "8. Levelorder\n"
            << "9. Exit\n"
            << "Your selection: ";
        cin >> selection;
        if (selection == 1) {
            cout << "What value would you like to insert (positive, unique integers only please): ";
            int insertion = 0;
            cin >> insertion;
            if (h.find(insertion, h.getRoot())) {
                cout << "Unable to insert " << insertion << ". It is already in the heap.\n"
                << "Please insert a unique number.\n";
            }
            else {
                h.insert(insertion);
                cout << "Successfully inserted " << insertion << " into the heap!\n";
            }
        }
        else if (selection == 2) {
            cout << "\nEnter first value of your new heap (positive, unique integers only please): ";
            int first = 0;
            cin >> first;
            MinSkewHeap H2;
            H2.insert(first);
            cout << "Enter second value of your new heap: ";
            int second = 0;
            cin >> second;
            H2.insert(second);
            cout << "Enter the third value of your new heap: ";
            int third = 0;
            cin >> third;
            H2.insert(third);
            cout << "Merging the old heap with your new heap...\n";
            h.root = h.merge(h.getRoot(), H2.getRoot());
            cout << "Successfully merged the two heaps!\n";
        }
        else if (selection == 3) {
            cout << "What value would you like to remove? ";
            int removal = 0;
            cin >> removal;
            if (h.remove(removal)) {
                cout << "Succdessfully removed " << removal << " from the heap!\n";
            }
            else {
                cout << "Unable to find " << removal << ", please make sure it is in the heap.\n";
            }
        }
        else if (selection == 4) {
            cout << "What value would you like to search for? ";
            int searchKey = 0;
            cin >> searchKey;
            if (h.find(searchKey, h.root)) {
                cout << "The value " << searchKey << " was found in the heap!\n";
            }
            else {
                cout << "Unable to find " << searchKey << " in the heap.\n";
            }
        }
        else if (selection == 5) {
           cout << "Printing in pre-order: \n";
           h.preOrder(h.getRoot());
        }
        else if (selection == 6) {
            cout << "Printing in in-order: \n";
            h.inOrder(h.getRoot());
        }
        else if (selection == 7) {
            cout << "Printing in post-order: \n";
            h.postOrder(h.getRoot());
        }
        else if (selection == 8) {
            cout << "Printing in level order: \n";
            h.levelOrder();
        }
        else {
            cout << "\n\n~~Goodbye~~\n\n";
        }
    }
}
