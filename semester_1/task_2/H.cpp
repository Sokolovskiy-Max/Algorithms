//#include <iostream>
//
//struct Node {
//  Node* prev = nullptr;
//  char key;
//};
//
//struct Stack {
//  Node* last = nullptr;
//  int64_t size = 0;
//
//  void Push(char num) {
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
//  char Peek() {
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
//  char a = ' ';
//  auto stack = new Stack();
//  int check = 0;
//  while (a != '\n') {
//    a = getchar();
//    if (a == '(' || a == '[' || a == '{') {
//      stack->Push(a);
//    } else if (a == ')') {
//      if (stack->Peek() == '(') {
//        stack->Pop();
//      } else {
//        check = -1;
//        break;
//      }
//    } else if (a == ']') {
//      if (stack->Peek() == '[') {
//        stack->Pop();
//      } else {
//        check = -1;
//        break;
//      }
//    } else if (a == '}') {
//      if (stack->Peek() == '{') {
//        stack->Pop();
//      } else {
//        check = -1;
//        break;
//      }
//    }
//  }
//  if (stack->Size() == 0 && check == 0) {
//    std::cout << "YES";
//  } else {
//    std::cout << "NO";
//  }
//  stack->Clear();
//  delete stack;
//  return 0;
//}