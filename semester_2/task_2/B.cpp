//#include <iostream>
//#include <vector>
//#include <queue>
//class RecBfs {
//public:
//  std::vector<std::vector<int>> graph_;
//  std::vector<int> colored_vertex_;
//  int n_;
//  RecBfs(std::vector<std::vector<int>>& graph, std::vector<int>& colored_vertex, int n)
//    : graph_(graph), colored_vertex_(colored_vertex), n_(n) {
//  }
//  bool BFS(int vertex) {
//    std::queue<int> queue;
//    colored_vertex_.assign(n_ + 1, 0);
//    colored_vertex_[vertex] = 1;
//    queue.push(vertex);
//    while (!queue.empty()) {
//      int v = queue.front();
//      queue.pop();
//      for (int u : graph_[v]) {
//        if (colored_vertex_[u] == 0) {
//          if (colored_vertex_[v] == 1) {
//            colored_vertex_[u] = 2;
//          }
//          if (colored_vertex_[v] == 2) {
//            colored_vertex_[u] = 1;
//          }
//          queue.push(u);
//        }
//        if (colored_vertex_[v] == colored_vertex_[u]) {
//          return false;
//        }
//      }
//    }
//    return true;
//  }
//};
//int main() {
//  int n, m;
//  std::cin >> n >> m;
//  std::vector<std::vector<int>> graph(n + 1, std::vector<int>());
//  std::vector<int> colored_vertex(n + 1, 0);
//  int vertex1, vertex2;
//  for (int i = 0; i < m; ++i) {
//    std::cin >> vertex1 >> vertex2;
//    graph[vertex1].push_back(vertex2);
//    graph[vertex2].push_back(vertex1);
//  }
//  RecBfs dfs_obj = RecBfs(graph, colored_vertex, n);
//  bool check = true;
//  for (int i = 1; i <= n; ++i) {
//    check = dfs_obj.BFS(i);
//    if (check == false) {
//      break;
//    }
//  }
//  std::cout << (check ? "YES" : "NO");
//}