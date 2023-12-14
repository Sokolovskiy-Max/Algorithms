//#include <iostream>
//#include <vector>
//#include <set>
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
//  std::vector<std::vector<std::pair<int, int>>> adj_list_;
//  std::vector<std::vector<int>> dist_;
//  std::vector<int> potential_;
//  std::vector<Edge> edges_;
//  int inf_ = 2009000999;
//
//  bool Relax(Edge edge) {
//    if (potential_[edge.u_] > potential_[edge.v_] + edge.w_) {
//      potential_[edge.u_] = potential_[edge.v_] + edge.w_;
//      return true;
//    }
//    return false;
//  }
//
//  void BellmanFord(int s) {
//    potential_[s] = 0;
//    for (int i = 0; i < n_ - 1; ++i) {
//      for (Edge edge : edges_) {
//        Relax(edge);
//      }
//    }
//  }
//
//
//  void Dijkstra(int s) {
//    dist_[s][s] = 0;
//    std::set<std::pair<int, int>> heap;
//    heap.insert({dist_[s][s],s});
//    while (!heap.empty()) {
//      int v = heap.begin()->second;
//      heap.erase(heap.begin());
//      for (auto u : adj_list_[v]) {
//        if (u.first != n_ && dist_[s][v] + u.second < dist_[s][u.first]) {
//          heap.erase({dist_[s][u.first], u.first});
//          dist_[s][u.first] = dist_[s][v] + u.second;
//          heap.insert({dist_[s][u.first], u.first});
//        }
//      }
//    }
//  }
//
//  void Djonson() {
//    BellmanFord(n_);
//    for (int v = 0; v < n_; ++v) {
//      for (auto u : adj_list_[v]) {
//        u.second += (potential_[v] - potential_[u.first]);
//      }
//    }
//    for (int s = 0; s < n_; ++s) {
//      Dijkstra(s);
//    }
//  }
// public:
//  explicit Graph(int n, int m) : n_(n), m_(m) {
//    potential_.resize(n_ + 1);
//    dist_.resize(n_);
//    for (int i = 0; i < n_; ++i) {
//      dist_[i].resize(n_, inf_);
//    }
//    adj_list_.resize(n_ + 1);
//  }
//
//  void ReadGrap() {
//    int w = 0;
//    int v = 0;
//    int u = 0;
//    for (int i = 0; i < m_; ++i) {
//      std::cin >> v >> u >> w;
//      adj_list_[v].push_back({u, w});
//      Edge edge = Edge(v, u, w);
//      edges_.emplace_back(edge);
//    }
//    for (int i = 0; i < n_; ++i) {
//      adj_list_[n_].push_back({i , 0});
//      Edge edge = Edge(n_, i, 0);
//      edges_.emplace_back(edge);
//    }
//  }
//
//  int MaxDistToString() {
//    Djonson();
//    int max_dist = -inf_;
//    for (int i = 0; i < n_; ++i) {
//      for (int j = 0; j < n_; ++j) {
//        if (i != j && dist_[i][j] != inf_) {
//          max_dist = std::max(max_dist, dist_[i][j]);
//        }
//      }
//    }
//    return max_dist;
//  }
//};
//
//int main() {
//  int n = 0;
//  int m = 0;
//  std::cin >> n >> m;
//  Graph graph = Graph(n, m);
//  graph.ReadGrap();
//  std::cout << graph.MaxDistToString();
//}
