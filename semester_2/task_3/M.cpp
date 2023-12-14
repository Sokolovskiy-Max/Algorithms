//#include <iostream>
//#include <vector>
//#include <set>
//
//class Graph {
//  int n_;
//  std::vector<std::vector<int>> adj_matrix_;
//  std::vector<std::vector<std::vector<int>>> d_;
//
//  void FloydWarshall() {
//    d_[0] = adj_matrix_;
//    for (int k = 0; k < n_; ++k) {
//      for (int x = 0; x < n_; ++x) {
//        for (int y = 0; y < n_; ++y) {
//          d_[k + 1][x][y] = std::min(d_[k][x][y], d_[k][x][k] + d_[k][k][y]);
//        }
//      }
//    }
//  }
//
// public:
//  explicit Graph(int n) : n_(n) {
//    adj_matrix_.resize(n_);
//    for (int i = 0; i < n_; ++i) {
//      adj_matrix_[i].resize(n_);
//    }
//    d_.resize(n_ + 1);
//    for (int i = 0; i <= n_; ++i) {
//      d_[i].resize(n_);
//      for (int j = 0; j < n_; ++j) {
//        d_[i][j].resize(n_);
//      }
//    }
//  }
//
//  void ReadGrap() {
//    for (int i = 0; i < n_; ++i) {
//      for (int j = 0; j < n_; ++j) {
//        std::cin >> adj_matrix_[i][j];
//      }
//    }
//  }
//
//  void DistanceToString() {
//    FloydWarshall();
//    for (int i = 0; i < n_; ++i) {
//      for (int j = 0; j < n_; ++j) {
//        std::cout << d_[n_][i][j] << ' ';
//      }
//      std::cout << '\n';
//    }
//  }
//};
//
//int main() {
//  int n = 0;
//  std::cin >> n;
//  Graph graph = Graph(n);
//  graph.ReadGrap();
//  graph.DistanceToString();
//}