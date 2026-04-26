//
//  QueueType.h
//  Lab04
//
//  Modified by Jeman Park on 2026/04/21.
//

#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include <iostream>
using namespace std;

template <class ItemType>
struct NodeType {
  ItemType value;
  NodeType* next;
};

template <class ItemType>
class QueueType {
 private:
  NodeType<ItemType>* pFront;
  NodeType<ItemType>* pRear;

 public:
  QueueType();
  ~QueueType();

  void clear();
  void enqueue(ItemType newItem);
  void dequeue(ItemType& value);

  int size() const;
  bool isFull() const;
  bool isEmpty() const;

  ItemType maxDequeue();

  void Print();
};

template <class ItemType>
QueueType<ItemType>::QueueType() {
  pFront = nullptr;
  pRear = nullptr;
}

template <class ItemType>
QueueType<ItemType>::~QueueType() {
  /* Implement the function here (Lab 04-2)*/
  // This destructor function iteratively deletes all nodes in the queue.
  // All "NodeType" should be "deallocated" properly.
  // It returns nothing

  while (!isEmpty()) {
    NodeType<ItemType>* tempPtr = pFront;
    pFront = pFront->next;
    delete tempPtr;
  }
}

template <class ItemType>
void QueueType<ItemType>::clear() {
  this->~QueueType();
}

template <class ItemType>
int QueueType<ItemType>::size() const {
  /* Implement the function here (Lab 04-2)*/
  // This function counts the number of nodes in the queue and returns it.

  int length = 0;
  NodeType<ItemType>* tempPtr = pFront;

  while (tempPtr != nullptr) {
    tempPtr = tempPtr->next;
    length++;
  }

  return length;
}

template <class ItemType>
bool QueueType<ItemType>::isEmpty() const {
  return (pFront == nullptr);
}

template <class ItemType>
bool QueueType<ItemType>::isFull() const {
  NodeType<ItemType>* newNode;
  try {
    newNode = new NodeType<ItemType>;
    delete newNode;
    return false;
  } catch (std::bad_alloc exception) {
    return true;
  }
}

template <class ItemType>
void QueueType<ItemType>::enqueue(ItemType newItem) {
  /* Implement the function here (Lab 04-2)*/
  // This function enqueues "newItem" into the queue, and returns NOTHING.
  // If the queue is already full, do nothing.

  if (isFull()) {
    return;
  }

  NodeType<ItemType>* newNode;
  newNode = new NodeType<ItemType>;

  newNode->value = newItem;
  newNode->next = nullptr;

  if (!isEmpty()) {
    pRear->next = newNode;
  } else {
    pFront = newNode;
  }
  pRear = newNode;
}

template <class ItemType>
void QueueType<ItemType>::dequeue(ItemType& ret_value) {
  /* Implement the function here (Lab 04-2)*/
  // This function dequeues the most front item in the queue, and returns it
  // through "RETURN BY REFERENCE (ret_value). You need to set "ret_value" as
  // the dequeue item's value to return. If the queue is empty, set "ret_value"
  // as -1

  if (isEmpty()) {
    ret_value = -1;
    return;
  }

  NodeType<ItemType>* tempPtr = pFront;
  ret_value = tempPtr->value;
  pFront = pFront->next;
  delete tempPtr;

  if (isEmpty()) {
    pRear = nullptr;
  }
}

template <class ItemType>
ItemType QueueType<ItemType>::maxDequeue() {
  /* Implement the function here (Lab 04-3)*/
  // This function removes and returns "the max value" in the queue
  // If the queue is empty, it returns -1 and does nothing

  if (isEmpty()) return -1;

 if (isEmpty()){
        return -1;
    }

    NodeType<ItemType>* maxPrev = nullptr;
    NodeType<ItemType>* maxNode = pFront;
    NodeType<ItemType>* prev = nullptr;
    NodeType<ItemType>* curr = pFront;

    while (curr != nullptr)
    {
        if (curr->value > maxNode->value)
        {
            maxPrev = prev;
            maxNode = curr;
        }
        prev = curr;
        curr = curr->next;
    }

    ItemType maxVal = maxNode->value;

    if (maxNode == pFront)
        pFront = maxNode->next;
    else
        maxPrev->next = maxNode->next;

    if (maxNode == pRear)
        pRear = maxPrev;

    delete maxNode;

    return maxVal;
}

template <class ItemType>
void QueueType<ItemType>::Print() {
  if (isEmpty()) {
    cout << "[EMPTY QUEUE]" << endl;
    return;
  }

  cout << "(front)\t[";
  NodeType<ItemType>* tempPtr = pFront;

  while (tempPtr != nullptr) {
    cout << tempPtr->value << "\t";
    tempPtr = tempPtr->next;
  }
  cout << "]\t(rear)" << endl;
}

#endif /* QUEUETYPE_H */
