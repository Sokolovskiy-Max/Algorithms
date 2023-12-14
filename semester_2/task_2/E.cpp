//#include <iostream>
//#include <vector>
//#include <queue>
//void DistanceSearch(std::vector<std::vector<int>>& map, std::queue<std::pair<int, int>>& queue, int n, int m) {
//  int dist = 1;
//  std::queue<std::pair<int, int>> queue1;
//  while (!queue.empty()) {
//    ++dist;
//    while (!queue.empty()) {
//      std::pair<int, int> cur = queue.front();
//      queue.pop();
//      if (map[cur.first + 1][cur.second] == 0) {
//        if (cur.first + 1 > 0 && cur.first + 1 < n + 1 && cur.second > 0 && cur.second < m + 1) {
//          queue1.push(std::make_pair(cur.first + 1, cur.second));
//        }
//        map[cur.first + 1][cur.second] = dist;
//      }
//      if (map[cur.first - 1][cur.second] == 0) {
//        if (cur.first - 1 > 0 && cur.first - 1 < n + 1 && cur.second > 0 && cur.second < m + 1) {
//          queue1.push(std::make_pair(cur.first - 1, cur.second));
//        }
//        map[cur.first - 1][cur.second] = dist;
//      }
//      if (map[cur.first][cur.second + 1] == 0) {
//        if (cur.first > 0 && cur.first < n + 1 && cur.second + 1 > 0 && cur.second + 1 < m + 1) {
//          queue1.push(std::make_pair(cur.first, cur.second + 1));
//        }
//        map[cur.first][cur.second + 1] = dist;
//      }
//      if (map[cur.first][cur.second - 1] == 0) {
//        if (cur.first > 0 && cur.first < n + 1 && cur.second - 1 > 0 && cur.second - 1 < m + 1) {
//          queue1.push(std::make_pair(cur.first, cur.second - 1));
//        }
//        map[cur.first][cur.second - 1] = dist;
//      }
//    }
//    queue = queue1;
//    while (!queue1.empty()) {
//      queue1.pop();
//    }
//  }
//}
//int main() {
//  std::queue<std::pair<int, int>> queue;
//  int n, m;
//  std::cin >> n >> m;
//  /std::vector<std::vector<int>> map(n + 2, std::vector<int>(m + 2, 0));
//  for (int i = 1; i < n + 1; ++i) {
//    for (int j = 1; j < m + 1; ++j) {
//      std::cin >> map[i][j];
//      if (map[i][j] == 1) {
//        queue.push(std::make_pair(i, j));
//      }
//    }
//  }
//  DistanceSearch(map, queue, n, m);
//  for (int i = 1; i < n + 1; ++i) {
//    for (int j = 1; j < m + 1; ++j) {
//      std::cout << map[i][j] - 1 << ' ';
//    }
//    std::cout << std::endl;
//  }
//}