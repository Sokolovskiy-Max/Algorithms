#include <iostream>
#include <vector>

class ConnactedVertex {
public:
  int n_;
  std::vector<std::vector<int>> graph_;
  std::vector<bool> used_;
  std::vector<std::vector<int>> all_groups_;
  int count_groups_;
  ConnactedVertex(int n, std::vector<std::vector<int>>& graph, std::vector<bool>& used,
    std::vector<std::vector<int>>& all_groups)
    : n_(n), graph_(graph), used_(used), all_groups_(all_groups), count_groups_(0) {
  }
  void DFS(int vertex, std::vector<int>& group) {
    used_[vertex] = true;
    group.emplace_back(vertex);
    for (int neighbour : graph_[vertex]) {
      int v = neighbour;
      if (!used_[v]) {
        DFS(neighbour, group);
      }
    }
  }
  void FindGroups() {
    for (int i = 1; i <= n_; ++i) {
      if (!used_[i]) {
        ++count_groups_;
        std::vector<int> group;
        DFS(i, group);
        all_groups_.emplace_back(group);
      }
    }
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n + 1, std::vector<int>());
  int vertex1, vertex2;
  for (int i = 0; i < m; ++i) {
    std::cin >> vertex1 >> vertex2;
    graph[vertex1].emplace_back(vertex2);
    graph[vertex2].emplace_back(vertex1);
  }
  std::vector<bool> used(n + 1, false);
  std::vector<std::vector<int>> all_groups;
  ConnactedVertex a = ConnactedVertex(n, graph, used, all_groups);
  a.FindGroups();
  std::cout << a.count_groups_ << std::endl;
  for (int i = 0; i < a.count_groups_; ++i) {
    int size = a.all_groups_[i].size();
    std::cout << size << std::endl;
    for (int j = 0; j < size; ++j) {
      std::cout << a.all_groups_[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}