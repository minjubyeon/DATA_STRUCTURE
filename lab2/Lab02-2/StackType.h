//
//  StackType.h
//  Lab02
//
//  Modified by Jeman Park on 2026/03/31.
//


#ifndef STACKTYPE_H
#define STACKTYPE_H

#include <iostream>

#define MAX_ITEMS 50

typedef int ItemType;

class StackType
{
public:
    StackType();
    void push(ItemType item);
    ItemType pop();

    bool size() const;
    bool isFull() const;
    bool isEmpty() const;
    
    void printStack();
    
private:
    int top;
    ItemType data[MAX_ITEMS];
};



#endif /* STACKTYPE_H */
