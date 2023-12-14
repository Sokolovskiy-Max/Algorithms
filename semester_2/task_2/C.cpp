//#include <iostream>
//#include <queue>
//#include <vector>
//int RotateLeft(int n) {
//  return (n % 1000) * 10 + n / 1000;
//}
//int RotateRight(int n) {
//  return (n % 10) * 1000 + n / 10;
//}
//int Plus(int n) {
//  if (n / 1000 == 9) {
//    return n;
//  }
//  return n + 1000;
//}
//int Minus(int n) {
//  if (n % 10 == 1) {
//    return n;
//  }
//  return n - 1;
//}
//
//class Graph {
//  int start_;
//  int end_;
//  int max_depth_ = 10000;
//  std::queue<int> queue_;
//  std::vector<int> color_;
//  std::vector<int> parent_;
//  std::vector<int> path_;
//
// public:
//  Graph(int start, int end) : start_(start), end_(end) {
//    color_.resize(max_depth_);
//    parent_.resize(max_depth_);
//  }
//
//  void Bfs() {
//    int vertex1, vertex2;
//    queue_.push(start_);
//    color_[start_] = 1;
//    int (*functions[4])(int) = { Plus, Minus, RotateLeft, RotateRight };
//    while (!queue_.empty()) {
//      vertex1 = queue_.front();
//      queue_.pop();
//      if (vertex1 == end_) {
//        break;
//      }
//      for (int i = 0; i < 4; ++i) {
//        vertex2 = functions[i](vertex1);
//        if (!color_[vertex2]) {
//          color_[vertex2] = 1;
//          parent_[vertex2] = vertex1;
//          queue_.push(vertex2);
//        }
//      }
//    }
//    while (parent_[end_] != parent_[start_]) {
//      path_.push_back(end_);
//      end_ = parent_[end_];
//    }
//  }
//
//  void ToString() {
//    std::cout << path_.size() + 1 << std::endl;
//    std::cout << start_ << std::endl;
//    for (int i = int(path_.size() - 1); i >= 0; --i) {
//      std::cout << path_[i] << std::endl;
//    }
//  }
//};
//
//int main() {
//  int start, end;
//  std::cin >> start >> end;
//  Graph graph = Graph(start, end);
//  graph.Bfs();
//  graph.ToString();
//}