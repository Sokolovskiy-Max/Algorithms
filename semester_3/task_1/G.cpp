//#include <iostream>
//#include <vector>
//#include <cmath>
//class SegmentTree {
//  std::vector<int64_t> arr_;
//  int64_t n_ = 0;
//  std::vector<int64_t> tree_;
//  int64_t neutral_ = 0;
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
//    tree_.resize(2 * n_ - 1, neutral_);
//    for (int64_t i = n_ - 1; i < 2 * n_ - 1; ++i) {
//      tree_[i] = arr_[i - n_ + 1];
//    }
//    for (int64_t i = n_ - 2; i >= 0; --i) {
//      tree_[i] = Operation(tree_[Left(i)], tree_[Right(i)]);
//    }
//  }
//  void Update() {
//    int64_t i = 0;
//    int64_t v = 0;
//    std::cin >> i >> v;
//    --i;
//    i += n_ - 1;
//    tree_[i] = v;
//    while (i != 0) {
//      i = Parent(i);
//      tree_[i] = Operation(tree_[Left(i)], tree_[Right(i)]);
//    }
//  }
//
//  int64_t BelowQuery(int64_t l, int64_t r) {
//    l += n_ - 1;
//    r += n_ - 1;
//    int64_t left_res = neutral_;
//    int64_t right_res = neutral_;
//    while (l < r) {
//      if (IsRightSon(l)) {
//        left_res = Operation(left_res, tree_[l]);
//      }
//      if (IsLeftSon(r)) {
//        right_res = Operation(tree_[r], right_res);
//      }
//      l = Parent(l + 1);
//      r = Parent(r - 1);
//    }
//    if (l == r) {
//      left_res = Operation(left_res, tree_[l]);
//    }
//    return Operation(left_res, right_res);
//  }
//
//  int64_t Count(int64_t l, int64_t r, int64_t value) {  // ?? ???? ?? ??????
//    int64_t count = 0;
//    for (int64_t i = l; i <= r; ++i) {
//      count += (arr_[i] == value ? 1 : 0);
//    }
//    return count;
//  }
//};
//
//int main() {
//  std::ios_base::sync_with_stdio(false);
//  std::cin.tie(nullptr);
//  std::cout.tie(nullptr);
//  int64_t n = 0;
//  std::cin >> n;
//  SegmentTree segment_tree(n);
//  int64_t k = 0;
//  std::cin >> k;
//  int64_t left = 0;
//  int64_t right = 0;
//  for (int64_t i = 0; i < k; ++i) {
//    std::cin >> left >> right;
//    int64_t m = segment_tree.BelowQuery(left - 1, right - 1);
//    int64_t count = segment_tree.Count(left - 1, right - 1, m);
//    std::cout << m << ' ' << count << '\n';
//  }
//}