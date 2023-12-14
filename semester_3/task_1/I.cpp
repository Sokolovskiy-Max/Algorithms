//#include <vector>
//#include <iostream>
//
//struct Node {
//  int64_t key_;
//  int64_t priority_;
//  int64_t arr_pos_ = 0;  // ????? ?????? ???? ????? ????????
//
//  Node* parent_ = nullptr;
//  Node* left_ = nullptr;
//  Node* right_ = nullptr;
//  
//  Node(int64_t key, int64_t priority, int64_t arr_pos, Node* parent, Node* left, Node* right) : key_(key), priority_(priority), arr_pos_(arr_pos), parent_(parent), left_(left), right_(right) {
//  }
//};
//
//class Treap {
//  Node* root_;
//  int64_t n_;
//
//public:
//  Treap(int64_t n, std::vector<Node*> arr) : n_(n) {  // ????????? ???????? ????? ??? ??? ???????? ?? 7? ?????? ? ?? ?? 5?
//    root_ = arr[0];
//    Node* last = root_;
//    for (int64_t i = 1; i < n_; ++i) {
//      Node* cur = last;
//      while (cur && (cur->priority_ > arr[i]->priority_)) {
//        cur = cur->parent_;
//      }
//      if (!cur) {
//        arr[i]->left_ = root_;
//        if (root_) {
//          root_->parent_ = arr[i];
//        }
//        root_ = arr[i];
//      } else {
//        arr[i]->left_ = cur->right_;
//        if (cur->right_) {
//          cur->right_->parent_ = arr[i];
//        }
//        cur->right_ = arr[i];
//        arr[i]->parent_ = cur;
//      }
//      last = arr[i];
//    }
//  }
//
//  Node* GetRoot() {
//    return root_;
//  }
//
//  void Norder(Node* root) {
//    if (root) {
//      Norder(root->left_);
//      std::cout << (root->parent_ ? root->parent_->arr_pos_ : 0) << " ";
//      std::cout << (root->left_ ? root->left_->arr_pos_ : 0) << " ";
//      std::cout << (root->right_ ? root->right_->arr_pos_ : 0) << "\n";
//      Norder(root->right_);
//    }
//    return;
//  }
//};
//
//int main() {
//  int64_t n = 0;
//  std::cin >> n;
//  std::vector<Node*> arr(n);
//  int64_t key = 0;
//  int64_t priority = 0;
//  for (int64_t i = 0; i < n; ++i) {
//    std::cin >> key >> priority;
//    arr[i] = new Node(key, priority, i + 1, nullptr, nullptr, nullptr);
//  }
//  Treap treap = Treap(n, arr);
//  std::cout << "YES\n";  //  ???? ?? ????? ? ??? ??? ?????? ????????? ????? (?? ??? ? xy ?????????? ????)
//  treap.Norder(treap.GetRoot());
//}