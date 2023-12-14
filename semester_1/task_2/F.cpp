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
//    std::cout << "ok" << std::endl;
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
//    std::cout << "ok" << std::endl;
//  }
//
//  void PopFront() {
//    if (size == 0) {
//      std::cout << "error" << std::endl;
//      return;
//    }
//    std::cout << first->self << std::endl;
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
//    std::cout << last->self << std::endl;
//    Node* del = last;
//    last = last->next;
//    delete del;
//    --size;
//  }
//  void Front() {
//    if (size == 0) {
//      std::cout << "error" << std::endl;
//      return;
//    }
//    std::cout << first->self << std::endl;
//  }
//  void Back() {
//    if (size == 0) {
//      std::cout << "error" << std::endl;
//      return;
//    }
//    std::cout << last->self << std::endl;
//  }
//  void Size() {
//    std::cout << size << std::endl;
//  }
//  void Clear() {
//    while (size > 0) {
//      Node* del = last;
//      last = last->next;
//      delete del;
//      --size;
//    }
//    std::cout << "ok" << std::endl;
//  }
//  void Exit() {
//    while (size > 0) {
//      Node* del = last;
//      last = last->next;
//      delete del;
//      --size;
//    }
//    std::cout << "bye" << std::endl;
//  }
//};
//int main() {
//  int n;
//  std::cin >> n;
//  auto deque = new Deque;
//  for (int i = 0; i < n; ++i) {
//    auto* line = new char[100];
//    std::cin >> line;
//    if (strcmp(line, "push_front") == 0) {
//      int a;
//      std::cin >> a;
//      deque->PushFront(a);
//    }
//    if (strcmp(line, "push_back") == 0) {
//      int a;
//      std::cin >> a;
//      deque->PushBack(a);
//    }
//    if (strcmp(line, "pop_front") == 0) {
//      deque->PopFront();
//    }
//    if (strcmp(line, "pop_back") == 0) {
//      deque->PopBack();
//    }
//    if (strcmp(line, "front") == 0) {
//      deque->Front();
//    }
//    if (strcmp(line, "back") == 0) {
//      deque->Back();
//    }
//    if (strcmp(line, "size") == 0) {
//      deque->Size();
//    }
//    if (strcmp(line, "clear") == 0) {
//      deque->Clear();
//    }
//    if (std::strcmp(line, "exit") == 0) {
//      deque->Exit();
//      return 0;
//    }
//    delete[] line;
//  }
//  deque->Clear();
//  delete deque;
//  return 0;
//}