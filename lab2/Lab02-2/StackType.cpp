//
//  StackType.cpp
//  Lab02
//
//  Modified by Jeman Park on 2026/03/31.
//


#include "StackType.h"


StackType::StackType()
{
    top = -1;
}

bool StackType::size() const
{
    return (top + 1);
}


bool StackType::isEmpty() const
{
    return (top == -1);
}

bool StackType::isFull() const
{
    return (top ==  MAX_ITEMS - 1);
}

void StackType::push(ItemType newItem)
{
    if(isFull()){
        return;
    }
        
    top++;
    data[top] = newItem;
}

ItemType StackType::pop()
{
    if( isEmpty() ){
        return -1;
    }
    
    ItemType result = data[top];
    top--;
    
    return result;
}

void StackType::printStack(){
    std::cout << "[ ";
    for(int i = 0; i <= top; i++){
        std::cout << data[i] << "\t";
    }
    std::cout << " (top) " << std::endl;
}

