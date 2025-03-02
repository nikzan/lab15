#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "node.h"

class LinkedList {
 public:
  LinkedList();
  ~LinkedList();

  void AddFirst(int value);
  void AddLast(int value);
  void Print();
  void RemoveFirst();
  void RemoveLast();
  bool RemoveAt(int position);
  Node* GetHead();
  Node* GetSecond();
  Node* InsertAfterEverySecond(int value);
  Node* InsertAfterEveryKth(int value, int k);

 private:
  Node* head_;
};

#endif  // LINKED_LIST_H_