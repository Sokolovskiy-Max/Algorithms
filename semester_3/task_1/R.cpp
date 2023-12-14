//#include <iostream>
//#include <vector>
//
//struct Node {
//  int64_t priority_ = 0;
//  int64_t size_ = 1;
//  int64_t min_ = 0;
//  int64_t key_ = 0;
//
//  Node* left_ = nullptr;
//  Node* right_ = nullptr;
//
//  Node(int64_t key) : key_(key), min_(key), size_(1), priority_(std::rand()) {
//  }
//};
//
//class Treap {
//  Node* root_ = nullptr;
//
//  Node* Merge(Node* tree1, Node* tree2) {
//    if (!tree1) {
//      return tree2;
//    }
//    if (!tree2) {
//      return tree1;
//    }
//    if (tree1->priority_ < tree2->priority_) {
//      tree1->size_ += tree2->size_;
//      tree1->min_ = std::min(tree1->min_, tree2->min_);
//      tree1->right_ = Merge(tree1->right_, tree2);
//      return tree1;
//    }
//    tree2->size_ += tree1->size_;
//    tree2->min_ = std::min(tree2->min_, tree1->min_);
//    tree2->left_ = Merge(tree1, tree2->left_);
//    return tree2;
//  }
//
//  static std::pair<Node*, Node*> Split(Node* node, int64_t k) {
//    if (!node) {
//      return { nullptr, nullptr };
//    }
//    if (node->size_ < k) {
//      return { nullptr, node };
//    }
//    int64_t left_size = (!node->left_ ? 0 : node->left_->size_);
//    if (left_size >= k) {
//      node->size_ -= left_size;
//      node->min_ = node->key_;
//      std::pair<Node*, Node*> tmp = Split(node->left_, k);
//      node->left_ = tmp.second;
//      if (tmp.second) {
//        node->size_ += tmp.second->size_;
//        node->min_ =
//          std::min(node->left_->min_, node->key_);
//      }
//      if (node->right_) {
//        node->min_ =
//          std::min(node->min_, node->right_->min_);
//      }
//      return { tmp.first, node };
//    }
//    if (node->right_) {
//      node->size_ -= node->right_->size_;
//    }
//    node->min_ = node->key_;
//    std::pair<Node*, Node*> tmp = Split(node->right_, k - left_size - 1);
//    node->right_ = tmp.first;
//    if (tmp.first) {
//      node->size_ += tmp.first->size_;
//      node->min_ = std::min(node->min_, node->right_->min_);
//    }
//    if (node->left_) {
//      node->min_ = std::min(node->min_, node->left_->min_);
//    }
//    return { node, tmp.second };
//  }
//
// public:
//  Node* GetRoot() {
//    return root_;
//  }
//  void Insert(Node* node, int64_t pos, int64_t key) {
//    Node* new_node = new Node(key);
//    if (pos == 0) {
//      root_ = Merge(new_node, node);
//      return;
//    }
//    std::pair<Node*, Node*> tmp = Split(node, pos);
//    root_ = Merge(Merge(tmp.first, new_node), tmp.second);
//  }
//
//  void MinSegment(Node* root, int64_t l, int64_t r) {
//    std::pair<Node*, Node*> tmp1 = Split(root, r);
//    std::pair<Node*, Node*> tmp2 = Split(tmp1.first, l - 1);
//    std::cout << tmp2.second->min_ << '\n';
//    Merge(Merge(tmp2.first, tmp2.second), tmp1.second);
//  }
//};
//
//int main() {
//  int64_t n = 0;
//  std::cin >> n;
//  Treap treap;
//  std::string str;
//  int64_t a = 0;
//  int64_t b = 0;
//  for (int64_t i = 0; i < n; ++i) {
//    std::cin >> str;
//    if (str == "?") {
//      std::cin >> a >> b;
//      treap.MinSegment(treap.GetRoot(), a, b);
//    } else if (str == "+") {
//      std::cin >> a >> b;
//      treap.Insert(treap.GetRoot(), a, b);
//    }
//  }
//}