//#include <iostream>
//#include <vector>
//struct Edge {
//  int v_ = 0;
//  int flow_ = 0;
//  int capacity_ = 0;
//
//  Edge(int v, int flow, int capacity) : v_(v), flow_(flow), capacity_(capacity) {
//  }
//
//  Edge(int v, int capacity) : v_(v), flow_(0), capacity_(capacity) {
//  }
//};
//
//class Graph {
//  int n_;
//  int m_;
//  std::vector<int> used_;
//  std::vector<Edge> edges_;
//  std::vector<std::vector<int>> adj_list_;
//  int inf_ = 1000000000;
//  int count_ = 1;
//
//  int Dfs(int v, int min_cap) {
//    if (v == n_ - 1) {
//      return min_cap;
//    }
//    used_[v] = count_;
//    for (auto u : adj_list_[v]) {
//      if (used_[edges_[u].v_] == count_ || edges_[u].capacity_  == edges_[u].flow_) {
//        continue;
//      }
//      int f = Dfs(edges_[u].v_, std::min(min_cap, edges_[u].capacity_ - edges_[u].flow_));
//      if (f != 0) {
//        edges_[u].flow_ += f;
//        edges_[u ^ 1].flow_ -= f;
//        return f;
//      }
//    }
//    return 0;
//  }
//public:
//  Graph(int n, int m) : n_(n), m_(m) {
//    used_.resize(n_, false);
//    adj_list_.resize(n_);
//  }
//
//  void ReadGraph() {
//    int v = 0;
//    int u = 0;
//    int capacity = 0;
//    for (int i = 0; i < m_; ++i) {
//      std::cin >> v >> u >> capacity;
//      --v;
//      --u;
//      Edge edge = Edge(u, capacity);
//      adj_list_[v].emplace_back(edges_.size());
//      edges_.emplace_back(edge);
//      edge = Edge(v, 0);
//      adj_list_[u].emplace_back(edges_.size());
//      edges_.emplace_back(edge);
//    }
//  }
//
//  int MaxFlow() {
//    int f = 0;
//    while (Dfs(0, inf_)) {
//      ++count_;
//    }
//    for (auto u : adj_list_[0]) {
//      f += edges_[u].flow_;
//    }
//    return f;
//  }
//};
//
//int main() {
//  int n = 0;
//  int m = 0;
//  std::cin >> n >> m;
//  Graph graph = Graph(n, m);
//  graph.ReadGraph();
//  std::cout << graph.MaxFlow();
//}