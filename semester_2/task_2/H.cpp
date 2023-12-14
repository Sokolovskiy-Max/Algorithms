//#include <iostream>
//#include <vector>
//
//class MoneyBoxs {
//  int n_;
//  std::vector<int> keys_;
//  std::vector<int> used_;
//
// public:
//  explicit MoneyBoxs(int n) : n_(n) {
//    keys_.resize(n_ + 1);
//    used_.resize(n_ + 1, 0);
//  }
//
//  friend std::istream& operator>>(std::istream&, MoneyBoxs&);
//
//  int MinCount() {
//    int count = 0;
//    for (int i = 1; i <= n_; ++i) {
//      if (used_[i] == 0) {
//        int start = i;
//        int j = i;
//        for (; used_[j] == 0; j = keys_[j]) {
//          used_[j] = start;
//        }
//        if (used_[j] == start) {
//          ++count;
//        }
//      }
//    }
//    return count;
//  }
//};
//
//std::istream& operator>>(std::istream& is, MoneyBoxs& money_boxs) {
//  for (int i = 1; i <= money_boxs.n_; ++i) {
//    is >> money_boxs.keys_[i];
//  }
//  return is;
//}
//
//int main() {
//  int n;
//  std::cin >> n;
//  MoneyBoxs money_boxs = MoneyBoxs(n);
//  std::cin >> money_boxs;
//  std::cout << money_boxs.MinCount();
//  return 0;
//}