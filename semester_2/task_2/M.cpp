//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//class Graph {
//public:
//  int vertex_, edges_;
//  std::vector<std::vector<int>> adj_list_;
//
//private:
//  std::vector<bool> used_;
//  std::vector<int> time_in_;
//  std::vector<int> time_up_;
//  std::set<int> articulation_points_;
//
//public:
//  Graph(int vertex, int edges) : vertex_(vertex), edges_(edges) {
//    adj_list_.resize(vertex_ + 1);
//  }
//
//  friend std::istream& operator>>(std::istream&, Graph&);
//
//  void ToString() {
//    used_.assign(vertex_ + 1, false);
//    time_in_.assign(vertex_ + 1, 0);
//    time_up_.assign(vertex_ + 1, 0);
//    for (int i = 1; i < vertex_; ++i) {
//      if (!used_[i]) {
//        this->DfsVisit(i, -1);
//      }
//    }
//    std::cout << articulation_points_.size() << std::endl;
//    for (int i : articulation_points_) {
//      std::cout << i << std::endl;
//    }
//  }
//
//private:
//  void DfsVisit(int v, int parent) {
//    time_up_[v] = (parent != -1 ? time_in_[parent] + 1 : 0);
//    time_in_[v] = (parent != -1 ? time_in_[parent] + 1 : 0);
//    used_[v] = true;
//    int n_children = 0;
//    for (int u : adj_list_[v]) {
//      if (u == parent) {
//        continue;
//      }
//      if (used_[u]) {
//        time_up_[v] = std::min(time_up_[v], time_in_[u]);
//      } else {
//        DfsVisit(u, v);
//        time_up_[v] = std::min(time_up_[v], time_up_[u]);
//        if (parent != -1 && time_up_[u] >= time_in_[v]) {
//          articulation_points_.emplace(v);
//        }
//        ++n_children;
//      }
//    }
//    if (parent == -1 && n_children > 1) {
//      articulation_points_.emplace(v);
//    }
//  }
//};
//
//std::istream& operator>>(std::istream& is, Graph& graph) {
//  int u, v;
//  for (int i = 0; i < graph.edges_; ++i) {
//    is >> u >> v;
//    graph.adj_list_[u].push_back(v);
//    graph.adj_list_[v].push_back(u);
//  }
//  return is;
//}
//
//int main() {
//  int n, m;
//  std::cin >> n >> m;
//  Graph graph = Graph(n, m);
//  std::cin >> graph;
//  graph.ToString();
//}