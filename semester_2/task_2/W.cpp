//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//class Graph {
// public:
//  int vertex_;
//  int edge_;
//
// private:
//  std::vector<bool> used_;
//  std::vector<std::vector<std::pair<int, int>>> adj_list_;
//  std::vector<int> addend_;
//  std::vector<bool> sign_;
//  std::vector<int> correct_vertex_;
//
//  friend std::istream& operator>>(std::istream&, Graph&);
//
//  void Dfs(int v, bool sign, int addend) {
//    std::cout << v << std::endl;
//    used_[v] = true;
//    addend_[v] = addend;
//    sign_[v] = sign;
//    for (size_t i = 0; i < adj_list_[v].size(); ++i) {
//      if (!used_[adj_list_[v][i].first]) {
//        addend = adj_list_[v][i].second - addend_[v];
//        Dfs(adj_list_[v][i].first, !sign, addend);
//      }
//    }
//  }
//
//  void Regiction() {
//    
//    
//    Dfs(1, true, 0);
//    for (int i = 1; i <= vertex_; ++i) {
//      std::cout << addend_[i] << ' ';
//    }
//    std::cout << std::endl;
//    int plus_min = 1000000000;
//    int minous_min = 1000000000;
//    int x1 = 0;
//    int x2 = 0;
//    for (int i = 1; i <= vertex_; ++i) {
//      if (sign_[i] && addend_[i] < plus_min) {
//        plus_min = addend_[i];
//        x1 = 1 - addend_[i];
//      }
//      if (!sign_[i] && addend_[i] < minous_min) {
//        minous_min = addend_[i];
//        x2 = addend_[i] - 1;
//      }
//    }
//    bool correct_check = true;
//
//    for (int i = 1; i <= vertex_; ++i) {
//      correct_vertex_[i] = addend_[i] + x1 * (sign_[i] ? 1 : -1);
//      if (correct_vertex_[i] > vertex_ || correct_vertex_[i] < 1) {
//        correct_check = false;
//      }
//    }
//    for (int i = 1; i <= vertex_; ++i) {
//      std::cout << correct_vertex_[i] << ' ';
//    }
//    std::cout << std::endl;
//    for (int v = 1; v <= vertex_; ++v) {
//      for (std::pair<int, int> u : adj_list_[v]) {
//        if (correct_vertex_[v] + correct_vertex_[u.first] != u.second) {
//          correct_check = false;
//          break;
//        }
//      }
//    }
//    if (int(std::set<int>(correct_vertex_.begin() + 1, correct_vertex_.end()).size()) != vertex_) {
//      correct_check = false;
//    }
//    if (correct_check) {
//      return;
//    }
//    for (int i = 1; i <= vertex_; ++i) {
//      correct_vertex_[i] = addend_[i] + x2 * (sign_[i] ? 1 : -1);
//    }
//  }
//
// public:
//  explicit Graph(int vertex, int edge) : vertex_(vertex), edge_(edge) {
//    adj_list_.resize(vertex_ + 1);
//    used_.resize(vertex_ + 1, false);
//    addend_.resize(vertex_ + 1);
//    sign_.resize(vertex_ + 1);
//    correct_vertex_.resize(vertex_ + 1);
//  }
//
//  friend std::istream& operator>>(std::istream&, Graph&);
//
//  void ToString() {
//    Regiction();
//    for (int i = 1; i <= vertex_; ++i) {
//      std::cout << correct_vertex_[i] << ' ';
//    }
//  }
//};
//
//std::istream& operator>>(std::istream& is, Graph& graph) {
//  int v, u, w;
//  for (int i = 0; i < graph.edge_; ++i) {
//    is >> v >> u >> w;
//    graph.adj_list_[v].emplace_back(std::make_pair(u, w));
//    graph.adj_list_[u].emplace_back(std::make_pair(v, w));
//  }
//  return is;
//}
//int main() {
//  int n, m;
//  std::cin >> n >> m;
//  Graph graph = Graph(n, m);
//  std::cin >> graph;
//  graph.ToString();
//
//}