//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//class Graph {
// public:
//  int vertex_, edges_;
//  std::vector<std::vector<std::pair<int, int>>> adj_list_;
//
// private:
//  int time_;
//  std::vector<int> colors_;
//  std::vector<int> time_in_;
//  std::vector<int> time_up_;
//  std::set<int> briges_;
//
// public:
//  Graph(int vertex, int edges) : vertex_(vertex), edges_(edges) {
//    adj_list_.resize(vertex_ + 1);
//    time_ = 0;
//  }
//
//  friend std::istream& operator>>(std::istream&, Graph&);
//
//  void ToString() {
//    time_ = 0;
//    colors_.assign(vertex_ + 1, 0);
//    time_in_.assign(vertex_ + 1, 0);
//    time_up_.assign(vertex_ + 1, 0);
//    for (int i = 1; i < vertex_; ++i) {
//      if (colors_[i] == 0) {
//        this->DfsVisit(i);
//      }
//    }
//    std::cout << briges_.size() << std::endl;
//    for (int i : briges_) {
//      std::cout << i << std::endl;
//    }
//  }
//
// private:
//  void DfsVisit(int v, int p = -1) {
//    time_up_[v] = time_in_[v] = ++time_;
//    colors_[v] = 1;
//    for (std::pair<int, int> u : adj_list_[v]) {
//      if (u.first == p) {
//        continue;
//      }
//      int u_bond_count = 0;
//      if (colors_[u.first] == 1) {
//        time_up_[v] = std::min(time_up_[v], time_in_[u.first]);
//      }
//      if (colors_[u.first] == 0) {
//        DfsVisit(u.first, v);
//        time_up_[v] = std::min(time_up_[v], time_up_[u.first]);
//        if (time_up_[u.first] > time_in_[v]) {
//          for (int i = 0; i < adj_list_[v].size(); ++i) {
//            if (adj_list_[v][i].first == u.first) {
//              ++u_bond_count;
//            }
//          }
//          if (u_bond_count == 1) {
//            briges_.emplace(u.second);
//          }
//        }
//      }
//    }
//    colors_[v] = 2;
//  }
//};
//
//std::istream& operator>>(std::istream& is, Graph& graph) {
//  int u, v;
//  for (int i = 0; i < graph.edges_; ++i) {
//    is >> u >> v;
//    graph.adj_list_[u].emplace_back(std::make_pair(v, i + 1));
//    graph.adj_list_[v].emplace_back(std::make_pair(u, i + 1));
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