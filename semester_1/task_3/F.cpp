//#include <iostream>
//void Solution(int64_t** arr, int64_t m, int64_t n) {
//  for (int64_t i = 0; i < m + 1; ++i) {
//    for (int64_t j = 0; j < n + 1; ++j) {
//      arr[i][j] = 0;
//    }
//  }
//  arr[0][0] = 1;
//  for (int64_t i = 0; i < m; ++i) {
//    for (int64_t j = 0; j < n; ++j) {
//      arr[i + 1][j] += arr[i][j];
//      arr[i][j + 1] += arr[i][j];
//      arr[i + 1][j + 1] += arr[i][j];
//    }
//  }
//  std::cout << arr[m - 1][n - 1];
//}
//int main() {
//  int64_t n, m;
//  std::cin >> m >> n;
//  auto** arr = new int64_t* [m + 1];
//  for (int64_t i = 0; i < m + 1; ++i) {
//    arr[i] = new int64_t[n + 1];
//  }
//  Solution(arr, m, n);
//  for (int64_t i = 0; i < m + 1; ++i) {
//    delete[] arr[i];
//  }
//  delete[] arr;
//  return 0;
//}