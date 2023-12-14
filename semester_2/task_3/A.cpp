//#include <iostream>
//#include <vector>
//class DSU {
//  int n_, size_;
//  std::vector<int> parent_;
//  std::vector<int> rank_;
//
//  int FindSet(int x) {
//    if (parent_[x] == x) {
//      return x;
//    }
//    parent_[x] = FindSet(parent_[x]);
//    return parent_[x];
//  }
//
//  void Union(int x, int y) {
//    x = FindSet(x);
//    y = FindSet(y);
//    if (x == y) {
//      return;
//    }
//    if (rank_[x] < rank_[y]) {
//      parent_[x] = y;
//    } else if (rank_[x] > rank_[y]) {
//      parent_[y] = x;
//    } else {
//      parent_[x] = y;
//      ++rank_[x];
//    }
//    --size_;
//  }
//
//public:
//  explicit DSU(int n) : n_(n), size_(n) {
//    rank_.resize(n_, 0);
//    parent_.resize(n);
//    for (int i = 0; i < n; ++i) {
//      parent_[i] = i;
//    }
//  }
//
//  bool AddEdge(int u, int v) {
//    Union(u, v);
//    return (size_ == 1);
//  }
//};
//
//int main() {
//  int n = 0;
//  int m = 0;
//  int u = 0;
//  int v = 0;
//  std::cin >> n >> m;
//  DSU dsu = DSU(n);
//  for (int i = 0; i < m; ++i) {
//    std::cin >> u >> v;
//    if (dsu.AddEdge(u, v)) {
//      std::cout << i + 1;
//      return 0;
//    }
//  }
//  std::cout << m;
//}