//#include <iostream>
//#include <vector>
//#include <queue>
//
//class Graph {
//  int n_;
//  std::vector<std::vector<int>> adj_matrix_;
//  std::vector<bool> used_;
//  std::vector<int> dist_;
//  int inf_ = 100000000;
//
//  void Dijkstra(int s) {
//    dist_[s] = 0;
//    std::priority_queue<std::pair<int, int>> heap;
//    heap.push({0, s});
//    while (!heap.empty()) {
//      int v = heap.top().second;
//      int dist = -heap.top().first;  // чтобы не переопределять сравнение 
//      heap.pop();
//      if (dist > dist_[v]) {
//        continue; 
//      }
//      for (int i = 0; i < n_; ++i) {
//        if (adj_matrix_[v][i] != -1 && i != v) {
//          if (dist_[v] + adj_matrix_[v][i] < dist_[i]) {
//            dist_[i] = dist_[v] + adj_matrix_[v][i];
//            heap.push({-dist_[i], i});
//          }
//        }
//      }
//    }
//  }
//
//public:
//  explicit Graph(int n) : n_(n) {
//    dist_.resize(n_, inf_);
//    adj_matrix_.resize(n_);
//    for (int i = 0; i < n_; ++i) {
//      adj_matrix_[i].resize(n);
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
//  void DistanceToString(int s, int t) {
//    Dijkstra(s);
//    if (dist_[t] >= inf_) {
//      std::cout << -1;
//    } else {
//      std::cout << dist_[t];
//    }
//  }
//};
//
//int main() {
//  std::ios_base::sync_with_stdio(false);
//  std::cin.tie(nullptr);
//  std::cout.tie(nullptr);
//  int n = 0;
//  int s = 0;
//  int t = 0;
//  std::cin >> n >> s >> t;
//  Graph graph = Graph(n);
//  graph.ReadGrap();
//  graph.DistanceToString(s - 1, t - 1);
//}
