//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//class Graph {
// public:
//  int vertex_, edges_;
//
// private:
//  int comp_tree_vertex_;
//  int time_;
//  std::vector<int> colors_;
//  std::vector<int> time_in_;
//  std::vector<int> time_up_;
//  std::set<int> briges_;
//  std::vector<int> comp_;
//  std::vector<std::vector<std::pair<int, int>>> adj_list_;
//  std::vector<std::vector<int>> comp_tree_adj_list_;
//  std::vector<std::pair<int, int>> edge_points_;
//
// public:
//  Graph(int vertex, int edges) : vertex_(vertex), edges_(edges) {
//    adj_list_.resize(vertex_ + 1);
//    comp_.resize(vertex_ + 1, -1);
//    time_ = 0;
//    comp_tree_vertex_ = 0;
//    edge_points_.resize(edges_);
//  }
//
//  friend std::istream& operator>>(std::istream&, Graph&);
//
//  int CountNewBonds() {
//    Briges();
//    FindComps();
//    int new_bonds = 0;
//    comp_tree_adj_list_.resize(comp_tree_vertex_ + 1);
//    for (int i : briges_) {
//      comp_tree_adj_list_[comp_[edge_points_[i - 1].first]].emplace_back(comp_[edge_points_[i - 1].second]);
//      comp_tree_adj_list_[comp_[edge_points_[i - 1].second]].emplace_back(comp_[edge_points_[i - 1].first]);
//    }
//    for (int i = 1; i < comp_tree_vertex_ + 1; ++i) {
//      if (comp_tree_adj_list_[i].size() == 1) {
//        ++new_bonds;
//      }
//      if (comp_tree_adj_list_[i].empty() && comp_tree_vertex_ != 1) {
//        new_bonds += 2;
//      }
//    }
//    return (new_bonds % 2 == 0 ? new_bonds / 2 : (new_bonds + 1) / 2);
//  }
//
// private:
//  void Briges() {
//    time_ = 0;
//    colors_.assign(vertex_ + 1, 0);
//    time_in_.assign(vertex_ + 1, 0);
//    time_up_.assign(vertex_ + 1, 0);
//    for (int i = 1; i < vertex_; ++i) {
//      if (colors_[i] == 0) {
//        this->DfsVisit(i);
//      }
//    }
//  }
//
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
//          for (int i = 0; i < int(adj_list_[v].size()); ++i) {
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
//
//  void Dfs(int v, int comp_num) {
//    colors_[v] = 1;
//    comp_[v] = comp_num;
//    for (size_t i = 0; i < adj_list_[v].size(); ++i) {
//      if (colors_[adj_list_[v][i].first] == 0 && briges_.find(adj_list_[v][i].second) == briges_.end()) {
//        Dfs(adj_list_[v][i].first, comp_num);
//      }
//    }
//  }
//
//  void FindComps() {
//    colors_.assign(vertex_ + 1, 0);
//    int comp_num = 1;
//    for (int i = 1; i < vertex_ + 1; ++i) {
//      if (colors_[i] == 0) {
//        Dfs(i, comp_num);
//        ++comp_num;
//      }
//    }
//    comp_tree_vertex_ = comp_num - 1;
//  }
//};
//
//std::istream& operator>>(std::istream& is, Graph& graph) {
//  int u, v;
//  for (int i = 0; i < graph.edges_; ++i) {
//    is >> u >> v;
//    graph.edge_points_[i] = std::make_pair(u, v);
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
//  std::cout << graph.CountNewBonds();
//}