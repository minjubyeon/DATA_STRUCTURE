#include <iostream>

#include "SortedType.h"

SortedType::SortedType() { length = 0; }

bool SortedType::isFull() {
  if (length >= MAX_SIZE)
    return true;
  else
    return false;
}

bool SortedType::isEmpty() {
  if (length == 0)
    return true;
  else
    return false;
}

// insertItem 연습
void SortedType::insertItem(ItemType value) {
  if (isFull()) return;
  if (isEmpty()) {
    data[0] = value;
    return;
  }

  int i = 0;
  while (i < length) {
    if (data[i] < value)
      i++;

    else if (data[i] >= value) {
      for (int j = length; j > i; j--) {
        data[j] = data[j - 1];
      }
      data[i] = value;
    }
  }
  
  length++;
}

// removeItem 연습
// void removeItem(ItemType value);

// updateItem 연습
//  void updateItem(ItemType old_value, ItemType new_value);

void SortedType::clear() { length = 0; }

int SortedType::size() { return length; }

// bool findItem(ItemType item);

ItemType SortedType::getItem(int pos) {
  if (pos >= length) throw std::runtime_error("List is empty");
  return data[pos];
}