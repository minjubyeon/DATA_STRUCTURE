#include <iostream>

#include "SortedType.h"
#include "UnsortedType.h"

UnsortedType::UnsortedType() { length = 0; }

// 1. appendItem
void UnsortedType::appendItem(ItemType value) {
  if (isFull()) {
    return;
  }

  length++;  // length를 먼저 증가시킵니다.
  data[length - 1] = value;
}

/* 강의자료에 소개 된 방식
void UnsortedType::appendItem(ItemType value) {
    if (isFull()) {
        return;
    }

    data[length] = value;
    length++;  // length를 나중에 증가시킵니다.
}
*/

// ################################################################
// 2. insertItem
void UnsortedType::insertItem(int pos, ItemType value) {
  if (pos >= length) {
    return;
  }

  for (int i = 1; (length - i) < (length - pos); i++) {
    data[length - i] = data[length - (i + 1)];
    if ((length - i) == pos) break;
  }

  data[pos] = value;
}

/*
void UnsortedType::insertItem(int pos, ItemType value) {
    // 1. 예외 처리: 위치가 범위를 벗어나거나 배열이 꽉 찬 경우
    if (pos < 0 || pos > length) {
        return;
    }

    // 2. 데이터 시프팅: 맨 뒤에서부터 pos까지 한 칸씩 뒤로 복사
    // 데이터 유실을 방지하기 위해 반드시 뒤에서부터 이동해야 합니다.
    for (int i = length; i > pos; i--) {
        data[i] = data[i - 1];
    }

    // 3. 목적지(pos)에 값 삽입 및 길이 증가
    data[pos] = value;
    length++;
}


void UnsortedType::insertItem(int pos, ItemType value) {
    if (isFull()) {
        return;
    }

    for (int i = length; i > pos; i--) {
        data[i] = data[i - 1];
    }

    data[pos] = value;
    length++;
}
    */

// ################################################################
// 3. removeItem

// ################################################################
// 4. updateItem
void UnsortedType::updateItem(int pos, ItemType new_value) {
  if (pos >= length) {
    return;
  }
  data[pos] == new_value;
}

// 5. clear
void UnsortedType::clear() { length == 0; }

// 6. size
int UnsortedType::size() { return length; }

// 7. isFull
bool UnsortedType::isFull() { return (length == MAX_SIZE); }

// 8. isEmpty
bool UnsortedType::isEmpty() {
  if (length == 0)
    return true;
  else
    return false;
}

// 9. findItem
bool UnsortedType::findItem(ItemType value) {
  for (int i = 0; i < length; i++) {
    if (data[i] == value) return true;
  }
  return false;
}

/*
bool UnsortedType::findItem(ItemType value) {
  // 1. 리스트 전체를 처음부터 끝까지 훑음
  for (int i = 0; i < length; i++) {
    // 2. 아이템을 찾으면 즉시 true를 반환하고 함수를 종료
    if (data[i] == value) {
      return true;
    }
  }
  // 3. 루프가 끝날 때까지 return되지 않았다면 리스트에 없는 것
  // else if (i >= length) 같은 조건문은 필요 없음
  return false;
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
*/

// ###############################################################
// 10. getItem
ItemType UnsortedType::getItem(int pos) {
  if (pos >= length) throw;
  return data[pos];
}

// ###############################################################
// SortedTypeB
// 1. void insertItem(ItemType value);
void SortedType::insertItem(ItemType value) {
  if (isFull()) return;

  for (int i = 0; i > length;) {
    if (data[i] < value)
      i++;
    else {
      for (int j = length; j > 0; j--) {
        data[length] = data[length - 1];
      }
    }
  }
}

// ###############################################################
// 2. void removeItem(ItemType value);

// ###############################################################
// 3. void updateItem(ItemType old_value, ItemType new_value);

// ###############################################################
// 4. void clear();

// ###############################################################
// 5. bool findItem(ItemType item);

// ###############################################################
// 6. ItemType getItem(int pos);