//#include <vector>
//#include <iostream>
//class Map {
//  std::vector<std::vector<int>> map_;
//  std::vector<std::vector<bool>> used_;
//  int drain_;
//  int inf_;
//
// public:
//  int n_, m_;
//
// private:
//  void Dfs(int x, int y, bool& lowland) {
//    used_[x][y] = 1;
//    if (map_[x][y] > map_[x + 1][y] || map_[x][y] > map_[x - 1][y] || map_[x][y] > map_[x][y - 1] || map_[x][y] > map_[x][y + 1]) {
//      lowland = true;
//    }
//    if (map_[x][y] == map_[x + 1][y] && !used_[x + 1][y]) {
//      Dfs(x + 1, y, lowland);
//    }
//    if (map_[x][y] == map_[x - 1][y] && !used_[x - 1][y]) {
//      Dfs(x - 1, y, lowland);
//    }
//    if (map_[x][y] == map_[x][y + 1] && !used_[x][y + 1]) {
//      Dfs(x, y + 1, lowland);
//    }
//    if (map_[x][y] == map_[x][y - 1] && !used_[x][y - 1]) {
//      Dfs(x, y - 1, lowland);
//    }
//  }
//
// public:
//  Map(int n, int m) : n_(n), m_(m), drain_(0), inf_(1000000000) {
//    used_.resize(n_ + 2);
//    map_.resize(n_ + 2);
//    for (int i = 0; i <= n_ + 1; ++i) {
//      used_[i].resize(m_ + 2);
//      map_[i].resize(m_ + 2);
//    }
//    for (int i = 1; i <= n_; ++i) {
//      for (int j = 1; j <= m_; ++j) {
//        used_[i][j] = false;
//      }
//    }
//    for (int i = 0; i <= n_ + 1; ++i) {
//      used_[i][0] = true;
//      map_[i][0] = inf_;
//      used_[i][m_ + 1] = true;
//      map_[i][m_ + 1] = inf_;
//    }
//    for (int i = 0; i <= m_ + 1; ++i) {
//      used_[0][i] = true;
//      map_[0][i] = inf_;
//      used_[n_ + 1][i] = true;
//      map_[n_ + 1][i] = inf_;
//    }
//  }
//
//  friend std::istream& operator>>(std::istream&, Map&);
//
//  int FindDrain() {
//    for (int i = 1; i <= n_; ++i) {
//      for (int j = 1; j <= m_; ++j) {
//        if (!used_[i][j]) {
//          bool lowland = false;
//          Dfs(i, j, lowland);
//          if (!lowland) {
//            ++drain_;
//          }
//        }
//      }
//    }
//    return drain_;
//  }
//};
//
//std::istream& operator>>(std::istream& is, Map& map) {
//  int height;
//  for (int i = 1; i <= map.n_; ++i) {
//    for (int j = 1; j <= map.m_; ++j) {
//      is >> height;
//      map.map_[i][j] = height;
//    }
//  }
//  return is;
//}
//
//int main() {
//  int n, m, height;
//  std::cin >> n >> m;
//  Map map = Map(n, m);
//  std::cin >> map;
//  std::cout << map.FindDrain();
//}