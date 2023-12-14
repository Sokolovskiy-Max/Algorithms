//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//class Graph {
//  int vertex_, edges_;
//  std::vector<std::vector<std::pair<int, int>>> adj_list_;
//  std::vector<int> dist_;
//  std::priority_queue<std::pair<int, int>> queue_;
//  int inf_ = 10000000000;
//
// public:
//  Graph(int vertex, int edges) : vertex_(vertex), edges_(edges) {
//    adj_list_.resize(vertex_ + 1);
//    dist_.resize(vertex_ + 1);
//    dist_.assign(vertex_ + 1, inf_);
//  }
//
//  friend std::istream& operator>>(std::istream&, Graph&);
//
//  int Dijkstra(int start, int end) {
//    dist_[start] = 0;
//    queue_.push(std::make_pair(start, 0));
//    while (!queue_.empty()) {
//      auto pair = queue_.top();
//      queue_.pop();
//      if (dist_[pair.first] < pair.second) {
//        continue;
//      }
//      for (auto u : adj_list_[pair.first]) {
//        int dst = pair.second + u.second;
//        if (dst < dist_[u.first]) {
//          dist_[u.first] = dst;
//          queue_.push(std::make_pair(u.first, dst));
//        }
//      }
//    }
//    if (dist_[end] >= inf_) {
//      return -1;
//    }
//    return dist_[end];
//  }
//};
//
//std::istream& operator>>(std::istream& is, Graph& graph) {
//  int u, v, w;
//  for (int i = 0; i < graph.edges_; ++i) {
//    is >> u >> v >> w;
//    graph.adj_list_[u].emplace_back(std::make_pair(v, w));
//  }
//  return is;
//}
//
//int main() {
//  int n, m;
//  std::cin >> n >> m;
//  int start, end;
//  std::cin >> start >> end;
//  Graph graph = Graph(n, m);
//  std::cin >> graph;
//  std::cout << graph.Dijkstra(start, end);
//}