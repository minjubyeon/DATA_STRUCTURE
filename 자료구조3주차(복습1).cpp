#include <iostream>

#include "SortedType.h"
#include "UnsortedType.h"

UnsortedType::UnsortedType() { length = 0; }

int UnsortedType::size() { return length; }

bool UnsortedType::isFull() {
  if (length == MAX_SIZE)
    return true;

  else
    return false;
}

bool UnsortedType::isEmpty() {
  if (length == 0)
    return true;

  else
    return false;
}

bool UnsortedType::findItem(ItemType item){
    for (int i = 0 ; i < MAX_SIZE; i++){
        if (data[i] == item)
        return true;
    }
    return false;
}

