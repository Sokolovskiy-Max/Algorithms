//#include <iostream>
//#include <vector>
//#include <set>
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
//  std::vector<std::vector<std::pair<int, int>>> adj_list_;
//  std::vector<bool> used_;
//  std::vector<int> dist_;
//  int inf_ = 2009000999;
//
//  void Dijkstra(int s) {
//    dist_[s] = 0;
//    std::set<std::pair<int, int>> heap;
//    heap.insert({ dist_[s],s });
//    while (!heap.empty()) {
//      int v = heap.begin()->second;
//      heap.erase(heap.begin());
//      for (auto u : adj_list_[v]) {
//        if (dist_[v] + u.second < dist_[u.first]) {
//          heap.erase({ dist_[u.first], u.first });
//          dist_[u.first] = dist_[v] + u.second;
//          heap.insert({ dist_[u.first], u.first });
//        }
//      }
//    }
//  }
//
//public:
//  explicit Graph(int n, int m) : n_(n), m_(m) {
//    dist_.resize(n_, inf_);
//    adj_list_.resize(n_);
//    used_.resize(n_, false);
//  }
//
//  void ReadGrap() {
//    int w = 0;
//    int v = 0;
//    int u = 0;
//    for (int i = 0; i < m_; ++i) {
//      std::cin >> v >> u >> w;
//      adj_list_[v].push_back({ u, w });
//    }
//  }
//
//  void DistanceToString(int s) {
//    Dijkstra(s);
//    for (int i = 0; i < n_; ++i) {
//      std::cout << dist_[i] << ' ';
//    }
//  }
//};
//
//int main() {
//  int k = 0;
//  int n = 0;
//  int m = 0;
//  int s = 0;
//  std::cin >> k;
//  for (int i = 0; i < k; ++i) {
//    std::cin >> n >> m;
//    Graph graph = Graph(n, m);
//    graph.ReadGrap();
//    std::cin >> s;
//    graph.DistanceToString(s);
//  }
//}
