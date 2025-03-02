#ifndef QUEUE_H_
  #define QUEUE_H_

  #include "node.h"

  class Queue {
   public:
    Queue();
    ~Queue();

    void Enqueue(int value);
    int Dequeue();
    void Print();
    Node* GetHead();
    Node* GetTail();
    void SetHead(Node* new_head);
    void SetTail(Node* new_tail);

   private:
    Node* head_;
    Node* tail_;
  };

  #endif  // QUEUE_H_