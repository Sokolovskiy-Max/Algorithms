//#include <iostream>
//#include <vector>
//#include <cmath>
//struct Node {
//  int64_t value_;
//  int64_t promise_;
//  Node(int64_t value, int64_t promise) : value_(value), promise_(promise) {
//  }
//};
//
//
//class SegmentTree {
//  std::vector<int64_t> arr_;
//  int64_t n_ = 0;
//  std::vector<Node> tree_;
//  int64_t neutral_ = 0;
//
//  void Push(int64_t node) {
//    tree_[node].value_ = UpdateOperation(tree_[node].value_, tree_[node].promise_);
//    tree_[Left(node)].promise_ = UpdateOperation(tree_[Left(node)].promise_, tree_[node].promise_);
//    tree_[Right(node)].promise_ = UpdateOperation(tree_[Right(node)].promise_, tree_[node].promise_);
//    tree_[node].promise_ = neutral_;
//  }
//
//  int64_t Parent(int64_t i) {
//    return std::floor((i - 1) / 2);
//  }
//
//  int64_t Left(int64_t i) {
//    return (2 * i + 1);
//  }
//
//  int64_t Right(int64_t i) {
//    return (2 * i + 2);
//  }
//
//  bool IsLeftSon(int64_t i) {
//    return (i % 2 == 1);
//  }
//
//  bool IsRightSon(int64_t i) {
//    return (i % 2 == 0);
//  }
//
//  int64_t Operation(int64_t a, int64_t b) {
//    return std::max(a, b);
//  }
//
//  int64_t UpdateOperation(int64_t a, int64_t b) {
//    return a + b;
//  }
//
// public:
//  explicit SegmentTree(int64_t n) {
//    int64_t temp = 1;
//    while (temp < n) {
//      temp *= 2;
//    }
//    n_ = temp;
//    arr_.resize(n_, neutral_);
//    for (int64_t i = 0; i < n; ++i) {
//      std::cin >> arr_[i];
//    }
//    tree_.resize(2 * n_ - 1, Node(neutral_, neutral_));
//    for (int64_t i = n_ - 1; i < 2 * n_ - 1; ++i) {
//      tree_[i] = Node(arr_[i - n_ + 1], neutral_);
//    }
//    for (int64_t i = n_ - 2; i >= 0; --i) {
//      tree_[i] = Node(Operation(tree_[Left(i)].value_, tree_[Right(i)].value_), neutral_);
//    }
//  }
//
//  int64_t AboveQuery(int64_t l, int64_t r, int64_t node, int64_t a, int64_t b) {
//    if (b == -1) {
//      b = 2 * n_ - 2;
//      l += n_ - 1;
//      r += n_ - 1;
//      a += n_ - 1;
//    }
//    if (a >= l && b <= r) {
//      return UpdateOperation(tree_[node].value_, tree_[node].promise_);
//    }
//    if (b < l || a > r) {
//      return neutral_;
//    }
//    Push(node);
//    int64_t left_res = AboveQuery(l, r, Left(node), a, static_cast<int64_t>(std::floor((a + b) / 2)));
//    int64_t right_res = AboveQuery(l, r, Right(node), static_cast<int64_t>(std::floor((a + b) / 2) + 1), b);
//    return Operation(left_res, right_res);
//  }
//
//  void Update(int64_t l, int64_t r, int64_t node, int64_t a, int64_t b, int64_t delta) {
//    if (b == -1) {
//      b = 2 * n_ - 2;
//      l += n_ - 1;
//      r += n_ - 1;
//      a += n_ - 1;
//    }
//    if (a >= l && b <= r) {
//      tree_[node].promise_ = UpdateOperation(tree_[node].promise_, delta);
//      return;
//    }
//    if (b < l || a > r) {
//      return;
//    }
//    Push(node);
//    Update(l, r, Left(node), a, static_cast<int64_t>(std::floor((a + b) / 2)), delta);
//    Update(l, r, Right(node), static_cast<int64_t>(std::floor((a + b) / 2) + 1), b, delta);
//    tree_[node].value_ = Operation(UpdateOperation(tree_[Left(node)].value_, tree_[Left(node)].promise_), UpdateOperation(tree_[Right(node)].value_, tree_[Right(node)].promise_));
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
//  std::string str;
//  int a = 0;
//  int b = 0;
//  int c = 0;
//  for (int i = 0; i < m; ++i) {
//    std::cin >> str;
//    if (str[0] == 'm') {
//      std::cin >> a >> b;
//      std::cout << segment_tree.AboveQuery(a - 1, b - 1, 0, 0, -1) << ' ';
//    } else {
//      std::cin >> a >> b >> c;
//      segment_tree.Update(a - 1, b - 1, 0, 0, -1, c);
//    }
//  }
//}