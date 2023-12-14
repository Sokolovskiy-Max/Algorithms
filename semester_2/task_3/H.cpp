//#include <iostream>
//#include <vector>
//
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
//  int inf_ = 1000000000;
//
//  bool Relax(Edge edge, std::vector<int>& tmp_dist) {
//    if (dist_[edge.u_] > dist_[edge.v_] + edge.w_) {
//      tmp_dist[edge.u_] = dist_[edge.v_] + edge.w_;
//      prev_[edge.u_] = edge.v_;
//      return true;
//    }
//    return false;
//  }
//
//  void BellmanFord(int s, int k) {
//    dist_.resize(n_, inf_);
//    dist_[s] = 0;
//    prev_.resize(n_, -1);
//    for (int i = 0; i < k; ++i) {
//      std::vector<int> tmp_dist(n_, -1);
//      for (Edge edge : edges_) {
//        Relax(edge, tmp_dist);
//      }
//      for (int i = 0; i < n_; ++i) {
//        if (tmp_dist[i] != -1) {
//          dist_[i] = tmp_dist[i];
//        }
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
//  void PriceToString(int s, int f, int k) {
//    BellmanFord(s, k);
//    if (dist_[f] < inf_) {
//      std::cout << dist_[f];
//    } else {
//      std::cout << -1;
//    }
//  }
//};
//
//int main() {
//  int n = 0;
//  int m = 0;
//  int k = 0;
//  int s = 0;
//  int f = 0;
//  std::cin >> n >> m >> k >> s >> f;
//  Graph graph = Graph(n, m);
//  graph.ReadGrap();
//  graph.PriceToString(s - 1, f - 1, k);
//}
