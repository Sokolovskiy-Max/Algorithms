//#include <iostream>
//#include <vector>
//class OnlineStaticRmq {
//  int64_t n_;
//  std::vector<int64_t> pref_sum_;
//
// public:
//  explicit OnlineStaticRmq(int64_t n) : n_(n) {
//    pref_sum_.resize(n + 1, 0);
//    int64_t sum = 0;
//    int64_t cost = 0;
//    for (int64_t i = 1; i <= n; ++i) {
//      std::cin >> cost;
//      sum += cost;
//      pref_sum_[i] = sum;
//    }
//  }
//  int64_t Question(int64_t l, int64_t r) {
//    return(pref_sum_[r] - pref_sum_[l - 1]);
//  }
//};
//
//int main() {
//  std::ios_base::sync_with_stdio(false);
//  std::cin.tie(nullptr);
//  std::cout.tie(nullptr);
//  int64_t n = 0;
//  int64_t m = 0;
//  int64_t l = 0;
//  int64_t r = 0;
//  std::cin >> n;
//  OnlineStaticRmq rmq(n);
//  std::cin >> m;
//  for (int64_t i = 0; i < m; ++i) {
//    std::cin >> l >> r;
//    std::cout << rmq.Question(l, r) << ' ';
//  }
//}