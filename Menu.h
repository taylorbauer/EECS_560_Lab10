//
//  Author: Taylor Bauer
//  Date:   11.17.2019
//          EECS 560
//          Lab 10
//

#ifndef MENU_H
#define MENU_H
#include "BinomialHeap.h"


//  The class that handles all user interaction and manages the heap
class Menu {
public:

    // Constructor that requires a pre-existing heap
    Menu(BinomialHeap h);

    //  Run the menu.  This is where all user interaction takes place.
    void run();
private:
    BinomialHeap heap;

};

#endif