//#include <iostream>
//#include <vector>
//#include <queue>
//
//class Graph {
//  int vertex_, edges_;
//  std::vector<std::vector<int>> adj_list_;
//  std::vector<int> dist_;
//  std::vector<int> path_;
//
// public:
//  Graph(int vertex, int edges) : vertex_(vertex), edges_(edges) {
//    adj_list_.resize(vertex_ + 1);
//    dist_.resize(vertex_ + 1, -1);
//  }
//
//  friend std::istream& operator>>(std::istream&, Graph&);
//
//  bool Bfs(int start, int end) {
//    std::vector<int> dist(vertex_ + 1, vertex_);
//    dist[start] = 0;
//    std::vector<int> path(vertex_ + 1, -1);
//    std::queue<int> queue;
//    queue.push(start);
//    while (!queue.empty()) {
//      int current = queue.front();
//      queue.pop();
//      for (int neighbour : adj_list_[current]) {
//        if (dist[neighbour] > dist[current] + 1) {
//          path[neighbour] = current;
//          dist[neighbour] = dist[current] + 1;
//          queue.push(neighbour);
//        }
//      }
//    }
//    if (dist[end] == vertex_) {
//      return false;
//    }
//    while (end != -1) {
//      path_.push_back(end);
//      end = path[end];
//    }
//    return true;
//  }
//
//  void ToString(int start, int end) {
//    if (Bfs(start, end)) {
//      std::cout << path_.size() - 1 << std::endl;
//      for (int i = path_.size() - 1; i >= 0; --i) {
//        std::cout << path_[i] << ' ';
//      }
//    } else {
//      std::cout << -1;
//    }
//  }
//};
//
//std::istream& operator>>(std::istream& is, Graph& graph) {
//  int u, v;
//  for (int i = 0; i < graph.edges_; ++i) {
//    is >> u >> v;
//    graph.adj_list_[u].emplace_back(v);
//    graph.adj_list_[v].emplace_back(u);
//  }
//  return is;
//}
//
//int main() {
//  int start, end, vertices, edges;
//  std::cin >> vertices >> edges;
//  std::cin >> start >> end;
//  Graph graph = Graph(vertices, edges);
//  std::cin >> graph;
//  graph.ToString(start, end);
//  return 0;
//}