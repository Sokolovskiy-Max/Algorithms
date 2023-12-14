//#include <iostream>
//#include <vector>
//class DSU {
//  int n_;
//  std::vector<std::pair<int, int>> parent_;
//  std::vector<int> rank_;
//
//  int FindSet(int x) {
//    if (parent_[x].first == x) {
//      return x;
//    }
//    parent_[x].first = FindSet(parent_[x].first);
//    return parent_[x].first;
//  }
//
//  void Union(int x, int y, int w) {
//    x = FindSet(x);
//    y = FindSet(y);
//    if (x == y) {
//      parent_[x].second += w;
//      return;
//    }
//    if (rank_[x] < rank_[y]) {
//      parent_[y].second = parent_[x].second + parent_[y].second + w;
//      parent_[x].first = y;
//    } else if (rank_[x] > rank_[y]) {
//      parent_[x].second = parent_[x].second + parent_[y].second + w;
//      parent_[y].first = x;
//    } else {
//      parent_[y].second = parent_[x].second + parent_[y].second + w;
//      parent_[x].first = y;
//      ++rank_[x];
//    }
//  }
//
//public:
//  explicit DSU(int n) : n_(n) {
//    rank_.resize(n_, 0);
//    parent_.resize(n);
//    for (int i = 0; i < n; ++i) {
//      parent_[i] = std::make_pair(i, 0);
//    }
//  }
//
//  void AddEdge(int u, int v, int w) {
//    Union(u, v, w);
//  }
//
//  int GetWeight(int v) {
//    return parent_[FindSet(v)].second;
//  }
//};
//
//int main() {
//  int n = 0;
//  int m = 0;
//  int type = 0;
//  int u = 0;
//  int v = 0;
//  int w = 0;
//  std::cin >> n >> m;
//  DSU dsu = DSU(n);
//  for (int i = 0; i < m; ++i) {
//    std::cin >> type;
//    if (type == 1) {
//      std::cin >> u >> v >> w;
//      dsu.AddEdge(u - 1, v - 1, w);
//    } else {
//      std::cin >> v;
//      std::cout << dsu.GetWeight(v - 1) << std::endl;
//    }
//  }
//}