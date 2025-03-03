#include <iostream>
#include <locale>
#include "stack.h"
#include "queue.h"
#include "linked_list.h"

void Task1() {
  std::cout << "\n--------------------\n";
  Stack stack;
  int n, value;

  std::cout << "Введите количество элементов стека: ";
  std::cin >> n;

  std::cout << "Введите " << n << " элементов стека:\n";
  for (int i = 0; i < n; i++) {
    std::cin >> value;
    stack.Push(value);
  }

  stack.Print();

  std::cout << "Введите значение D для добавления в стек: ";
  std::cin >> value;

  stack.Push(value);
  void* p2 = stack.GetTop();

  stack.Print();
  std::cout << "Адрес P2 (новая вершина стека): " << p2 << std::endl;
}

void Task2() {
  std::cout << "\n--------------------\n";
  Queue queue1, queue2;
  int n, value;

  std::cout << "Введите количество элементов для каждой очереди: ";
  std::cin >> n;

  std::cout << "Введите " << n << " элементов первой очереди:\n";
  for (int i = 0; i < n; i++) {
    std::cin >> value;
    queue1.Enqueue(value);
  }

  std::cout << "Введите " << n << " элементов второй очереди:\n";
  for (int i = 0; i < n; i++) {
    std::cin >> value;
    queue2.Enqueue(value);
  }

  queue1.Print();
  queue2.Print();

  Queue result_queue;
  Node* current1 = queue1.GetHead();
  Node* current2 = queue2.GetHead();

  if (current1) {
    result_queue.SetHead(current1);
    result_queue.SetTail(current1);
    current1 = current1->next;
  }

  while (current1 || current2) {
    if (current2) {
      result_queue.GetTail()->next = current2;
      result_queue.SetTail(current2);
      current2 = current2->next;
    }

    if (current1) {
      result_queue.GetTail()->next = current1;
      result_queue.SetTail(current1);
      current1 = current1->next;
    }
  }

  if (result_queue.GetTail()) {
    result_queue.GetTail()->next = nullptr;
  }

  queue1.SetHead(nullptr);
  queue1.SetTail(nullptr);
  queue2.SetHead(nullptr);
  queue2.SetTail(nullptr);

  result_queue.Print();
  std::cout << "Адрес начала новой очереди: " << result_queue.GetHead() << std::endl;
  std::cout << "Адрес конца новой очереди: " << result_queue.GetTail() << std::endl;
}

void Task3() {
  std::cout << "\n--------------------=\n";
  LinkedList list;
  int n, value;

  std::cout << "Введите количество элементов списка (не менее 2): ";
  std::cin >> n;

  if (n < 2) {
    std::cout << "Количество элементов должно быть не менее 2!" << std::endl;
    return;
  }

  std::cout << "Введите " << n << " элементов списка:\n";
  for (int i = 0; i < n; i++) {
    std::cin >> value;
    list.AddLast(value);
  }

  list.Print();

  void* p2 = list.GetSecond();

  std::cout << "Адрес P2 (второй элемент списка): " << p2 << std::endl;
}

void Task4() {
  std::cout << "\n--------------------\n";
  LinkedList list;
  int n, value, m;

  std::cout << "Введите количество элементов списка: ";
  std::cin >> n;

  std::cout << "Введите " << n << " элементов списка:\n";
  for (int i = 0; i < n; i++) {
    std::cin >> value;
    list.AddLast(value);
  }

  list.Print();

  std::cout << "Введите значение M для вставки после каждого второго элемента: ";
  std::cin >> m;

  void* p2 = list.InsertAfterEverySecond(m);

  list.Print();
  std::cout << "Адрес P2 (последний элемент полученного списка): " << p2 << std::endl;
}

void Task5() {
  std::cout << "\n--------------------\n";
  LinkedList list;
  int n, value, m, k;

  std::cout << "Введите количество элементов списка: ";
  std::cin >> n;

  std::cout << "Введите " << n << " элементов списка:\n";
  for (int i = 0; i < n; i++) {
    std::cin >> value;
    list.AddLast(value);
  }

  list.Print();

  std::cout << "Введите значение M для вставки: ";
  std::cin >> m;

  std::cout << "Введите значение K (после каждого K-го элемента): ";
  std::cin >> k;

  void* p2 = list.InsertAfterEveryKth(m, k);

  list.Print();
  std::cout << "Адрес P2 (последний элемент полученного списка): " << p2 << std::endl;
}

int main() {
  std::setlocale(LC_ALL, "ru_RU.UTF-8");
  int choice;
  bool exit_program = false;

  do {
    std::cout << "\--------------------\n";
    std::cout << "1. Task1\n";
    std::cout << "2. Task2\n";
    std::cout << "3. Task3\n";
    std::cout << "4. Task4\n";
    std::cout << "5. Task5\n";
    std::cout << "0. Выход\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        Task1();
        break;
      case 2:
        Task2();
        break;
      case 3:
        Task3();
        break;
      case 4:
        Task4();
        break;
      case 5:
        Task5();
        break;
      case 0:
        exit_program = true;
        break;
      default:
        std::cout << "Неверный выбор. Попробуйте снова.\n";
    }
  } while (!exit_program);

  return 0;
}
