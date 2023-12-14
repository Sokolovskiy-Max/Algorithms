//#include <iostream>
//#include <vector>
//
//class AVL {
//public:
//  struct Node {
//    Node* left{ nullptr };
//    Node* right{ nullptr };
//    int64_t value;
//    unsigned char height{ 0 };
//  };
//
//  AVL() : root_(nullptr) {}
//  void Insert(int value) { root_ = Insert(root_, value); }
//  ~AVL() { Clear(root_); }
//  void Clear() {
//    Clear(root_);
//    root_ = nullptr;
//  }
//  int64_t FindNext(int value) {
//    int64_t big_value = 1000000001;
//    return Find(root_, value, big_value);
//  }
//  bool Find(int value) { return Find(root_, value); }
//  void Erase(int value) { root_ = Erase(root_, value); }
//
//private:
//  static Node* Erase(Node* node, int value) {
//    if (node == nullptr) {
//      return node;
//    }
//    if (node->value == value) {
//      if (node->right == nullptr) {
//        Node* temp = node->left;
//        delete node;
//        return CheckBalancir(temp);
//      }
//      Node* minimum_r = FindMinimum(node->right);
//      node->right = UnlinkMin(node->right);
//      minimum_r->left = node->left;
//      minimum_r->right = node->right;
//      delete node;
//      return CheckBalancir(minimum_r);
//    }
//    if (value <= node->value) {
//      node->left = Erase(node->left, value);
//    } else {
//      node->right = Erase(node->right, value);
//    }
//    return CheckBalancir(node);
//  }
//
//  static Node* FindMinimum(Node* node) {
//    if (node->left == nullptr) {
//      return node;
//    }
//    return FindMinimum(node->left);
//  }
//  static Node* UnlinkMin(Node* node) {
//    if (node->left == nullptr) {
//      return node->right;
//    }
//    node->left = UnlinkMin(node->left);
//    return CheckBalancir(node);
//  }
//  static bool Find(Node* node, int64_t value) {
//    if (node == nullptr) {
//      return false;
//    }
//    if (node->value == value) {
//      return true;
//    }
//    if (value <= node->value) {
//      return Find(node->left, value);
//    }
//    return Find(node->right, value);
//  }
//  static int Find(Node* node, int value, int64_t big_value) {
//    if (node == nullptr) {
//      if (big_value == 1000000001) {
//        return -1;
//      }
//      return big_value;
//    }
//    if ((big_value > node->value) && (node->value >= value)) {
//      big_value = node->value;
//    }
//    if (node->value > value) {
//      return Find(node->left, value, big_value);
//    }
//    return Find(node->right, value, big_value);
//  }
//  static void Clear(Node* node) {
//    if (node->left != nullptr) {
//      Clear(node->left);
//    }
//    if (node->right != nullptr) {
//      Clear(node->right);
//    }
//    delete node;
//  }
//  static Node* Insert(Node* node, int value) {
//    if (node == nullptr) {
//      Node* node_new = new Node;
//      node_new->value = value;
//      return node_new;
//    }
//    if (value > node->value) {
//      node->right = Insert(node->right, value);
//    } else {
//      node->left = Insert(node->left, value);
//    }
//    return CheckBalancir(node);
//  }
//
//  static int64_t Height(Node* node) {
//    return node == nullptr ? 0 : node->height;
//  }
//
//  static void ChangeHeight(Node* node) {
//    if (node == nullptr) {
//      return;
//    }
//    node->height = std::max(Height(node->right), Height(node->left)) + 1;
//  }
//
//  static Node* RotateRight(Node* p) {
//    Node* w = p->left;
//    p->left = w->right;
//    w->right = p;
//    ChangeHeight(p);
//    ChangeHeight(w);
//    return w;
//  }
//
//  static Node* RotateLeft(Node* w) {
//    Node* p = w->right;
//    w->right = p->left;
//    p->left = w;
//    ChangeHeight(w);
//    ChangeHeight(p);
//    return p;
//  }
//
//  static Node* CheckBalancir(Node* node) {
//    ChangeHeight(node);
//    if (BalanceFactor(node) == 2) {
//      if (BalanceFactor(node->right) == -1) {
//        node->right = RotateRight(node->right);
//      }
//      return RotateLeft(node);
//    }
//    if (BalanceFactor(node) == -2) {
//      if (BalanceFactor(node->left) == 1) {
//        node->left = RotateLeft(node->left);
//      }
//      return RotateRight(node);
//    }
//    return node;
//  }
//  static int64_t BalanceFactor(Node* node) {
//    return node == nullptr ? 0 : Height(node->right) - Height(node->left);
//  }
//
//  Node* root_;
//};
//
//int main() {
//  int n;
//  char quection[3];
//  bool last_bool = false;
//  int last_value = -1;
//  std::cin >> n;
//  int64_t mod = 1000000000;
//  int64_t inserting_value, lval;
//  AVL* tree = new AVL();
//  for (int i = 0; i < n; ++i) {
//    std::cin >> quection;
//    std::cin >> inserting_value;
//    lval = -1;
//    if (quection[0] != '+') {
//      lval = tree->FindNext(inserting_value);
//      std::cout << lval << '\n';
//    } else {
//      if (last_bool) {
//        inserting_value = (last_value + inserting_value) % mod;
//        if (!(tree->Find(inserting_value))) {
//          tree->Insert(inserting_value);
//        }
//      } else {
//        if (!(tree->Find(inserting_value))) {
//          tree->Insert(inserting_value);
//        }
//      }
//    }
//    last_value = lval;
//    last_bool = quection[0] == '?';
//  }
//  delete tree;
//}