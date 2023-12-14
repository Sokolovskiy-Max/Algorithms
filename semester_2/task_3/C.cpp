//#include <iostream>
//#include <vector>
//#include <queue>
//
//struct Vertex {
//  int key_;
//  int weight_;
//  Vertex(int key, int weight) : key_(key), weight_(weight) {
//  }
//};
//
//bool operator<(const Vertex& v1, const Vertex& v2) {
//  return v1.weight_ > v2.weight_;
//}
//
//class Graph {
//  int n_, m_;
//  std::vector<std::vector<Vertex>> adj_list_;
//  std::vector<int> dist_;
//  std::vector<int> used_;
//  int inf_ = 10000000;
//
// public:
//  Graph(int n, int m) : n_(n), m_(m) {
//    adj_list_.resize(n_);
//    dist_.resize(n_, inf_);
//    used_.resize(n_, 0);
//    dist_[0] = 0;
//  }
//
//  friend std::istream& operator>>(std::istream&, Graph&);
//
//  int Prim() {
//    std::priority_queue<Vertex> queue;
//    queue.push(Vertex(0, 0));
//    int total_weight = 0;
//    while (!queue.empty()) {
//      Vertex v = queue.top();
//      queue.pop();
//      if (!used_[v.key_]) {
//        total_weight += v.weight_;
//        used_[v.key_] = true;
//        for (Vertex u : adj_list_[v.key_]) {
//          if (!used_[u.key_]) {
//            queue.push(u);
//          }
//        }
//      }
//    }
//    return total_weight;
//  }
//};
//
//std::istream& operator>>(std::istream& is, Graph& graph) {
//  int u = 0;
//  int v = 0;
//  int w = 0;
//  for (int i = 0; i < graph.m_; ++i) {
//    is >> u >> v >> w;
//    graph.adj_list_[u - 1].emplace_back(Vertex(v - 1, w));
//    graph.adj_list_[v - 1].emplace_back(Vertex(u - 1, w));
//  }
//  return is;
//}
//
//int main() {
//  int n = 0;
//  int m = 0;
//  std::cin >> n >> m;
//  Graph graph = Graph(n, m);
//  std::cin >> graph;
//  std::cout << graph.Prim();
//}
//
