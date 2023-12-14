//#include <iostream>
//#include <vector>
//
//struct Node {
//  int64_t key_ = 0;
//  int64_t priority_ = 0;
//  int64_t result_ = 0;
//
//  Node* parent_ = nullptr;
//  Node* left_ = nullptr;
//  Node* right_ = nullptr;
//
//  Node() = default;
//
//  explicit Node(int64_t x) : key_(x) {
//    priority_ = std::rand();
//    result_ = x;
//    left_ = nullptr;
//    right_ = nullptr;
//    parent_ = nullptr;
//  }
//};
//
//class Treap {
//  Node* root_ = nullptr;
//
//  int64_t Result(Node* node) {
//    return (node ? node->result_ : 0);
//  }
//
//  void FixNode(Node* node) {
//    if (node) {
//      node->result_ = Result(node->left_) + Result(node->right_) + node->key_;
//    }
//  }
//
//  Node* Merge(Node* tree1, Node* tree2) {
//    if (!tree1) {
//      return tree2;
//    }
//    if (!tree2) {
//      return tree1;
//    }
//    if (tree2->priority_ < tree1->priority_) {
//      tree2->left_ = Merge(tree1, tree2->left_);
//      tree2->left_->parent_ = tree2;
//      FixNode(tree2);
//      return tree2;
//    }
//    tree1->right_ = Merge(tree1->right_, tree2);
//    tree1->right_->parent_ = tree1;
//    FixNode(tree1);
//    return tree1;
//  }
//
//  std::pair<Node*, Node*> Split(Node* node, int64_t key0) {
//    if (!node) {
//      return { nullptr, nullptr };
//    }
//    if (node->key_ < key0) {
//      std::pair<Node*, Node*> tmp = Split(node->right_, key0);
//      node->right_ = tmp.first;
//      if (tmp.first) {
//        tmp.first->parent_ = node;
//      }
//      if (tmp.second) {
//        tmp.second->parent_ = nullptr;
//      }
//      FixNode(node);
//      return { node, tmp.second };
//    }
//    std::pair<Node*, Node*> tmp = Split(node->left_, key0);
//    node->left_ = tmp.second;
//    if (tmp.second) {
//      tmp.second->parent_ = node;
//    }
//    if (tmp.first) {
//      tmp.first->parent_ = nullptr;
//    }
//    FixNode(node);
//    return { tmp.first, node };
//  }
//
//  Node* Exists(int64_t key) {
//    if (!root_) {
//      return nullptr;
//    }
//    Node* node = root_;
//    while (node) {
//      if (key > node->key_) {
//        node = node->right_;
//      } else if (key < node->key_) {
//        node = node->left_;
//      } else {
//        return node;
//      }
//    }
//    return nullptr;
//  }
//
//  Node* Insert(int64_t key) {
//    Node* node_to_ins = new Node(key);
//    if (!root_) {
//      return node_to_ins;
//    }
//    std::pair<Node*, Node*> pair = Split(root_, node_to_ins->key_);
//    return Merge(Merge(pair.first, node_to_ins), pair.second);
//  }
//
//  Node* Delete(Node* node, int64_t key) {
//    if (!node) {
//      return nullptr;
//    }
//    if (node->key_ > key) {
//      node->left_ = Delete(node->left_, key);
//      FixNode(node);
//      return node;
//    }
//    if (node->key_ < key) {
//      node->right_ = Delete(node->right_, key);
//      FixNode(node);
//      return node;
//    }
//    Node* temp_node = Merge(node->left_, node->right_);
//    delete node;
//    return temp_node;
//  }
//
//  Node* Next(Node* node, int64_t key) {
//    if (!node) {
//      return nullptr;
//    }
//    Node* tmp = root_;
//    Node* ans = nullptr;
//    while (tmp) {
//      if (tmp->key_ > key) {
//        ans = tmp;
//        tmp = tmp->left_;
//      } else {
//        tmp = tmp->right_;
//      }
//    }
//    return ans;
//  }
//
//  Node* Prev(Node* node, int64_t key) {
//    if (!node) {
//      return nullptr;
//    }
//    Node* tmp = root_;
//    Node* ans = nullptr;
//    while (tmp) {
//      if (tmp->key_ < key) {
//        ans = tmp;
//        tmp = tmp->right_;
//      } else {
//        tmp = tmp->left_;
//      }
//    }
//    return ans;
//  }
//
//  Node* Kth(Node* node, int64_t k) {
//    if (!node) {
//      return nullptr;
//    }
//    if (k >= Result(node)) {
//      return nullptr;
//    }
//    if (Result(node->left_) > k) {
//      return Kth(node->left_, k);
//    }
//    if (Result(node->left_) < k) {
//      return Kth(node->right_, k - Result(node->left_) - 1);
//    }
//    return node;
//  }
//public:
//  Treap() = default;
//
//  explicit Treap(Node* root) : root_(root) {
//  }
//
//  int64_t RSQ(int64_t l, int64_t r) {
//    auto tmp = Split(root_, l);
//    auto tmp2 = Split(tmp.second, r);
//    int64_t result = Result(tmp2.first);
//    Merge(Merge(tmp.first, tmp2.first), tmp2.second);
//    return result;
//  }
//
//  Node* GetRoot() {
//    return root_;
//  }
//
//  void SetRoot(Node* node) {
//    root_ = node;
//  }
//
//  void ExistsQ(int64_t val) {
//    if (Exists(val)) {
//      std::cout << "true" << '\n';
//    } else {
//      std::cout << "false" << '\n';
//    }
//  }
//
//  void InsertQ(int64_t val) {
//    if (!Exists(val)) {
//      root_ = Insert(val);
//    }
//  }
//
//  void DeleteQ(int64_t val) {
//    if (Exists(val)) {
//      root_ = Delete(root_, val);
//    }
//  }
//
//  void NextQ(int64_t val) {
//    Node* tmp = Next(root_, val);
//    if (tmp) {
//      std::cout << tmp->key_ << '\n';
//    } else {
//      std::cout << "none" << '\n';
//    }
//  }
//
//  void PrevQ(int64_t val) {
//    Node* tmp = Prev(root_, val);
//    if (tmp) {
//      std::cout << tmp->key_ << '\n';
//    } else {
//      std::cout << "none" << '\n';
//    }
//  }
//
//  void KthQ(int64_t x) {
//    Node* tmp = Kth(root_, x);
//    if (tmp) {
//      std::cout << tmp->key_ << '\n';
//    } else {
//      std::cout << "none" << '\n';
//    }
//  }
//  
//  void ChooseQuery(std::string& str) {
//    if (str == "+") {
//      int64_t val = 0;
//      std::cin >> val;
//      InsertQ(val);
//    } else if (str == "?") {
//      int64_t l = 0;
//      int64_t r = 0;
//      std::cin >> l >> r;
//      std::cout << RSQ(l, r + 1) << '\n';
//    }
//  }
//
//  ~Treap() {
//    while (root_ != nullptr) {
//      root_ = Delete(root_, Next(root_, -1)->key_);
//    }
//  }
//};
//
//int main() {
//  Treap tree = Treap();
//  std::string str;
//  int64_t n = 0;
//  std::cin >> n;
//  for (int64_t i = 0; i < n; ++i) {
//    std::cin >> str;
//    tree.ChooseQuery(str);
//  }
//}