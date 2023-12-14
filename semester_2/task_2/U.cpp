//#include <iostream>
//#include <vector>
//
//class Graph {
// public:
//  int vertex_;
//  int edge_;
//
// private:
//  std::vector<bool> used_;
//  std::vector<std::vector<int>> adj_list_;
//  std::vector<bool> type_;
//
//  void Dfs(int v) {
//    used_[v] = true;
//    for (size_t i = 0; i < adj_list_[v].size(); ++i) {
//      if (!used_[adj_list_[v][i]]) {
//        Dfs(adj_list_[v][i]);
//      }
//    }
//  }
//
// public:
//  explicit Graph(int vertex, int edge) : vertex_(vertex), edge_(edge) {
//    adj_list_.resize(vertex_ + 1);
//    type_.resize(vertex_ + 1, false);
//    used_.resize(vertex_ + 1, false);
//  }
//
//  friend std::istream& operator>>(std::istream&, Graph&);
//
//  bool AlkanCheck() {
//    Dfs(1);
//    for (int i = 1; i < vertex_ + 1; ++i) {
//      if (!used_[i]) {
//        return false;  // связность
//      }
//    }
//    int cc_edge = 0;
//    int count_c = 0;
//    for (int i = 1; i < vertex_ + 1; ++i) {
//      if (type_[i]) {
//        ++count_c;
//        if (adj_list_[i].size() != 4) {
//          return false;  // 4 связи у углерода
//        }
//        for (int u : adj_list_[i]) {
//          if (type_[u]) {
//            int u_bond_count = 0;
//            for (int v : adj_list_[i]) {
//              if (v == u) {
//                ++u_bond_count;
//              }
//            }
//            if (u_bond_count > 1) {
//              return false;  // проверка на наличие кратных ребер
//            }
//            ++cc_edge;
//          }
//        }
//      } else {
//        if (adj_list_[i].size() != 1) {
//          return false;  // 1 связь у водорода
//        }
//        if (!type_[adj_list_[i][0]]) {
//          return false;  // нет H-H
//        }
//      }
//    }
//
//    if (count_c == 1) {
//      return true;
//    }
//    if (count_c == 2) {
//      return (cc_edge == count_c);
//    }
//    return (cc_edge > count_c * 2);  // нет углеродного цикла
//  }
//};
//
//std::istream& operator>>(std::istream& is, Graph& graph) {
//  std::string type;
//  is >> type;
//  for (int i = 0; i < graph.vertex_; ++i) {
//    if (type[i] == 'C') {
//      graph.type_[i + 1] = true;
//    }
//  }
//  int v1, v2;
//  for (int i = 0; i < graph.edge_; ++i) {
//    is >> v1 >> v2;
//    graph.adj_list_[v1].push_back(v2);
//    graph.adj_list_[v2].push_back(v1);
//  }
//  return is;
//}
//int main() {
//  std::ios::sync_with_stdio(false);
//  std::cin.tie(nullptr);
//  std::cout.tie(nullptr);
//  int n, m;
//  std::cin >> n >> m;
//  Graph graph = Graph(n, m);
//  std::cin >> graph;
//  std::cout << (graph.AlkanCheck() ? "YES" : "NO");
//}