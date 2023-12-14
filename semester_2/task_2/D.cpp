//#include <iostream>
//#include <vector>
//#include <queue>
//class NewYork {
//  int n_;
//  int m_;
//  std::vector<std::vector<int>> map_;
//  std::queue<std::pair<int, int>> general_queue_;
//  
// public:
//  NewYork(int n, int m) : n_(n), m_(m) {
//    map_.resize(n_ + 2);
//    for (int i = 0; i < n_ + 2; ++i) {
//      map_[i].resize(m + 2, 0);
//    }
//  }
//
//  friend std::istream& operator>>(std::istream&, NewYork&);
//
//  void DistanceSearch() {
//    int dist = 1;
//    std::queue<std::pair<int, int>> internal_queue;
//    while (!general_queue_.empty()) {
//      ++dist;
//      while (!general_queue_.empty()) {
//        std::pair<int, int> cur = general_queue_.front();
//        general_queue_.pop();
//        if (map_[cur.first + 1][cur.second] == 0) {
//          if (cur.first + 1 > 0 && cur.first + 1 < n_ + 1 && cur.second > 0 && cur.second < m_ + 1) {
//            internal_queue.push(std::make_pair(cur.first + 1, cur.second));
//          }
//          map_[cur.first + 1][cur.second] = dist;
//        }
//        if (map_[cur.first - 1][cur.second] == 0) {
//          if (cur.first - 1 > 0 && cur.first - 1 < n_ + 1 && cur.second > 0 && cur.second < m_ + 1) {
//            internal_queue.push(std::make_pair(cur.first - 1, cur.second));
//          }
//          map_[cur.first - 1][cur.second] = dist;
//        }
//        if (map_[cur.first][cur.second + 1] == 0) {
//          if (cur.first > 0 && cur.first < n_ + 1 && cur.second + 1 > 0 && cur.second + 1 < m_ + 1) {
//            internal_queue.push(std::make_pair(cur.first, cur.second + 1));
//          }
//          map_[cur.first][cur.second + 1] = dist;
//        }
//        if (map_[cur.first][cur.second - 1] == 0) {
//          if (cur.first > 0 && cur.first < n_ + 1 && cur.second - 1 > 0 && cur.second - 1 < m_ + 1) {
//            internal_queue.push(std::make_pair(cur.first, cur.second - 1));
//          }
//          map_[cur.first][cur.second - 1] = dist;
//        }
//      }
//      general_queue_ = internal_queue;
//      while (!internal_queue.empty()) {
//        internal_queue.pop();
//      }
//    }
//  }
//
//  void ToString() {
//    for (int i = 1; i < n_ + 1; ++i) {
//      for (int j = 1; j < m_ + 1; ++j) {
//        std::cout << map_[i][j] - 1 << ' ';
//      }
//      std::cout << std::endl;
//    }
//  }
//};
//
//std::istream& operator>>(std::istream& is, NewYork& new_york) {
//  for (int i = 1; i < new_york.n_ + 1; ++i) {
//    for (int j = 1; j < new_york.m_ + 1; ++j) {
//      std::cin >> new_york.map_[i][j];
//      if (new_york.map_[i][j] == 1) {
//        new_york.general_queue_.push(std::make_pair(i, j));
//      }
//    }
//  }
//  return is;
//}
//
//int main() {
//  std::queue<std::pair<int, int>> queue;
//  int n, m;
//  std::cin >> n >> m;
//  NewYork new_york = NewYork(n, m);
//  std::cin >> new_york;
//  new_york.DistanceSearch();
//  new_york.ToString();
//}