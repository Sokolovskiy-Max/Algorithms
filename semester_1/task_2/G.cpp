//#include <iostream>
//#include <iostream>
//#include <cstring>
//struct Node {
//  int self;
//  Node* next;
//  Node* prev;
//};
//
//struct Deque {
//  Node* first = nullptr;
//  Node* last = nullptr;
//  size_t size = 0;
//  void PushFront(int elem) {
//    auto* node = new Node;
//    node->self = elem;
//    if (size == 0) {
//      first = node;
//      last = node;
//      ++size;
//    } else {
//      first->next = node;
//      node->prev = first;
//      first = node;
//      ++size;
//    }
//  }
//
//  void PushBack(int elem) {
//    auto node = new Node;
//    node->self = elem;
//    if (size == 0) {
//      first = node;
//      last = node;
//      ++size;
//    } else {
//      last->prev = node;
//      node->next = last;
//      last = node;
//      ++size;
//    }
//  }
//
//  void PopFront() {
//    if (size == 0) {
//      std::cout << "error" << std::endl;
//      return;
//    }
//    Node* del = first;
//    first = first->prev;
//    delete del;
//    --size;
//  }
//  void PopBack() {
//    if (size == 0) {
//      std::cout << "error" << std::endl;
//      return;
//    }
//    Node* del = last;
//    last = last->next;
//    delete del;
//    --size;
//  }
//  int Front() {
//    if (size == 0) {
//      std::cout << "error" << std::endl;
//      return -1;
//    }
//    return first->self;
//  }
//  void Clear() {
//    while (size > 0) {
//      Node* del = last;
//      last = last->next;
//      delete del;
//      --size;
//    }
//  }
//};
//
//int main() /*{
 /* auto deque1 = new Deque;
  auto deque2 = new Deque;
  for (int i = 0; i < 5; ++i) {
    int a;
    std::cin >> a;
    deque1->PushBack(a);
  }
  for (int i = 0; i < 5; ++i) {
    int a;
    std::cin >> a;
    deque2->PushBack(a);
  }
  int step = 0;
  while (deque1->size > 0 && deque2->size > 0 && step < 1000000) {
    int a = deque1->Front();
    int b = deque2->Front();
    if (a == 0 && b == 9) {
      deque1->PushBack(a);
      deque1->PushBack(b);
      deque2->PopFront();
    } else {
      if (a == 9 && b == 0) {
        deque2->PushBack(a);
        deque2->PushBack(b);
        deque1->PopFront();
      } else {
        if (a > b) {
          deque1->PushBack(a);
          deque1->PushBack(b);
          deque2->PopFront();
        } else {
          if (b > a) {
            deque2->PushBack(a);
            deque2->PushBack(b);
            deque1->PopFront();
          }
        }
      }
    }
    ++step;
  }
  if (step >= 1000000) {
    std::cout << "botva";
  } else {
    if (deque1->size == 0) {
      std::cout << "second " << step;
    } else {
      std::cout << "first " << step;
    }
  }
  deque1->Clear();
  deque2->Clear();
  delete deque1;
  delete deque2;
  return 0;
}*/