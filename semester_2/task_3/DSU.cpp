//#include <iostream>
//#include <vector>
//#include <queue>
//class Graph {
//  int n_;
//  int m_;
//  std::vector<std::vector<int>> adj_list_;
//  std::vector<bool> used_;
//  std::vector<int> dist_;
//  int inf_ = 100000000;
//  Graph(int n, int m) : n_(n), m_(m) {
//    used_.resize(false, n_);
//    adj_list_.resize(n_);
//    dist_.resize(n_, inf_);
//  }
//  void ReadGraph() {
//    int u, int v;
//    std::cin >> v >> u;
//    --v;
//    --u;
//    for (int i = 0; i < m_; ++i) {
//      std::cin >> v >> u;
//      adj_list_[v].push_back(u);
//    }
//  }
//
//  int Bfs(int s) {
//    std::queue<int> queue;
//    queue.push(s);
//    dist_[s] = 0;
//    used_[s] = true;
//    while (!queue.empty()) {
//      int v = queue.front();
//      queue.pop();
//      for (auto u : adj_list_[v]) {
//        if (!used_[u]) {
//          used_[u] = true;
//          queue.push(u);
//          dist_[u] = dist_[v] + 1;
//
//        }
//      }
//    }
//  }
//};