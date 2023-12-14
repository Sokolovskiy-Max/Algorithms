//#include <iostream>
//#include <vector>
//
//struct Edge {
//  int v_ = 0;
//  int u_ = 0;
//  int w_ = 0;
//
//  Edge() = default;
//  Edge(int v, int u, int w) : v_(v), u_(u), w_(w) {
//  }
//};
//
//class DSU {
//  int n_, size_;
//  std::vector<int> parent_;
//  std::vector<int> rank_;
//
// public:
//  explicit DSU(int n) : n_(n), size_(n) {
//    rank_.resize(n_, 0);
//    parent_.resize(n);
//    for (int i = 0; i < n; ++i) {
//      parent_[i] = i;
//    }
//  }
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
//  bool AddEdge(int u, int v) {
//    Union(u, v);
//    return (size_ == 1);
//  }
//};
//
//int Krusc(int n, std::vector<Edge>& edges) {
//  int total_weight = 0;
//  DSU dsu = DSU(n);
//  for (Edge& edge : edges) {
//    if (dsu.FindSet(edge.v_) != dsu.FindSet(edge.u_)) {
//      dsu.Union(edge.v_, edge.u_);
//      total_weight += edge.w_;
//    }
//  }
//  return total_weight;
//}
//
//int main() {
//  int n = 0;
//  int m = 0;
//  int v = 0;
//  int u = 0;
//  int w = 0;
//  std::cin >> n >> m;
//  std::vector<Edge> edges(m);
//  for (int i = 0; i < m; ++i) {
//    std::cin >> v >> u >> w;
//    edges[i] = Edge(v - 1, u - 1, w);
//  }
//  std::cout << Krusc(n, edges);
//}