//#include <iostream>
//struct Node {
//  int64_t key;
//  Node* left = nullptr;
//  Node* right = nullptr;
//  Node* parent = nullptr;
//};
//
//struct Tree {
//  Node* root = nullptr;
//};
//
//void InOrderWalk(Node* x) {
//  if (x != nullptr) {
//    InOrderWalk(x->left);
//    std::cout << x->key;
//    InOrderWalk(x->right);
//  }
//}
//
//void PreOrderWalk(Node* x) {
//  if (x != nullptr) {
//    std::cout << x->key;
//    PreOrderWalk(x->left);
//    PreOrderWalk(x->right);
//  }
//}
//
//void PostOrderWalk(Node* x) {
//  if (x != nullptr) {
//    PostOrderWalk(x->left);
//    PostOrderWalk(x->right);
//    std::cout << x->key;
//  }
//}
//
//Node* Minimum(Node* x) {
//  if (x->left == nullptr) {
//    return x;
//  }
//  return Minimum(x->left);
//}
//
//Node* Maximum(Node* x) {
//  if (x->right == nullptr) {
//    return x;
//  }
//  return Maximum(x->right);
//}
//
//void Insert(Tree* tree, Node* node) {
//  Node* parent = nullptr;
//  Node* root = tree->root;
//  while (root != nullptr) {
//    parent = root;
//    if (node->key < root->key) {
//      root = root->left;
//    } else {
//      root = root->right;
//    }
//  }
//  node->parent = parent;
//  if (parent == nullptr) {
//    tree->root = node;
//  } else if (node->key < parent->key) {
//    parent->left = node;
//  } else if (node->key > parent->key) {
//    parent->right = node;
//  } else {
//    delete node;
//  }
//}
//
//void Transplant(Tree* tree, Node* u, Node* v) {
//  if (u->parent == nullptr) {
//    tree->root = v;
//  } else if (u == u->parent->left) {
//    u->parent->left = v;
//  } else {
//    u->parent->right = v;
//  }
//  if (v != nullptr) {
//    v->parent = u->parent;
//  }
//  delete u;
//}
//void Erase(Tree* tree, Node* node) {
//  if (node->left == nullptr) {
//    Transplant(tree, node, node->right);
//  } else if (node->right == nullptr) {
//    Transplant(tree, node, node->left);
//  } else {
//    Node* y = Minimum(node->right);
//    if (y->parent != node) {
//      Transplant(tree, y, y->right);
//      y->right = node->right;
//      y->right->parent = y;
//    }
//    Transplant(tree, node, y);
//    y->left = node->left;
//    y->left->parent = y;
//  }
//}
//
//void Clear(Node* root) {
//  if (root == nullptr) {
//    return;
//  }
//  if (root->left == nullptr && root->right == nullptr) {
//    delete root;
//    return;
//  }
//  if (root->right != nullptr) {
//    Clear(root->right);
//  }
//  if (root->left != nullptr) {
//    Clear(root->left);
//  }
//  delete root;
//}
//
//void PrintForks(Node* root) {
//  if (root != nullptr) {
//    PrintForks(root->left);
//    if (root->left != nullptr && root->right != nullptr) {
//      std::cout << root->key << ' ';
//    }
//    PrintForks(root->right);
//  }
//}
//
//int main() {
//  auto tree = new Tree;
//  int i;
//  std::cin >> i;
//  while (i != 0) {
//    auto node = new Node;
//    node->key = i;
//    Insert(tree, node);
//    std::cin >> i;
//  }
//  PrintForks(tree->root);
//  Clear(tree->root);
//  delete tree;
//  return 0;
//}