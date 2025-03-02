#ifndef STACK_H_
#define STACK_H_

#include "node.h"

class Stack {
 public:
  Stack();
  ~Stack();

  void Push(int value);
  int Pop();
  void Print();
  Node* GetTop();

 private:
  Node* top_;
};

#endif  // STACK_H_