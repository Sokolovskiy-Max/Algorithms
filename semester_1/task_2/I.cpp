//#include <iostream>
//
//struct Node {
//  Node* prev = nullptr;
//  int key;
//};
//
//struct Stack {
//  Node* last = nullptr;
//  int64_t size = 0;
//
//  void Push(int num) {
//    auto node = new Node;
//    node->prev = last;
//    node->key = num;
//    last = node;
//
//    ++size;
//  }
//
//  void Pop() {
//    if (size == 0) {
//      return;
//    }
//    Node* del = last;
//    last = last->prev;
//    delete del;
//    --size;
//  }
//
//  int Peek() {
//    if (size == 0) {
//      return 0;
//    }
//    return last->key;
//  }
//
//  int64_t Size() {
//    return size;
//  }
//
//  void Clear() {
//    if (size > 0) {
//      Pop();
//      Clear();
//    }
//    delete last;
//  }
//};
//
//int main() {
//  auto stack = new Stack;
//  char a = ' ';
//  for (int i = 0; a != '\n'; ++i) {
//    a = getchar();
//    if (a == ' ') {
//      continue;
//    }
//    if ((a - '0') > -1 && (a - '0') < 10) {
//      stack->Push(a - '0');
//    } else {
//      if (a == '+') {
//        int b = stack->Peek();
//        stack->Pop();
//        int c = stack->Peek();
//        stack->Pop();
//        stack->Push(b + c);
//      } else {
//        if (a == '*') {
//          int b = stack->Peek();
//          stack->Pop();
//          int c = stack->Peek();
//          stack->Pop();
//          stack->Push(b * c);
//        } else {
//          if (a == '-') {
//            int b = stack->Peek();
//            stack->Pop();
//            int c = stack->Peek();
//            stack->Pop();
//            stack->Push(c - b);
//          } 
//        }
//      } 
//    }
//  }
//
//  std::cout << stack->Peek();
//  stack->Clear();
//  delete stack;
//  return 0;
//}