//#include <iostream>
//#include <vector>
//
//class SegmentTree {
//  uint32_t n_;
//  std::vector<uint32_t> arr_;
//  std::vector<uint32_t> pref_;
//  uint32_t a_;
//  uint32_t b_;
//  uint32_t cur_;
//  uint32_t sum_;
//
//  uint32_t NextRand() {
//    cur_ = cur_ * a_ + b_;
//    return cur_ >> 8;
//  }
// public:
//  SegmentTree(uint32_t n, uint32_t a, uint32_t b) : n_(n), a_(a), b_(b) {
//    arr_ = std::vector<uint32_t>(n_, 0);
//    pref_ = std::vector<uint32_t>(n_, 0);
//    cur_ = 0;
//  }
//
//  void FiresTypeQuery() {
//    uint32_t add = NextRand();
//    uint32_t l = NextRand();
//    uint32_t r = NextRand();
//    if (l > r) {
//      std::swap(l, r);
//    }
//    if (r != n_ - 1) {
//      arr_[r + 1] -= add;
//    }
//    arr_[l] += add;
//  }
//
//  void SecondTypeQuery() {
//    uint32_t l = NextRand();
//    uint32_t r = NextRand();
//    if (l > r) {
//      std::swap(l, r);
//    }
//    sum_ += pref_[r];
//    if (l != 0) {
//      sum_ -= pref_[l - 1];
//    }
//  }
//
//  void CountPref() {
//    std::vector<uint32_t> tmp(n_);
//    tmp[0] = arr_[0];
//    for (uint32_t i = 1; i < arr_.size(); ++i) {
//      tmp[i] = tmp[i - 1] + arr_[i];
//    }
//    pref_[0] = tmp[0];
//    for (uint32_t i = 1; i < n_; ++i) {
//      pref_[i] = pref_[i - 1] + tmp[i];
//    }
//  }
//
//  uint32_t GetSum() {
//    return sum_;
//  }
//};
//
//
//int main() {
//  uint32_t m = 0;
//  uint32_t q = 0;
//  std::cin >> m >> q;
//  uint32_t a = 0;
//  uint32_t b = 0;
//  std::cin >> a >> b;
//  SegmentTree tree = SegmentTree(1 << 24, a, b);
//  for (uint32_t i = 0; i < m; ++i) {
//    tree.FiresTypeQuery();
//  }
//  tree.CountPref();
//  for (uint32_t i = 0; i < q; ++i) {
//    tree.SecondTypeQuery();
//  }
//  std::cout << tree.GetSum();
//}