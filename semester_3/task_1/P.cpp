//#include <iostream>
//#include <vector>
//#include <cmath>
//struct Node {
//  int value_ = 0;
//  int promise_ = 0;
//  int childs_ = 0;
//
//  Node(int value, int promise, int childs) : value_(value), promise_(promise), childs_(childs) {
//  }
//};
//
//
//class SegmentTree {
//  std::vector<int> arr_;
//  int n_ = 0;
//  std::vector<Node> tree_;
//
//  void Push(int node) {
//    tree_[node].value_ = tree_[node].value_ + tree_[node].promise_ * tree_[node].childs_;
//    tree_[Left(node)].promise_ = tree_[Left(node)].promise_ + tree_[node].promise_;
//    tree_[Right(node)].promise_ = tree_[Right(node)].promise_ + tree_[node].promise_;
//    tree_[node].promise_ = 0;
//  }
//
//  int Parent(int i) {
//    return std::floor((i - 1) / 2);
//  }
//
//  int Left(int i) {
//    return (2 * i + 1);
//  }
//
//  int Right(int i) {
//    return (2 * i + 2);
//  }
//
//  bool IsLeftSon(int i) {
//    return (i % 2 == 1);
//  }
//
//  bool IsRightSon(int i) {
//    return (i % 2 == 0);
//  }
//
// public:
//  explicit SegmentTree(int n) {
//    int temp = 1;
//    while (temp < n) {
//      temp *= 2;
//    }
//    n_ = temp;
//    arr_.resize(n_, 0);
//    for (int i = 0; i < n; ++i) {
//      arr_[i] = 0;
//    }
//    tree_.resize(2 * n_ - 1, Node(0, 0, 1));
//    for (int i = n_ - 1; i < 2 * n_ - 1; ++i) {
//      tree_[i] = Node(arr_[i - n_ + 1], 0, 1);
//    }
//    for (int i = n_ - 2; i >= 0; --i) {
//      tree_[i] = Node((tree_[Left(i)].value_ + tree_[Right(i)].value_), 0, tree_[Left(i)].childs_ * 2);
//    }
//  }
//
//  int AboveQuery(int l, int r, int node, int a, int b) {
//    if (b == -1) {
//      b = 2 * n_ - 2;
//      l += n_ - 1;
//      r += n_ - 1;
//      a += n_ - 1;
//    }
//    if (a >= l && b <= r) {
//      return (tree_[node].value_ + tree_[node].promise_ * tree_[node].childs_);
//    }
//    if (b < l || a > r) {
//      return 0;
//    }
//    Push(node);
//    int left_res = AboveQuery(l, r, Left(node), a, static_cast<int>(std::floor((a + b) / 2)));
//    int right_res = AboveQuery(l, r, Right(node), static_cast<int>(std::floor((a + b) / 2) + 1), b);
//    return (left_res + right_res);
//  }
//
//  void Update(int l, int r, int node, int a, int b, int delta) {
//    if (b == -1) {
//      b = 2 * n_ - 2;
//      l += n_ - 1;
//      r += n_ - 1;
//      a += n_ - 1;
//    }
//    if (a >= l && b <= r) {
//      tree_[node].promise_ = (tree_[node].promise_ + delta);
//      return;
//    }
//    if (b < l || a > r) {
//      return;
//    }
//    Push(node);
//    Update(l, r, Left(node), a, static_cast<int>(std::floor((a + b) / 2)), delta);
//    Update(l, r, Right(node), static_cast<int>(std::floor((a + b) / 2) + 1), b, delta);
//    tree_[node].value_ = ((tree_[Left(node)].value_ + tree_[Left(node)].promise_ * tree_[Left(node)].childs_) + (tree_[Right(node)].value_ + tree_[Right(node)].promise_ * tree_[Right(node)].childs_));
//  }
//};
//
//int main() {
//  std::ios_base::sync_with_stdio(false);
//  std::cin.tie(nullptr);
//  std::cout.tie(nullptr);
//  int n = 0;
//  std::cin >> n;
//  SegmentTree segment_tree(n);
//  int m = 0;
//  std::cin >> m;
//  int type = 0;
//  int l = 0;
//  int r = 0;
//  int delta = 0;
//  for (int i = 0; i < m; ++i) {
//    std::cin >> type;
//    if (type == 2) {
//      std::cin >> l >> r;
//      std::cout << segment_tree.AboveQuery(l, r - 1, 0, 0, -1) << ' ';
//    } else {
//      std::cin >> l >> r >> delta;
//      segment_tree.Update(l, r - 1, 0, 0, -1, delta);
//    }
//  }
//}