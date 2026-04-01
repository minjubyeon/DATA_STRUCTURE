//
//  Lab01_3.cpp
//  Lab01
//
//  Modified by Jeman Park on 2026/03/23.
//

#include <iostream>
#include "UnsortedType.h"

using namespace std;

int main() {
    UnsortedType uList;
    
    /* Feel free to edit codes below (test with various cases) */

    uList.appendItem(4);
    uList.appendItem(3);
    uList.appendItem(2);
    uList.appendItem(7);
    uList.PrintList();
    // [ 4 3 2 7 ]
    
    uList.insertItem(1, 15);
    uList.PrintList();
    // [ 4 15 2 7 3 ]

    uList.removeItem(3);
    uList.PrintList();
    // [ 4 15 2 7 ]
   
    uList.updateItem(1, 5);
    uList.PrintList();
    // [ 4 5 2 7 ]
    
    uList.insertItem(3, 11);
    uList.PrintList();
    // [ 4 5 2 11 7 ]
    
    uList.clear();
    uList.PrintList();
    // [ EMPTY LIST ]

    // You don't have to do anything with the codes above (just for reference)
    
    uList.appendItem(4);
    uList.appendItem(3);
    uList.appendItem(14);
    uList.appendItem(12);
    uList.appendItem(11);
    uList.appendItem(7);
    uList.appendItem(24);
    uList.appendItem(6);
    uList.appendItem(1);
    uList.PrintList();
    // [4 3 14 12 11 7 24 6 1 ]
    
    
    //uList.swapItems(0, 8);
    uList.PrintList();
    // [1 3 14 12 11 7 24 6 4 ]
    
    int ret = 0;
    ret = uList.removeLargestItem();
    cout << ret << endl;
    // 24
    uList.PrintList();
    // [1 3 14 12 11 7 4 6 ]
    // OR
    // [1 3 14 12 11 7 6 4 ]
    
    
    return 0;
}
