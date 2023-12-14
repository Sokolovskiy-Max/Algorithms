//#include <iostream>
//#include <vector>
//#include <algorithm>
//struct Edge {
//  int v_ = 0;
//  int u_ = 0;
//  int w_ = 0;
//
//  Edge() = default;
//  Edge(int v, int u, int w) : v_(v), u_(u), w_(w) {
//  }
//};
//
//class Graph {
//  int n_;
//  int m_;
//  std::vector<Edge> edges_;
//  std::vector<int> dist_;
//  std::vector<int> prev_;
//  int inf_ = 100000000;
//  Edge rel_edge_;
//
//  inline bool Relax(Edge edge) {
//    int d = dist_[edge.v_] + edge.w_;
//    if (d != inf_ && dist_[edge.u_] > d) {
//      dist_[edge.u_] = d;
//      prev_[edge.u_] = edge.v_;
//      return true;
//    }
//    return false;
//  }
//
// public:
//  explicit Graph(int n) : n_(n) {
//  }
//
//  void ReadGrap() {
//    int w = 0;
//    for (int i = 0; i < n_; ++i) {
//      for (int j = 0; j < n_; ++j) {
//        std::cin >> w;
//        if (w != 100000) {
//          Edge edge = Edge(i, j, w);
//          edges_.emplace_back(edge);
//        }
//      }
//    }
//    m_ = static_cast<int>(edges_.size());
//  }
//
//  bool HasNegativeCycle(int s) {
//    dist_.resize(n_, inf_);
//    dist_[s] = 0;
//    prev_.resize(n_, -1);
//    for (int i = 0; i < n_ - 1; ++i) {
//      for (auto edge : edges_) {
//        int d = dist_[edge.v_] + edge.w_;
//        if (d != inf_ && dist_[edge.u_] > d) {
//          dist_[edge.u_] = d;
//          prev_[edge.u_] = edge.v_;
//        }
//      }
//    }
//    for (auto edge : edges_) {
//      if (Relax(edge)) {
//        rel_edge_ = edge;
//        return true;
//      }
//    }
//    return false;
//  }
//
//  void ToString(int s) {
//    if (!HasNegativeCycle(s)) {
//      std::cout << "NO";
//    } else {
//      std::cout << "YES\n";
//      std::vector<int> cycle;
//      int v = rel_edge_.v_;
//      for (int i = 0; i < n_; ++i) {
//        v = prev_[v];
//      }
//      cycle.emplace_back(v);
//      for (int i = prev_[v]; i != v; i = prev_[i]) {
//        cycle.emplace_back(i);
//      }
//      cycle.emplace_back(v);
//      size_t size = cycle.size();
//      std::cout << size << '\n';
//      std::reverse(cycle.begin(), cycle.end());
//      for (int i : cycle) {
//        std::cout << i + 1 << ' ';
//      }
//    }
//  }
//};
//
//int main() {
//  std::ios_base::sync_with_stdio(false);
//  std::cin.tie(nullptr);
//  std::cout.tie(nullptr);
//  int n = 0;
//  std::cin >> n;
//  Graph graph = Graph(n);
//  graph.ReadGrap();
//  graph.ToString(0);
//}