//#include <iostream>
//#include <vector>
//class Graph {
//  int n_;
//  int m_;
//  std::vector<std::vector<int>> adj_list_;
//  std::vector<int> color_;
//
// public:
//  std::vector<int> parent_;
//
//  Graph(int n, int m) : n_(n), m_(m) {
//    color_.resize(n_ + 1, 0);
//    parent_.resize(n_ + 1, -1);
//    adj_list_.resize(n_ + 1);
//  }
//
//  bool Dfs(int vertex, int& cycle_start, int& cycle_end) {
//    color_[vertex] = 1;
//    for (size_t i = 0; i < adj_list_[vertex].size(); ++i) {
//      int neighbour = adj_list_[vertex][i];
//      if (color_[neighbour] == 0) {
//        parent_[neighbour] = vertex;
//        if (Dfs(neighbour, cycle_start, cycle_end)) {
//          return true;
//        }
//      } else if (color_[neighbour] == 1) {
//        cycle_end = vertex;
//        cycle_start = neighbour;
//        return true;
//      }
//    }
//    color_[vertex] = 2;
//    return false;
//  }
//
//  friend std::istream& operator>>(std::istream&, Graph&);
//};
//
//std::istream& operator>>(std::istream& is, Graph& graph) {
//  int v, u;
//  for (int i = 0; i < graph.m_; ++i) {
//    is >> v >> u;
//    graph.adj_list_[v].emplace_back(u);
//  }
//  return is;
//}
//
//int main() {
//  int n, m;
//  std::cin >> n >> m;
//  Graph graph = Graph(n, m);
//  int cycle_start, cycle_end;
//  std::cin >> graph;
//  cycle_start = -1;
//  for (int i = 1; i < n + 1; ++i) {
//    if (graph.Dfs(i, cycle_start, cycle_end)) {
//      break;
//    }
//  }
//  if (cycle_start == -1) {
//    std::cout << "NO" << std::endl;
//  } else {
//    std::cout << "YES" << std::endl;
//    std::vector<int> cycle;
//    for (int i = cycle_end; i != cycle_start; i = graph.parent_[i]) {
//      cycle.push_back(i);
//    }
//    cycle.push_back(cycle_start);
//    for (size_t i = cycle.size() - 1; i > 0; --i) {
//      std::cout << cycle[i] << ' ';
//    }
//    std::cout << cycle[0] << ' ';
//  }
//}