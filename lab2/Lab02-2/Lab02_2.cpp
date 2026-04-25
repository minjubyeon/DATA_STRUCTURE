//
//  Lab02_2.cpp
//  Lab02
//
//  Modified by Jeman Park on 2026/03/31.
//

#include <iostream>
#include "reversingOrder.h"


using namespace std;

int main() {
    
    SortedType<int> s_list;
    
    s_list.insertItem(15);
    s_list.insertItem(7);
    s_list.insertItem(20);
    s_list.PrintList();
    // Correct Output:
    //    [7 15 20 ]
    
    int length = s_list.size();
    
    int* reversed = reversingOrder(s_list);
    cout << "[";
    for(int i=0; i<length; i++){
        cout << reversed[i] << "\t";
    }
    cout << "]";
    cout << endl;
    // Correct Output:
    //    [20    15    7    ]

    s_list.clear();
    s_list.PrintList();
    // Correct Output:
    //    [EMPTY LIST]
 
    delete[] reversed;
    
    
    
    length = s_list.size();
    int* empty_reversed = reversingOrder(s_list);
    cout << "[";
    for(int i=0; i<length; i++){
        cout << empty_reversed[i] << "\t";
    }
    cout << "]";
    cout << endl;
    
    // Correct Output:
    //    []
    
    delete[] empty_reversed;
    
    
    return 0;
}
