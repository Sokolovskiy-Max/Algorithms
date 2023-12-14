//#include <iostream>
//#include <vector>
//
//struct Edge {
//  int64_t v_ = 0;
//  int64_t u_ = 0;
//  int64_t w_ = 0;
//
//  Edge() = default;
//  Edge(int64_t v, int64_t u, int64_t w) : v_(v), u_(u), w_(w) {
//  }
//};
//
//class Graph {
//  int n_;
//  int m_;
//  std::vector<Edge> edges_;
//  std::vector<int> dist_;
//  std::vector<int> prev_;
//  int inf = 1000000000;
//
//  bool Relax(Edge edge) {
//    if (dist_[edge.u_] > dist_[edge.v_] + edge.w_) {
//      dist_[edge.u_] = dist_[edge.v_] + edge.w_;
//      prev_[edge.u_] = edge.v_;
//      return true;
//    }
//    return false;
//  }
//
//  void BellmanFord(int s) {
//    dist_.resize(n_, inf);
//    dist_[s] = 0;
//    prev_.resize(n_, -1);
//    for (int i = 0; i < n_ - 1; ++i) {
//      for (Edge edge : edges_) {
//        Relax(edge);
//      }
//    }
//  }
//
// public:
//  explicit Graph(int n, int m) : n_(n), m_(m) {
//    edges_.resize(m_);
//  }
//
//  void ReadGrap() {
//    int w = 0;
//    int v = 0;
//    int u = 0;
//    for (int i = 0; i < m_; ++i) {
//      std::cin >> v >> u >> w;
//      edges_[i] = Edge(v - 1, u - 1, w);
//    }
//  }
//
//  void DistanceToString(int s) {
//    BellmanFord(s);
//    for (int i = 0; i < n_; i++) {
//      if (dist_[i] >= 30000) {
//        std::cout << 30000 << ' ';
//      } else {
//        std::cout << dist_[i] << ' ';
//      }
//    }
//  }
//};
//
//int main() {
//  int n = 0;
//  int m = 0;
//  std::cin >> n >> m;
//  Graph graph = Graph(n, m);
//  graph.ReadGrap();
//  graph.DistanceToString(0);
//}
