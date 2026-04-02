#include <iostream>

#include "SortedType.h"
#include "UnsortedType.h"

UnsortedType::UnsortedType() { length = 0; }

// 1. appendItem
void UnsortedType::appendItem(ItemType value) {
  if (isFull) {
    return;
  }

  data[length] = value;
}

//***********************************************************************************
// 2. void insertItem(int pos, ItemType value);

void UnsortedType::insertItem(int pos, ItemType value) {
  if (pos > MAX_SIZE - 1) {
    return;
  }

  data[length] = data[pos];
  data[pos] = value;
  length++;
}

void UnsortedType::insertItem(int pos, ItemType value) {
  if (pos > MAX_SIZE - 1) {
    return;
  }

  length++;

  for (int i = 1; (length-1) < pos; i++) {
    data[length - i] = data[length];
    if ((length - i) == pos) break;
  }

  data[pos] = value;
}

//***********************************************************************************
// 3. void removeItem(ItemType value);
void UnsortedType::removeItem(ItemType value){
    for (int i = 0; i < length; i++){
        if (data[i] == value){
            data[i] = data[length-1];
            length--;
            break;
        }
    }

}


//***********************************************************************************
// 4. void updateItem(int pos, ItemType new_value);
void UnsortedType::updateItem(int pos, ItemType new_value){

    if (pos >= length) return;
    data[pos] = new_value;

}


//***********************************************************************************
// 5. void clear();
void UnsortedType::clear(){
    length = 0;
}

//***********************************************************************************
// 6.int size();
int UnsortedType::size() { return length; }

//***********************************************************************************
// 7. bool isFull();
bool UnsortedType::isFull() {
  if (length == MAX_SIZE)
    return true;

  else
    return false;
}

//***********************************************************************************
// 8. bool isEmpty();
bool UnsortedType::isEmpty() {
  if (length == 0)
    return true;

  else
    return false;
}

//***********************************************************************************
// 9. bool findItem(ItemType item);
bool UnsortedType::findItem(ItemType item) {
  for (int i = 0; i < length; i++) {
    if (data[i] == item) return true;
  }
  return false;
}

//***********************************************************************************
// 10. ItemType getItem(int pos);

ItemType UnsortedType::getItem(int pos){
    if (pos >= length) return;
    return data[pos];
}

//***********************************************************************************
//SortedType
//1. insertItem(ItemType value);

//***********************************************************************************
//2. void removeItem(ItemType value);

//***********************************************************************************
//3. void updateItem(ItemType old_value, ItemType new_value);

//***********************************************************************************
//4. void clear();

//***********************************************************************************
//5. bool findItem(ItemType item);

//***********************************************************************************
//6. ItemType getItem(int pos);