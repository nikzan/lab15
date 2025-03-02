#include "stack.h"
#include <iostream>

Stack::Stack() : top_(nullptr) {}

Stack::~Stack() {
  while (top_ != nullptr) {
    Node* temp = top_;
    top_ = top_->next;
    delete temp;
  }
}

void Stack::Push(int value) {
  Node* new_node = new Node;
  new_node->data = value;
  new_node->next = top_;
  top_ = new_node;
}

int Stack::Pop() {
  if (top_ == nullptr) {
    std::cout << "Стек пуст!" << std::endl;
    return -1;
  }
  int value = top_->data;
  Node* temp = top_;
  top_ = top_->next;
  delete temp;
  return value;
}

void Stack::Print() {
  if (top_ == nullptr) {
    std::cout << "Стек пуст!" << std::endl;
    return;
  }
  Node* current = top_;
  std::cout << "Содержимое стека: ";
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

Node* Stack::GetTop() {
  return top_;
}