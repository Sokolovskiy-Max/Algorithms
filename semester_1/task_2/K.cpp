//#include <iostream>
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
//
//
//int main() {
//
//  int n, k;
//  std::cin >> n;
//  std::cin >> k;
//  auto arr = new int[n];
//  for (int i = 0; i < n; ++i) {
//    std::cin >> arr[i];
//  }
//  auto stack = new Stack;
//  auto stack_turn = new Stack;
//  for (int i = 0; i < k; ++i) {
//    stack->Push(arr[i]);
//  }
//  std::cout << Min(stack, stack_turn) << std::endl;
//  for (int i = k; i < n; ++i) {
//    stack->Push(arr[i]);
//    if (stack_turn->Size() != 0) {
//      stack_turn->Pop();
//    } else {
//      if (stack->Size() != 0) {
//        Turning(stack, stack_turn);
//        stack_turn->Pop();
//      }
//    }
//    std::cout << Min(stack, stack_turn) << std::endl;
//  }
//  stack->Clear();
//  stack_turn->Clear();
//  delete stack;
//  delete stack_turn;
//  delete[] arr;
//  return 0;
//}