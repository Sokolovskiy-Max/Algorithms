//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class item {
//public:
//  int key;
//  int cnt;
//  item* l;
//  item* r;
//
//  item(int k) {
//    key = k;
//    cnt = 1;
//    l = nullptr;
//    r = nullptr;
//  }
//};
//class Tree {
//  int cnt(item* t) {
//    return t ? t->cnt : 0;
//  }
//
//  void upd_cnt(item* t) {
//    if (t)
//      t->cnt = 1 + cnt(t->l) + cnt(t->r);
//  }
//  void merge(item& t, item* l, item* r) {
//    if (!l || !r)
//      t = l ? l : r;
//    else if (l->prior > r->prior)
//      merge(l->r, l->r, r), t = l;
//    else
//      merge(r->l, l, r->l), t = r;
//    upd_cnt(t);
//  }
//
//  void split(pitem t, pitem& l, pitem& r, int key, int add = 0) {
//    if (!t)
//      return void(l = r = 0);
//    int cur_key = add + cnt(t->l);
//    if (key <= cur_key)
//      split(t->l, l, t->l, key, add), r = t;
//    else
//      split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
//    upd_cnt(t);
//  }
//
//  void printTree(Node* node) {
//    if (node == nullptr) {
//      return;
//    }
//    printTree(node->left);
//    cout << node->key << " ";
//    printTree(node->right);
//  }
//};
//int main() {
//  int n, m;
//  cin >> n >> m;
//
//  Node* tree = nullptr;
//  for (int i = 1; i <= n; i++) {
//    tree = insert(tree, i);
//  }
//
//  for (int i = 0; i < m; i++) {
//    int l, r;
//    cin >> l >> r;
//    pair<Node*, Node*> splitted1 = split(tree, l);
//    pair<Node*, Node*> splitted2 = split(splitted1.second, r + 1);
//    tree = merge(splitted2.first, merge(splitted1.first, splitted2.second));
//    printTree(tree);
//  }
//
//  
//
//  return 0;
//}