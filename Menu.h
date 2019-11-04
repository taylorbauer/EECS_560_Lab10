//
//  Author: Taylor Bauer
//  Date:   11.10.2019
//          EECS 560
//          Lab 09
//

#ifndef MENU_H
#define MENU_H
#include "MinSkewHeap.h"


//  The class that handles all user interaction and manages the heap
class Menu {
public:

    // Constructor that requires a pre-existing heap
    Menu(MinSkewHeap heap);

    //  Run the menu.  This is where all user interaction takes place.
    void run();
private:

    MinSkewHeap h;

};

#endif