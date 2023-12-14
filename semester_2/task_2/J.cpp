//#include <iostream>
//#include <vector>
//
//class TopSortDfs {
//public:
//  int n_;
//  std::vector<std::vector<int>> graph_;
//  std::vector<int> color_;
//  std::vector<std::vector<int>> all_groups_;
//  std::vector<int> top_sorted_;
//  TopSortDfs(int n, std::vector<std::vector<int>>& graph, std::vector<int>& color, std::vector<int>& top_sorted)
//      : n_(n), graph_(graph), color_(color), top_sorted_(top_sorted) {
//  }
//  bool PossibleToSort(int vertex) {
//    color_[vertex] = 1;
//    for (int neighbour : graph_[vertex]) {
//      if (color_[neighbour] == 1) {
//        return false;
//      }
//      if (color_[neighbour] == 0) {
//        if (!PossibleToSort(neighbour)) {
//          return false;
//        }
//      }
//    }
//    color_[vertex] = 2;
//    top_sorted_.emplace_back(vertex);
//    return true;
//  }
//  void TopSort() {
//    for (int vertex = 1; vertex <= n_; ++vertex) {
//      if (color_[vertex] == 0) {
//        if (!PossibleToSort(vertex)) {
//          top_sorted_.emplace_back(-1);
//        }
//      }
//    }
//  }
//};
//
//int main() {
//  int n, m;
//  std::cin >> n >> m;
//  std::vector<std::vector<int>> graph(n + 1, std::vector<int>());
//  int vertex1, vertex2;
//  for (int i = 0; i < m; ++i) {
//    std::cin >> vertex1 >> vertex2;
//    graph[vertex1].emplace_back(vertex2);
//  }
//  std::vector<int> color(n + 1, 0);
//  std::vector<int> top_sorted;
//  TopSortDfs tsd = TopSortDfs(n, graph, color, top_sorted);
//  tsd.TopSort();
//  for (int i = 0; i < n; ++i) {
//    if (tsd.top_sorted_[i] == -1) {
//      std::cout << -1;
//      return 0;
//    }
//  }
//  for (int i = n - 1; i >= 0; --i) {
//    std::cout << tsd.top_sorted_[i] << ' ';
//  }
//  return 0;
//}