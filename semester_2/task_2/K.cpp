//#include <iostream>
//#include <vector>
//
//class Graph {
// public:
//  int vertex_;
//  int edges_;
//
// private:
//  std::vector<std::vector<int>> adj_list_;
//  std::vector<int> top_sorted_;
//  std::vector<int> color_;
//  std::vector<int> parent_;
//  int cycle_start_;
//  int cycle_end_;
//
//  bool Dfs(int vertex) {
//    color_[vertex] = 1;
//    for (size_t i = 0; i < adj_list_[vertex].size(); ++i) {
//      int neighbour = adj_list_[vertex][i];
//      if (color_[neighbour] == 0) {
//        parent_[neighbour] = vertex;
//        if (Dfs(neighbour)) {
//          return true;
//        }
//      } else if (color_[neighbour] == 1) {
//        cycle_end_ = vertex;
//        cycle_start_ = neighbour;
//        return true;
//      }
//    }
//    color_[vertex] = 2;
//    return false;
//  }
//
// public:
//  explicit Graph(int vertex) : vertex_(vertex), edges_(0), cycle_start_(-1), cycle_end_(-1) {
//    adj_list_.resize(vertex_ + 1);
//    color_.resize(vertex_ + 1, 0);
//    parent_.resize(vertex_ + 1, -1);
//  }
//
//  friend std::istream& operator>>(std::istream&, Graph&);
//
//  bool PossibleToSort() {
//    for (int i = 1; i < vertex_ + 1; ++i) {
//      if (Dfs(i)) {
//        break;
//      }
//    }
//    return (cycle_start_ == -1);
//  }
//};
//
//std::istream& operator>>(std::istream& is, Graph& graph) {
//  int first = 1;
//  int count = 0;
//  std::string col;
//  while (first < graph.vertex_) {
//    is >> col;
//    int second = first + 1;
//    for (const auto l : col) {
//      if (l == 'R') {
//        graph.adj_list_[first].emplace_back(second);
//        ++count;
//      } else {
//        graph.adj_list_[second].emplace_back(first);
//        ++count;
//      }
//      ++second;
//    }
//    ++first;
//  }
//  graph.edges_ = count;
//  return is;
//}
//int main() {
//  std::ios::sync_with_stdio(false);
//  std::cin.tie(nullptr);
//  std::cout.tie(nullptr);
//  int n;
//  std::cin >> n;
//  Graph graph = Graph(n);
//  std::cin >> graph;
//  std::cout << (graph.PossibleToSort() ? "YES" : "NO");
//}