//#include <iostream>
//#include <vector>
//
//class FenwicTree {
//  std::vector<std::vector<std::vector<int>>> arr_;
//  int n_;
//
//  int Query(int x, int y, int z) {
//    int sum = 0;
//    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
//      for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
//        for (int k = z; k >= 0; k = (k & (k + 1)) - 1) {
//          sum += arr_[i][j][k];
//        }
//      }
//    }
//    return sum;
//  }
//
// public:
//  FenwicTree(int n) : n_(n) {
//    arr_.resize(n_);
//    for (int i = 0; i < n_; ++i) {
//      arr_[i].resize(n_);
//      for (int j = 0; j < n_; ++j) {
//        arr_[i][j].resize(n_, 0);
//      }
//    }
//  }
//  void Update(int x, int y, int z, int delta) {
//    for (int i = x; i < n_; i = i | (i + 1)) {
//      for (int j = y; j < n_; j = j | (j + 1)) {
//        for (int k = z; k < n_; k = k | (k + 1)) {
//          arr_[i][j][k] += delta;
//        }
//      }
//    }
//  }
//
//  int Query(int x1, int y1, int z1, int x2, int y2, int z2) {
//    int ans = Query(x2, y2, z2) - Query(x1 - 1, y2, z2) - Query(x2, y1 - 1, z2) - Query(x2, y2, z1 - 1) + Query(x2, y1 - 1, z1 - 1) +
//              Query(x1 - 1, y2, z1 - 1) + Query(x1 - 1, y1 - 1, z2) - Query(x1 - 1, y1 - 1, z1 - 1);
//    return ans;
//  }
//
//};
//
//int main() {
//  std::ios_base::sync_with_stdio(false);
//  std::cin.tie(nullptr);
//  std::cout.tie(nullptr);
//  int n = 0;
//
//  int x = 0;
//  int y = 0;
//  int z = 0;
//  int k = 0;
//
//  int x2 = 0;
//  int y2 = 0;
//  int z2 = 0;
//  std::cin >> n;
//  FenwicTree tree = FenwicTree(n);
//  int type = 0;
//  while (true) {
//    std::cin >> type;
//    if (type == 1) {
//      std::cin >> x >> y >> z >> k;
//      tree.Update(x, y, z, k);
//    } else if (type == 2) {
//      std::cin >> x >> y >> z >> x2 >> y2 >> z2;
//      std::cout << tree.Query(x, y, z, x2, y2, z2) << '\n';
//    } else {
//      break;
//    }
//  }
//  return 0;
//}  