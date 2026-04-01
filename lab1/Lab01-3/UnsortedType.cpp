//
//  UnsortedType.cpp
//  Lab01
//
//  Modified by Jeman Park on 2026/03/23.
//

#include "UnsortedType.h"

#include <iostream>

using namespace std;

UnsortedType::UnsortedType() { length = 0; }

int UnsortedType::size() { return length; }

bool UnsortedType::isFull() { return (length == MAX_ITEMS); }

bool UnsortedType::isEmpty() { return (length == 0); }

void UnsortedType::appendItem(ItemType value) {
  if (isFull()) {
    cout << "[ERROR] List is FULL" << endl;
    return;
  }

  data[length] = value;
  length++;
}

void UnsortedType::insertItem(int pos, ItemType value) {
  if (isFull()) {
    cout << "[ERROR] List is FULL" << endl;
    return;
  }

  if (pos > length) {
    cout << "[ERROR] Invalid Position (pos > length)" << endl;
    return;
  }

  data[length] = data[pos];
  data[pos] = value;
  length++;
}

void UnsortedType::removeItem(ItemType value) {
  if (isEmpty()) {
    cout << "[ERROR] List is EMPTY" << endl;
    return;
  }
  for (int i = 0; i < length; i++) {
    if (data[i] == value) {
      data[i] = data[length - 1];
      length--;
      break;
    }
  }
}

void UnsortedType::swapItems(int firstItemIndex, int secondItemIndex) {
  /* Implement the function here (Lab 01-3) */
  // This function swaps data[firstIndex] and data[secondItemIndex]
  // Pay attention to exception handling
  // Time Complexity: O(   )




  
}

int UnsortedType::removeLargestItem() {
  int max = -9999;
  /* Implement the function here (Lab 01-3) */
  // This function removes and returns the largest item in the list
  // Pay attention to exception handling
  // Time Complexity: O(   )

  int max_index = 0;

  if (isEmpty()) throw std::runtime_error("List is empty");

  for (int i = 0; i < length; i++) {
    if (data[i] > max) {
      max = data[i];
      max_index = i;
    }
  }

  // removeItem 없이 직접 구현
  for (int i = max_index; i < length - 1; i++) {
    data[i] = data[i + 1];
  }
  length--;
  return max;
}

void UnsortedType::updateItem(int pos, ItemType new_value) {
  if (pos >= length) {
    cout << "[ERROR] Invalid Position (pos >= length)" << endl;
    return;
  }

  data[pos] = new_value;
}

void UnsortedType::clear() { length = 0; }

ItemType UnsortedType::getItem(int pos) {
  if (pos >= length) {
    cout << "[ERROR] Invalid Position (pos >= length)" << endl;
    return -1;
  }

  return data[pos];
}

bool UnsortedType::findItem(ItemType item) {
  int location = 0;

  while (location < length) {
    if (data[location] == item) {
      return true;
    }
    location++;
  }
  return false;
}

void UnsortedType::PrintList() {
  if (length == 0) {
    cout << "[EMPTY LIST]" << endl;
    ;
    return;
  }
  cout << "[";
  for (int i = 0; i < length; i++) {
    cout << data[i] << " ";
  }
  cout << "]" << endl;
}
