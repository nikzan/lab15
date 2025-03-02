#include "queue.h"
#include <iostream>

Queue::Queue() : head_(nullptr), tail_(nullptr) {}

Queue::~Queue() {
  while (head_ != nullptr) {
    Node* temp = head_;
    head_ = head_->next;
    delete temp;
  }
  tail_ = nullptr;
}

void Queue::Enqueue(int value) {
  Node* new_node = new Node;
  new_node->data = value;
  new_node->next = nullptr;

  if (tail_ == nullptr) {
    head_ = new_node;
    tail_ = new_node;
  } else {
    tail_->next = new_node;
    tail_ = new_node;
  }
}

int Queue::Dequeue() {
  if (head_ == nullptr) {
    std::cout << "Очередь пуста!" << std::endl;
    return -1;
  }
  int value = head_->data;
  Node* temp = head_;
  head_ = head_->next;
  if (head_ == nullptr) {
    tail_ = nullptr;
  }
  delete temp;
  return value;
}

void Queue::Print() {
  if (head_ == nullptr) {
    std::cout << "Очередь пуста!" << std::endl;
    return;
  }
  Node* current = head_;
  std::cout << "Содержимое очереди: ";
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

Node* Queue::GetHead() {
  return head_;
}

Node* Queue::GetTail() {
  return tail_;
}

void Queue::SetHead(Node* new_head) {
  head_ = new_head;
}

void Queue::SetTail(Node* new_tail) {
  tail_ = new_tail;
}