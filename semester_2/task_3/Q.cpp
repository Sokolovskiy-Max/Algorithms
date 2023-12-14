//#include <algorithm>
//#include <iostream>
//#include <limits>
//#include <queue>
//#include <vector>
//
//
//struct Edge {
//  int v_;
//  int u_;
//  int flow_;
//  int capacity_;
//
//  Edge(int from, int to, int capacity)
//    : v_(from), u_(to), flow_(0), capacity_(capacity) {
//  }
//  Edge(int from, int to, int flow, int capacity)
//    : v_(from), u_(to), flow_(flow), capacity_(capacity) {
//  }
//};
//
//class Graph {
//  int n_;
//  int m_;
//  std::vector<Edge> edges_;
//  std::vector<std::vector<int>> adj_list_;
//  std::vector<int> dist_;
//  std::vector<int> ptr_;
//  int inf_ = 10000000;
//
//  bool Bfs(int start, int end) {
//    dist_.assign(adj_list_.size(), inf_);
//    ptr_.assign(adj_list_.size(), 0);
//    std::queue<int> queue;
//    dist_[start] = 0;
//    queue.push(start);
//    while (!queue.empty() and dist_[end] == inf_) {
//      int current = queue.front();
//      queue.pop();
//      for (int j = 0; j < adj_list_[current].size(); ++j) {
//        int edge_id = adj_list_[current][j];
//        if ((dist_[edges_[edge_id].u_] == inf_) &&
//          (edges_[edge_id].v_ < edges_[edge_id].capacity_)) {
//          queue.push(edges_[edge_id].u_);
//          dist_[edges_[edge_id].u_] = dist_[edges_[edge_id].v_] + 1;
//        }
//      }
//    }
//    return (dist_[end] != inf_);
//  }
//
//  int Dfs(int vertex, int u, int curr_flow) {
//    if (vertex == u) {
//      return curr_flow;
//    }
//    while (ptr_[vertex] < adj_list_[vertex].size()) {
//      int edge_id = adj_list_[vertex][ptr_[vertex]];
//      if ((dist_[edges_[edge_id].v_] + 1 != dist_[edges_[edge_id].u_]) or
//        (edges_[edge_id].flow_ == edges_[edge_id].capacity_)) {
//        ptr_[vertex] += 1;
//        continue;
//      }
//      int taken = Dfs(
//        edges_[edge_id].u_, u,
//        std::min(curr_flow, edges_[edge_id].capacity_ - edges_[edge_id].flow_));
//      if (taken == 0) {
//        ptr_[vertex] += 1;
//        continue;
//      }
//      edges_[edge_id].flow_ += taken;
//      edges_[edge_id ^ 1].flow_ -= taken;
//      return taken;
//    }
//    return 0;
//  }
//
//  int DinicAlgo() {
//    int flow = 0;
//    while (Bfs(0, n_ - 1)) {
//      int delta = 0;
//      do {
//        delta = Dfs(0, n_ - 1, inf_);
//        flow += delta;
//      } while (delta > 0);
//    }
//    return flow;
//  }
//
//public:
//  explicit Graph(int n, int m) : n_(n), m_(m) {
//    adj_list_.resize(n_);
//  }
//
//  void ReadGraph() {
//    int v = 0;
//    int u = 0;
//    int cap = 0;
//    for (int j = 0; j < m_; ++j) {
//      std::cin >> v >> u >> cap;
//      --v;
//      --u;
//      Edge edge = Edge(v, u, cap);
//      adj_list_[v].emplace_back(edges_.size());
//      edges_.emplace_back(edge);
//      edge = Edge(u, v, 0);
//      adj_list_[u].emplace_back(edges_.size());
//      edges_.emplace_back(edge);
//    }
//  }
//
//  void MaxFlow() {
//    std::cout << DinicAlgo();
//  }
//};
//
//int main() {
//  int n = 0;
//  int m = 0;
//  std::cin >> n >> m;
//  Graph graph(n, m);
//  graph.ReadGraph();
//  graph.MaxFlow();
//}