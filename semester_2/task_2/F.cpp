//#include <iostream>
//#include <vector>
//#include <queue>
//class Graph {
//  int vertex_;
//  int edge_;
//  std::vector<std::vector<std::pair<int, int>>> adj_list_;
//  std::queue<int> queue_;
//  std::vector<int> dist_;
//  int inf_;
//
// public:
//  Graph(int vertex, int edge) : vertex_(vertex), edge_(edge), inf_(1000000000) {
//    adj_list_.resize(vertex_ + 1);
//    dist_.resize(vertex_ + 1, inf_);
//  }
//
//  friend std::istream& operator>>(std::istream&, Graph&);
//
//  int Bfs01(int start, int end) {
//    while (!queue_.empty()) {
//      queue_.pop();
//    }
//    dist_.assign(vertex_ + 1, inf_);
//    queue_.push(start);
//    dist_[start] = 0;
//    while (!queue_.empty()) {
//      int v = queue_.front();
//      queue_.pop();
//      for (std::pair<int, int> u : adj_list_[v]) {
//        if (dist_[u.first] > dist_[v] + u.second) {
//          dist_[u.first] = dist_[v] + u.second;
//            queue_.push(u.first);
//        }
//      }
//    }
//    return dist_[end];
//  }
//};
//
//std::istream& operator>>(std::istream& is, Graph& graph) {
//  int v, u;
//  for (int i = 0; i < graph.edge_; ++i) {
//    is >> v >> u;
//    graph.adj_list_[v].emplace_back(std::make_pair(u, 0));
//    graph.adj_list_[u].emplace_back(std::make_pair(v, 1));
//  }
//  return is;
//}
//
//int main() {
//  int n, m;
//  int inf = 1000000000;
//  std::cin >> n >> m;
//  Graph graph = Graph(n, m);
//  std::cin >> graph;
//  int k, start, end, dist;
//  std::cin >> k;
//  for (int i = 0; i < k; ++i) {
//    std::cin >> start >> end;
//    dist = graph.Bfs01(start, end);
//    if (dist >= inf) {
//      std::cout << -1 << std::endl;
//    } else {
//      std::cout << dist << std::endl;
//    }
//  }
//}