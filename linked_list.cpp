#include "linked_list.h"
#include <iostream>

LinkedList::LinkedList() : head_(nullptr) {}

LinkedList::~LinkedList() {
  while (head_ != nullptr) {
    Node* temp = head_;
    head_ = head_->next;
    delete temp;
  }
}

void LinkedList::AddFirst(int value) {
  Node* new_node = new Node;
  new_node->data = value;
  new_node->next = head_;
  head_ = new_node;
}

void LinkedList::AddLast(int value) {
  Node* new_node = new Node;
  new_node->data = value;
  new_node->next = nullptr;

  if (head_ == nullptr) {
    head_ = new_node;
    return;
  }

  Node* current = head_;
  while (current->next != nullptr) {
    current = current->next;
  }

  current->next = new_node;
}

void LinkedList::Print() {
  if (head_ == nullptr) {
    std::cout << "Список пуст!" << std::endl;
    return;
  }
  Node* current = head_;
  std::cout << "Содержимое списка: ";
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

Node* LinkedList::GetHead() {
  return head_;
}

Node* LinkedList::GetSecond() {
  if (head_ == nullptr || head_->next == nullptr) {
    std::cout << "В списке меньше двух элементов!" << std::endl;
    return nullptr;
  }
  return head_->next;
}

Node* LinkedList::InsertAfterEverySecond(int value) {
  if (head_ == nullptr) {
    std::cout << "Список пуст!" << std::endl;
    return nullptr;
  }

  Node* current = head_;
  int counter = 0;

  while (current != nullptr) {
    counter++;
    if (counter % 2 == 0) {
      Node* new_node = new Node;
      new_node->data = value;
      new_node->next = current->next;
      current->next = new_node;
      current = new_node;
    }
    if (current->next == nullptr) {
      break;
    }
    current = current->next;
  }

  return current;
}

Node* LinkedList::InsertAfterEveryKth(int value, int k) {
  if (head_ == nullptr) {
    std::cout << "Список пуст!" << std::endl;
    return nullptr;
  }

  if (k <= 0) {
    std::cout << "K должно быть положительным числом!" << std::endl;
    return nullptr;
  }

  Node* current = head_;
  int counter = 0;

  while (current != nullptr) {
    counter++;
    if (counter % k == 0) {
      Node* new_node = new Node;
      new_node->data = value;
      new_node->next = current->next;
      current->next = new_node;
      current = new_node;
    }
    if (current->next == nullptr) {
      break;
    }
    current = current->next;
  }

  return current;
}

void LinkedList::RemoveFirst() {
  if (head_ == nullptr) {
    std::cout << "Список пуст!" << std::endl;
    return;
  }

  Node* temp = head_;
  head_ = head_->next;
  delete temp;
}

void LinkedList::RemoveLast() {
  if (head_ == nullptr) {
    std::cout << "Список пуст!" << std::endl;
    return;
  }

  if (head_->next == nullptr) {
    delete head_;
    head_ = nullptr;
    return;
  }

  Node* current = head_;
  while (current->next->next != nullptr) {
    current = current->next;
  }

  delete current->next;
  current->next = nullptr;
}

bool LinkedList::RemoveAt(int position) {
  if (head_ == nullptr) {
    std::cout << "Список пуст!" << std::endl;
    return false;
  }

  if (position == 0) {
    RemoveFirst();
    return true;
  }

  Node* current = head_;
  int currentPos = 0;

  while (current != nullptr && currentPos < position - 1) {
    current = current->next;
    currentPos++;
  }

  if (current == nullptr || current->next == nullptr) {
    std::cout << "Позиция " << position << " не найдена в списке!" << std::endl;
    return false;
  }

  Node* temp = current->next;
  current->next = temp->next;
  delete temp;

  return true;
}