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

  int location = 0;
  while (location < length) {
    if (value > data[location])
      location++;
    else
      break;  // 삽입 위치 찾으면 즉시 탈출
  }
  // while과 분리된 for루프로 한번에 밀기
  for (int i = length; i > location; i--) data[i] = data[i - 1];

  data[location] = value;
  length++;
}

// removeItem 연습
void SortedType::removeItem(ItemType value) {
  if (isEmpty()) return;

  int location = 0;
  while (location < length) {
    if (value > data[location])
      location++;

    else if (value == data[location])
      break;

    else if (value < data[location])
      return;
  }

  if (location < length) {
    for (int i = location; (i + 1) < length; i++) {
      data[i] = data[i + 1];
    }
    length--;
  } 
  
  else if (location == length)
    return;
}

// updateItem 연습
//  void updateItem(ItemType old_value, ItemType new_value);

void SortedType::clear() { length = 0; }

int SortedType::size() { return length; }

// bool findItem(ItemType item);

ItemType SortedType::getItem(int pos) {
  if (pos >= length) throw std::runtime_error("List is empty");
  return data[pos];
}