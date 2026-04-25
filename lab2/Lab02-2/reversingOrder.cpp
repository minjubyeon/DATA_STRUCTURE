//
//  reversingOrder.cpp
//  Lab02
//
//  Modified by Jeman Park on 2026/03/31.
//

#include "reversingOrder.h"

int* reversingOrder(SortedType<int> original){
    /* Implement the function here (Lab 02-2) */
    // This functions returns the array in a reversed order
    // In this example, the function returns the descending-order array.
    // HINT: You can use STACK for this purpose
    
    int * reversed = new int[original.size()];
    StackType tempStack;
    
    // 1. 리스트 앞에서부터 스택에 push
    for (int i = 0; i < original.size(); i++) {
        tempStack.push(original.getItem(i));
    }
  
    // 2. 스택에서 pop해서 reversed 배열에 저장
    int i = 0;
    while (!tempStack.isEmpty()) {
        reversed[i++] = tempStack.pop();
    }
    
       
    return reversed;
}
