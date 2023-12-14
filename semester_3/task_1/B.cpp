#include <iostream>
#include <vector>
class MaxOnSegment {
  int64_t n_;
  std::vector<int64_t> arr_;
  int64_t l_bord_ = 0;
  int64_t r_bord_ = 0;
  int64_t max_sum_ = 0;

public:
  explicit MaxOnSegment(int64_t n) : n_(n) {
    arr_.resize(n_);
    int64_t min_l = -1;
    for (int64_t i = 0; i < n_; ++i) {
      std::cin >> arr_[i];
    }
    int pref = 0;
    max_sum_ = arr_[0];
    for (int64_t i = 0; i < n_; ++i) {
      pref += arr_[i];
      if (pref > max_sum_) {
        max_sum_ = pref;
        l_bord_ = min_l + 1;
        r_bord_ = i;
      }
      if (pref < 0) {
        pref = 0;
        min_l = i;
      }
    }
  }

  void Question() {
    std::cout << l_bord_ + 1 << ' ' << r_bord_ + 1 << ' ' << max_sum_;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int64_t n = 0;
  std::cin >> n;
  MaxOnSegment max_on_segment(n);
  max_on_segment.Question();
}