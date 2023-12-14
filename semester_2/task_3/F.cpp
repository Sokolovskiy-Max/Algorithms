//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//bool Comp(std::pair<int, std::pair<int, int>>& p1, std::pair<int, std::pair<int, int>>& p2) {
//  return p1.first < p2.first;
//}
//
//class Graph {
//  int n_;
//  std::vector<std::pair<int, std::pair<int, int>>> edges_;
//
// public:
//  explicit Graph(int n) : n_(n) {
//  }
//
//  void ReadGrap() {
//    int w = 0;
//    for (int i = 0; i < n_; ++i) {
//      for (int j = 0; j < n_; ++j) {
//        std::cin >> w;
//        if (i > j) {
//          edges_.push_back({w, {i, j}});
//        }
//      }
//    }
//    for (int i = 0; i < n_; ++i) {
//      std::cin >> w;
//      edges_.push_back({w, {i, n_}});
//    }
//  }
//
//  int MinCost() {
//    int min_cost = 0;
//    sort(edges_.begin(), edges_.end(), Comp);
//    std::vector<int> parent(n_ + 1);
//    for (int i = 0; i <= n_; ++i) {
//      parent[i] = i;
//    }
//    for (auto i : edges_) {
//      if (parent[i.second.second] != parent[i.second.first]) {
//        min_cost += i.first;
//        int cur_p = parent[i.second.first];
//        for (int j = 0; j <= n_; ++j) {
//          if (parent[j] == cur_p) {
//            parent[j] = parent[i.second.second];
//          }
//        }
//      }
//    }
//    return min_cost;
//  }
//};
//
//int main() {
//  int n = 0;
//  std::cin >> n;
//  Graph graph = Graph(n);
//  graph.ReadGrap();
//  std::cout << graph.MinCost();
//  return 0;
//}