//#include <iostream>
//#include <vector>
//
//class SparceTable2D {
//  int n_;
//  int m_;
//  std::vector<std::vector<std::vector<std::vector<int>>>> st_;
//  std::vector<std::vector<int>> arr_;
//  std::vector<int> log_;
//
// public:
//  explicit SparceTable2D(int n, int m) : n_(n), m_(m) {
//    log_.resize(std::max(n_ + 2, m_ + 2));
//
//    for (int i = 1; i <= std::max(n_ + 1, m_ + 1); ++i) {
//      log_[i] = std::floor(std::log2(i));
//    }
//
//    arr_.resize(n);
//    for (int i = 0; i < n_; ++i) {
//      arr_[i].resize(m_);
//    }
//
//    for (int i = 0; i < n_; ++i) {
//      for (int j = 0; j < m_; ++j) {
//        std::cin >> arr_[i][j];
//      }
//    }
//
//    st_.resize(n_);
//    for (int i = 0; i < n_; ++i) {
//      st_[i].resize(m_);
//      for (int j = 0; j < m_; ++j) {
//        st_[i][j].resize(log_[n_] + 1);
//        for (int k = 0; k < log_[n_] + 1; ++k) {
//          st_[i][j][k].resize(log_[m_] + 1);
//        }
//      }
//    }
//    for (int i = 0; i < n_; ++i) {
//      for (int j = 0; j < m_; ++j) {
//        for (int k = 0; k < log_[n_] + 1; ++k) {
//          for (int t = 0; t < log_[m_] + 1; ++t) {
//            st_[i][j][k][t] = ((k == 0 || t == 0) ? arr_[i][j] : 0);
//          }
//        }
//      }
//    }
//    for (int i = 0; i < n_; ++i) {
//      for (int lg = 1; lg < log_[m_] + 1; ++lg) {
//        for (int j = 0; j < m_ - static_cast<int>(std::pow(2, lg)) + 1; ++j) {
//          st_[i][j][0][lg] =
//              std::min(st_[i][j][0][lg - 1], st_[i][j + static_cast<int>(std::pow(2, lg - 1))][0][lg - 1]);
//        }
//      }
//    }
//    for (int k = 1; k < log_[n_] + 1; ++k) {
//      for (int i = 0; i < n_ - static_cast<int>(std::pow(2, k)) + 1; ++i) {
//        for (int t = 0; t < log_[m_] + 1; ++t) {
//          for (int j = 0; j < m_ - static_cast<int>(std::pow(2, t)) + 1; ++j) {
//            st_[i][j][k][t] =
//                std::min(st_[i][j][k - 1][t], st_[i + static_cast<int>(std::pow(2, k - 1))][j][k - 1][t]);
//          }
//        }
//      }
//    }
//  }
//  int Question(int x1, int y1, int x2, int y2) {
//    int k = log_[x2 - x1 + 1];
//    int t = log_[y2 - y1 + 1];
//    // ????????? ?? ????????
//    int ans1 = st_[x1][y1][k][t];
//    int ans2 = st_[x2 - static_cast<int>(std::pow(2, k)) + 1][y1][k][t];
//    int ans3 = st_[x1][y2 - static_cast<int>(std::pow(2, t)) + 1][k][t];
//    int ans4 =
//        st_[x2 - static_cast<int>(std::pow(2, k)) + 1][y2 - static_cast<int>(std::pow(2, t)) + 1][k][t];
//    return std::min(std::min(ans1, ans2), std::min(ans3, ans4));
//  }
//};
//
//int main() {
//  std::ios_base::sync_with_stdio(false);
//  std::cin.tie(nullptr);
//  std::cout.tie(nullptr);
//  int n = 0;
//  int m = 0;
//  int q = 0;
//  int x1 = 0;
//  int y1 = 0;
//  int x2 = 0;
//  int y2 = 0;
//  std::cin >> n >> m;
//  SparceTable2D st(n, m);
//  std::cin >> q;
//  for (int i = 0; i < q; ++i) {
//    std::cin >> x1 >> y1 >> x2 >> y2;
//    std::cout << st.Question(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << '\n';
//  }
//}