//#include <iostream>
//#include <vector>
//
//struct Edge {
//  int64_t v_ = 0;
//  int64_t u_ = 0;
//  int64_t w_ = 1000000010;
//
//  Edge() = default;
//  Edge(int64_t v, int64_t u, int64_t w) : v_(v), u_(u), w_(w) {
//  }
//};
//
//class DSU {
//  int64_t n_, size_;
//  std::vector<int64_t> parent_;
//  std::vector<int64_t> rank_;
//
// public:
//  explicit DSU(int64_t n) : n_(n), size_(n) {
//    rank_.resize(n_, 0);
//    parent_.resize(n);
//    for (int64_t i = 0; i < n; ++i) {
//      parent_[i] = i;
//    }
//  }
//
//  int64_t FindSet(int64_t x) {
//    if (parent_[x] == x) {
//      return x;
//    }
//    parent_[x] = FindSet(parent_[x]);
//    return parent_[x];
//  }
//
//  void Union(int64_t x, int64_t y) {
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
//  bool AddEdge(int64_t u, int64_t v) {
//    Union(u, v);
//    return (size_ == 1);
//  }
//
//  int64_t SetCount() {
//    return size_;
//  }
//};
//
//int64_t Boruvka(int64_t n, std::vector<Edge>& edges) {
//  int64_t total_weight = 0;
//  DSU dsu = DSU(n);
//  for (Edge& edge : edges) {
//    if (dsu.FindSet(edge.v_) != dsu.FindSet(edge.u_)) {
//      dsu.Union(edge.v_, edge.u_);
//      total_weight += edge.w_;
//    }
//  }
//  return total_weight;
//}
//int64_t Boruvka(int64_t n, int64_t m, std::vector<Edge>& edges) {
//  int64_t total_weight = 0;
//  DSU dsu = DSU(n);
//  while (dsu.SetCount() > 1) {
//    std::vector<Edge> min_edge;
//    min_edge.resize(m);
//    for (Edge edge : edges) {
//      int64_t comp_v = dsu.FindSet(edge.v_);
//      int64_t comp_u = dsu.FindSet(edge.u_);
//      if (comp_u != comp_v) {
//        if (edge.w_ < min_edge[comp_v].w_) {
//          min_edge[comp_v] = edge;
//          if (edge.w_ < min_edge[comp_u].w_) {
//            min_edge[comp_u] = edge;
//          }
//        }
//      }
//    }
//    for (Edge edge : min_edge) {
//      if (edge.w_ == 1000000010) {
//        continue;
//      }
//      total_weight += edge.w_;
//      dsu.Union(edge.v_, edge.u_);
//    }
//  }
//  return total_weight;
//}
//
//int main() {
//  int64_t n = 0;
//  int64_t m = 0;
//  int64_t v = 0;
//  int64_t u = 0;
//  int64_t w = 0;
//  std::cin >> n >> m;
//  std::vector<Edge> edges(m);
//  for (int64_t i = 0; i < m; ++i) {
//    std::cin >> v >> u >> w;
//    edges[i] = Edge(v - 1, u - 1, w);
//  }
//  std::cout << Boruvka(n, edges);
//}