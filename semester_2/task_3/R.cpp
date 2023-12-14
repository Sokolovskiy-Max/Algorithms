#include <iostream>
#include <vector>

struct Edge {
  int v_ = 0;
  int t_start_ = 0;
  int u_ = 0;
  int t_end_ = 0;

  Edge() = default;
  Edge(int v, int t_start, int u, int t_end) : v_(v), t_start_(t_start), u_(u), t_end_(t_end) {
  }
};

class Graph {
  int n_;
  int m_;
  std::vector<Edge> edges_;
  std::vector<int> dist_;
  int inf_ = 10000000;

  bool Relax(Edge edge) {
    if (dist_[edge.v_] <= edge.t_start_ && dist_[edge.u_] >= edge.t_end_) {
      dist_[edge.u_] = edge.t_end_;
      return true;
    }
    return false;
  }

  void BellmanFord(int start) {
    dist_.resize(n_, inf_);
    dist_[start] = 0;
    for (int i = 0; i < n_ + m_ - 1; ++i) {
      for (Edge edge : edges_) {
        Relax(edge);
      }
    }
  }

 public:
  explicit Graph(int n, int m) : n_(n), m_(m) {
    edges_.resize(m_);
  }

  void ReadGrap() {
    int v = 0;
    int t_start = 0;
    int u = 0;
    int t_end = 0;
    for (int i = 0; i < m_; ++i) {
      std::cin >> v >> t_start >> u >> t_end;
      edges_[i] = Edge(v - 1, t_start, u - 1, t_end);
    }
  }

  void DistanceToString(int start, int end) {
    BellmanFord(start);
    std::cout << dist_[end];
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  int start = 0;
  int end = 0;
  int m = 0;
  std::cin >> n;
  std::cin >> start >> end;
  std::cin >> m;
  --start;
  --end;
  Graph graph = Graph(n, m);
  graph.ReadGrap();
  graph.DistanceToString(start, end);
}
