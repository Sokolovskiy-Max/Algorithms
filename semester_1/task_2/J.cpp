//#include <iostream>
//#include <cstring>
//struct Node {
//  Node* prev = nullptr;
//  int key = 0;
//  int min = 0;
//};
//
//struct Stack {
//  Node* last = nullptr;
//  int64_t size = 0;
//
//  void Push(int num) {
//    auto new_node = new Node;
//    new_node->key = num;
//    new_node->prev = last;
//    if (size > 0) {
//      if (last->min < num) {
//        new_node->min = last->min;
//      } else {
//        new_node->min = num;
//      }
//    } else {
//      new_node->min = num;
//    }
//    last = new_node;
//    ++size;
//  }
//  int Back() {
//    if (size == 0) {
//      return 0;
//    }
//    return last->key;
//  }
//  int Pop() {
//    if (size == 0) {
//      return 0;
//    }
//    int temp = last->key;
//    Node* del = last;
//    last = last->prev;
//    delete del;
//    --size;
//    return temp;
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
//void Turning(Stack* stack1, Stack* stack2) {
//  while (stack1->size != 0) {
//    int tmp = stack1->Pop();
//    stack2->Push(tmp);
//  }
//}
//
//int Min(const Stack* stack1, const Stack* stack2) {
//  if (stack1->size == 0) {
//    return stack2->last->min;
//  }
//  if (stack2->size == 0) {
//    return stack1->last->min;
//  }
//  return std::min(stack1->last->min, stack2->last->min);
//}
//
//void Solution() {
//  int n;
//  std::cin >> n;
//  int num;
//  auto stack = new Stack;
//  auto stack_turn = new Stack;
//  for (int i = 0; i < n; ++i) {
//    auto* line = new char[100];
//    std::cin >> line;
//    if (strcmp(line, "enqueue") == 0) {
//      std::cin >> num;
//      stack->Push(num);
//      std::cout << "ok" << std::endl;
//    }
//    if (strcmp(line, "dequeue") == 0) {
//      if (stack_turn->Size() != 0) {
//        std::cout << stack_turn->Pop() << std::endl;
//      } else {
//        if (stack->Size() != 0) {
//          Turning(stack, stack_turn);
//          std::cout << stack_turn->Pop() << std::endl;
//        } else {
//          std::cout << "error" << std::endl;
//        }
//      }
//    }
//    if (strcmp(line, "front") == 0) {
//      if (stack_turn->Size() != 0) {
//        std::cout << stack_turn->Back() << std::endl;
//      } else {
//        if (stack->Size() != 0) {
//          Turning(stack, stack_turn);
//          std::cout << stack_turn->Back() << std::endl;
//        } else {
//          std::cout << "error" << std::endl;
//        }
//      }
//    }
//    if (strcmp(line, "size") == 0) {
//      std::cout << stack->size + stack_turn->size << std::endl;
//    }
//    if (strcmp(line, "clear") == 0) {
//      stack->Clear();
//      stack_turn->Clear();
//      std::cout << "ok" << std::endl;
//    }
//    if (strcmp(line, "min") == 0) {
//      if (stack->size != 0 || stack_turn->size != 0) {
//        std::cout << Min(stack, stack_turn) << std::endl;
//      } else {
//        std::cout << "error" << std::endl;
//      }
//    }
//    delete[] line;
//  }
//  stack->Clear();
//  stack_turn->Clear();
//  delete stack;
//  delete stack_turn;
//}
//int main() {
//  Solution();
//  return 0;
//}