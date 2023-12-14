//#include <iostream>
//#include <vector>
//
//class Graph {
//public:
//  int64_t vertex_;
//
//private:
//  std::vector<bool> used_;
//  std::vector<std::vector<std::pair<int64_t, bool>>> adj_list_;
//  std::vector<std::vector<int64_t>> tr_adj_list_;
//  std::vector<std::vector<int64_t>> not_orientation_adj_list_;
//  std::vector<int64_t> euler_cycle_;
//  std::vector<int64_t> count_;
//  int64_t min_vertex_;
//
//  void DfsEulerCycle(int64_t v) {
//    for (int64_t i = count_[v]; i < int64_t(adj_list_[v].size()); ++i) {
//      if (count_[v] >= int64_t(adj_list_[v].size())) {
//        break;
//      }
//      if (!adj_list_[v][i].second) {
//        adj_list_[v][i].second = true;
//        ++count_[v];
//        DfsEulerCycle(adj_list_[v][i].first);
//      }
//    }
//    euler_cycle_.emplace_back(v);
//  }
//
//  void Dfs(int64_t v) {
//    used_[v] = true;
//    for (int64_t u : not_orientation_adj_list_[v]) {
//      if (!used_[u]) {
//        Dfs(u);
//      }
//    }
//  }
//
//  bool CheckWeekAdjacent() {
//    if (min_vertex_ == 1000000000 || adj_list_[min_vertex_].empty()) {
//      return false;
//    }
//    Dfs(min_vertex_);
//    for (int64_t i = 1; i <= vertex_; ++i) {
//      if (!used_[i] && !adj_list_[i].empty()) {
//        return false;
//      }
//    }
//    for (int64_t i = 1; i <= vertex_; ++i) {
//      if (adj_list_[i].size() != tr_adj_list_[i].size()) {
//        std::cout << i << std::endl;
//        return false;
//      }
//    }
//    return true;
//  }
//
//public:
//  explicit Graph(int64_t vertex) : vertex_(vertex), min_vertex_(1000000000) {
//    adj_list_.resize(vertex_ + 1);
//    tr_adj_list_.resize(vertex_ + 1);
//    not_orientation_adj_list_.resize(vertex_ + 1);
//    used_.resize(vertex_ + 1, false);
//    count_.resize(vertex_ + 1, 0);
//  }
//
//  void ToString() {
//    if (!CheckWeekAdjacent()) {
//      std::cout << 0;
//      return;
//    }
//    DfsEulerCycle(min_vertex_);
//    int64_t size = euler_cycle_.size();
//    std::cout << size << ' ';
//    for (size_t i = 0; i < euler_cycle_.size(); ++i) {
//      std::cout << euler_cycle_[euler_cycle_.size() - i - 1] << ' ';
//    }
//  }
//  friend std::istream& operator>>(std::istream&, Graph&);
//};
//
//std::istream& operator>>(std::istream& is, Graph& graph) {
//  int64_t way, v1, v2;
//  is >> way;
//  is >> v1;
//  if (v1 < graph.min_vertex_) {
//    graph.min_vertex_ = v1;
//  }
//  for (int64_t i = 0; i < way; ++i) {
//    is >> v2;
//    if (v2 < graph.min_vertex_) {
//      graph.min_vertex_ = v2;
//    }
//    graph.adj_list_[v1].emplace_back(std::make_pair(v2, false));
//    graph.tr_adj_list_[v2].emplace_back(v1);
//    graph.not_orientation_adj_list_[v1].emplace_back(v2);
//    graph.not_orientation_adj_list_[v2].emplace_back(v1);
//    v1 = v2;
//  }
//  return is;
//}
//
//int main() {
//  int64_t path, n;
//  std::cin >> path >> n;
//  Graph graph = Graph(n);
//  for (int64_t i = 0; i < path; ++i) {
//    std::cin >> graph;
//  }
//  graph.ToString();
//}