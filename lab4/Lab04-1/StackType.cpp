//
//  StackType.cpp
//  Lab04
//
//  Modified by Jeman Park on 2026/04/21.
//

#include "StackType.h"

StackType::StackType() { topPtr = nullptr; }

StackType::~StackType() {
  /* Implement the function here */
  // This destructor function iteratively deletes all nodes in the stack.
  // All "NodeType" should be "deallocated" properly.
  // It returns nothing

  NodeType* tempPtr = topPtr;

  while (tempPtr != nullptr) {
    topPtr = topPtr->next;
    delete tempPtr;
    tempPtr = topPtr;
  }
}

void StackType::clear() { this->~StackType(); }

bool StackType::isEmpty() const { return (topPtr == nullptr); }

bool StackType::isFull() const {
  NodeType* newNode;
  try {
    newNode = new NodeType;
    delete newNode;
    return false;
  } catch (std::bad_alloc exception) {
    return true;
  }
}

int StackType::size() const {
  /* Implement the function here */
  // This function counts the number of nodes in the stack and returns it.

  NodeType* tempPtr = topPtr;
  int count = 0;
  while (tempPtr != nullptr) {
    count++;
    tempPtr = tempPtr->next;
  }
  return count;
}

void StackType::push(ItemType newItem) {
   if (isFull()) {
    return;
  }

  NodeType* newNode; //heap에 객체를 생성하고 그 주소를 포인터에 저장.
                     //topPtr이 가리킬 대상은 반드시 heap에 할당된 주소.
  newNode = new NodeType;

  newNode -> value = newItem;
  newNode -> next = topPtr;
  topPtr = newNode;
}

ItemType StackType::pop() {
  /* Implement the function here */
  // This function pops the item at the top of the stack, and returns it.
  // It should deallocate the popped node.
  // If the stack is EMPTY, it returns -1.

    if (isEmpty()) {
        return -1;
    }
    
    NodeType* tempPtr = topPtr;       // 현재 top 노드 주소 보관
    ItemType item = tempPtr->value;    // 반환할 값 저장
    topPtr = topPtr->next;            // top 포인터 이동
    delete tempPtr;                   // 노드 메모리 해제
    return item;                      // 값 반환
}

void StackType::Print() {
  if (isEmpty()) {
    cout << "[EMPTY STACK]" << endl;
    return;
  }

  cout << "(top)\t";
  NodeType* tempPtr = topPtr;

  while (tempPtr != nullptr) {
    cout << tempPtr->value << "\t";
    tempPtr = tempPtr->next;
  }

  cout << " ] " << endl;
}
