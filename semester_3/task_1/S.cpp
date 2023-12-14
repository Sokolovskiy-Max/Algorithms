//#include <iostream>
//#include <random>
//#include <vector>
//
//class Treap {
//public:
//  struct Node {
//    unsigned long long priority;
//    long long size_subtree;
//    long long min_subtree;
//    long long value;
//    Node* left_child{ nullptr };
//    Node* right_child{ nullptr };
//    bool reverse{ false };
//  };
//
//  Treap() = default;
//
//  ~Treap() { Clear(); }
//
//  void Insert(long long pos, long long value) {
//    root_ = Insert(root_, pos, value);
//  }
//
//  void PushBack(long long value) { root_ = PushBack(root_, value); }
//
//  void MinSegment(long long left, long long right) { MinSegment(root_, left, right); }
//
//  void Reverse(long long left, long long right) { root_ = Reverse(root_, left, right); }
//
//  void Clear() {
//    Clear(root_);
//    root_ = nullptr;
//  }
//
//private:
//  Node* root_ = nullptr;
//  static std::random_device random_device;
//  static std::mt19937_64 mersenne;
//
//  static Node* Merge(Node* tree1, Node* tree2) {
//    Push(tree1);
//    Push(tree2);
//    if (tree1 == nullptr) {
//      return tree2;
//    }
//    if (tree2 == nullptr) {
//      return tree1;
//    }
//    if (tree1->priority < tree2->priority) {
//      tree1->size_subtree += tree2->size_subtree;
//      tree1->min_subtree = std::min(tree1->min_subtree, tree2->min_subtree);
//      tree1->right_child = Merge(tree1->right_child, tree2);
//      return tree1;
//    }
//    tree2->size_subtree += tree1->size_subtree;
//    tree2->min_subtree = std::min(tree2->min_subtree, tree1->min_subtree);
//    tree2->left_child = Merge(tree1, tree2->left_child);
//    return tree2;
//  }
//
//  static std::pair<Node*, Node*> SplitBySize(Node* root, long long size) {
//    Push(root);
//
//    if (root == nullptr) {
//      return { nullptr, nullptr };
//    }
//
//    if (root->size_subtree < size) {
//      return { nullptr, root };
//    }
//
//    long long left_size;
//    if (root->left_child == nullptr) {
//      left_size = 0;
//    } else {
//      left_size = root->left_child->size_subtree;
//    }
//
//    if (left_size >= size) {
//      root->size_subtree -= left_size;
//      root->min_subtree = root->value;
//      auto left_split = SplitBySize(root->left_child, size);
//      root->left_child = left_split.second;
//      if (left_split.second != nullptr) {
//        root->size_subtree += left_split.second->size_subtree;
//        root->min_subtree =
//          std::min(root->left_child->min_subtree, root->value);
//      }
//      if (root->right_child != nullptr) {
//        root->min_subtree =
//          std::min(root->min_subtree, root->right_child->min_subtree);
//      }
//      return { left_split.first, root };
//    }
//    if (root->right_child != nullptr) {
//      root->size_subtree -= root->right_child->size_subtree;
//    }
//    root->min_subtree = root->value;
//    auto right_split = SplitBySize(root->right_child, size - left_size - 1);
//    root->right_child = right_split.first;
//    if (right_split.first != nullptr) {
//      root->size_subtree += right_split.first->size_subtree;
//      root->min_subtree =
//        std::min(root->min_subtree, root->right_child->min_subtree);
//    }
//    if (root->left_child != nullptr) {
//      root->min_subtree =
//        std::min(root->min_subtree, root->left_child->min_subtree);
//    }
//    return { root, right_split.second };
//  }
//
//  static void Clear(Node* start) {
//    if (start == nullptr) {
//      return;
//    }
//    if (start->left_child != nullptr) {
//      Clear(start->left_child);
//    }
//    if (start->right_child != nullptr) {
//      Clear(start->right_child);
//    }
//    delete start;
//  }
//
//  static Node* Insert(Node* root, long long pos, long long value) {
//    Node* new_node = new Node;
//    new_node->value = value;
//    new_node->priority = mersenne();
//    new_node->min_subtree = value;
//    new_node->size_subtree = 1;
//    if (pos == 0) {
//      return Merge(new_node, root);
//    }
//    auto splitted = SplitBySize(root, pos);
//    return Merge(Merge(splitted.first, new_node), splitted.second);
//  }
//static Node* PushBack(Node* root, long long value) {
//  Node* new_node = new Node;
//  new_node->value = value;
//  new_node->priority = mersenne();
//  new_node->min_subtree = value;
//  new_node->size_subtree = 1;
//  return Merge(root, new_node);
//}
//
//static Node* MinSegment(Node* root, long long left, long long right) {
//  auto splitted = SplitBySize(root, right);
//  auto splitted2 = SplitBySize(splitted.first, left - 1);
//  std::cout << splitted2.second->min_subtree << '\n';
//  return Merge(Merge(splitted2.first, splitted2.second), splitted.second);
//}
//
//static void Push(Node* current) {
//  if (current != nullptr) {
//    if (current->reverse) {
//      Node* tmp = current->left_child;
//      current->left_child = current->right_child;
//      current->right_child = tmp;
//      if (current->left_child != nullptr) {
//        current->left_child->reverse ^= 1;
//      }
//      if (current->right_child != nullptr) {
//        current->right_child->reverse ^= 1;
//      }
//    }
//    current->reverse = false;
//  }
//}
//
//static Node* Reverse(Node* root, long long left, long long right) {
//  auto split1 = SplitBySize(root, right);
//  auto split2 = SplitBySize(split1.first, left - 1);
//  split2.second->reverse ^= 1;
//  return Merge(Merge(split2.first, split2.second), split1.second);
//}
//};
//
//std::random_device Treap::random_device;
//std::mt19937_64 Treap::mersenne(random_device());
//
//void FillingTheData(Treap& treap, const size_t& treap_size) {
//  for (size_t i = 0; i < treap_size; ++i) {
//    long long element;
//    std::cin >> element;
//    treap.PushBack(element);
//  }
//}
//
//void ProcessingTheData(Treap& treap, const size_t& amount_requests) {
//  for (size_t j = 0; j < amount_requests; ++j) {
//    char command;
//    long long left;
//    long long right;
//    std::cin >> command >> left >> right;
//    if (command == '1') {
//      treap.Reverse(left, right);
//    } else if (command == '2') {
//      treap.MinSegment(left, right);
//    }
//  }
//}
//
//int main() {
//  Treap treap;
//  size_t treap_size;
//  size_t amount_requests;
//  std::cin >> treap_size >> amount_requests;
//  FillingTheData(treap, treap_size);
//  ProcessingTheData(treap, amount_requests);
//}