//#include <iostream>
//#include <vector>
//#include <queue>
//const int inf_ = 1000000002;
//struct Edge {
//  int v_;
//  int u_;
//  int flow_;
//  int capacity_;
//
//  Edge(int v, int u, int flow, int capacity) : v_(v), u_(u), flow_(flow), capacity_(capacity) {
//  }
//
//  Edge(int v, int u, int capacity) : v_(v), u_(u), flow_(0), capacity_(capacity) {
//  }
//};
//
//struct Graph {
//  int n_;
//  int m_;
//  std::vector<bool> used_;
//  std::vector<std::vector<int>> adj_list_;
//  std::vector<Edge> edges_;
//  std::vector<int> parent_;
//  std::vector<int> flow_;
//
//  Graph(int n, int m) : n_(n), m_(m) {
//    adj_list_.resize(n_);
//    parent_.resize(n_);
//    used_.resize(n_, false);
//    flow_.resize(n_, inf_);
//  }
//
//  bool Bfs(int start, int end) {
//    std::queue<int> queue;
//    queue.push(start);
//    used_[start] = true;
//    flow_[start] = inf_;
//    while (!queue.empty()) {
//      int v = queue.front();
//      queue.pop();
//      if (v == end) {
//        while (v != start) {
//          int u = parent_[v];
//          edges_[u].flow_ += flow_[end];
//          edges_[u ^ 1].flow_ -= flow_[end];
//          v = edges_[u].v_;
//        }
//        return true;
//      }
//      for (int u : adj_list_[v]) {
//        if (edges_[u].flow_ < edges_[u].capacity_) {
//          if (!used_[u]) {
//            used_[edges_[u].u_] = true;
//            parent_[edges_[u].u_] = u;
//            flow_[edges_[u].u_]= std::min(flow_[v], edges_[edges_[u].u_].capacity_ - edges_[edges_[u].u_].flow_);
//            queue.push(edges_[u].u_);
//          }
//        }
//      }
//    }
//    return false;
//  }
//
//public:
//  void ReadGraph() {
//    int v = 0;
//    int u = 0;
//    int capacity = 0;
//    for (int i = 0; i < m_; ++i) {
//      std::cin >> v >> u >> capacity;
//      --v;
//      --u;
//      Edge edge = Edge(v, u, capacity);
//      adj_list_[v].emplace_back(edges_.size());
//      edges_.emplace_back(edge);
//      edge = Edge(u, v, 0);
//      adj_list_[u].emplace_back(edges_.size());
//      edges_.emplace_back(edge);
//    }
//  }
//  
//  int MaxFlow(int start, int end) {
//    bool all_paths = true;
//    while (all_paths) {
//      all_paths = Bfs(start, end);
//      used_.assign(n_, false);
//      flow_.assign(n_, inf_);
//    }
//    int f = 0;
//    for (auto u : adj_list_[start]) {
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
//  std::cout << graph.MaxFlow(0 , n - 1);
//  return 0;
//}