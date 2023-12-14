//#include <iostream>
//#include <vector>
//int64_t Fl(int64_t len) {
//  if (len == 1) {
//    return 0;
//  }
//  return Fl((len - len % 2) / 2) + 1;
//}
//
//class OnlineStaticRmq {
//  int64_t n_;
//  std::vector<std::vector<int64_t>> st_;
//  std::vector<int64_t> arr_;
//  std::vector<int64_t> log_;
//
// public:
//  explicit OnlineStaticRmq(int64_t n) : n_(n) {
//    log_.resize(n_ + 2);
//    arr_.resize(n);
//    for (int64_t i = 1; i <= n_ + 1; ++i) {
//      log_[i] = Fl(i);
//    }
//    st_.resize(log_[n_] + 1);
//    for (int64_t i = 0; i < log_[n_] + 1; ++i) {
//      st_[i].resize(n, 0);
//    }
//    int64_t val = 0;
//    for (int64_t i = 0; i < n_; ++i) {
//      std::cin >> val;
//      arr_[i] = val;
//    }
//    for (int64_t k = 0; k < log_[n_] + 1; ++k) {
//      for (int64_t i = 0; i + static_cast<int>(std::pow(2, k)) - 1 < n_; ++i) {
//        if (k == 0) {
//          st_[0][i] = arr_[i];
//        } else {
//          st_[k][i] = std::min(st_[k - 1][i], st_[k - 1][i + static_cast<int>(std::pow(2, k - 1))]);
//        }
//      }
//    }
//  }
//  int64_t Question(int64_t l, int64_t r) {
//    if (l == r) {
//      return arr_[l];
//    }
//    return (std::min(st_[log_[r - l + 1]][l], st_[log_[r - l + 1]][r - static_cast<int>(std::pow(2, log_[r - l + 1])) + 1]));
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
//  std::cin >> n >> m;
//  OnlineStaticRmq rmq(n);
//  for (int64_t i = 0; i < m; ++i) {
//    std::cin >> l >> r;
//    std::cout << rmq.Question(l - 1, r - 1) << '\n';
//  }
//}