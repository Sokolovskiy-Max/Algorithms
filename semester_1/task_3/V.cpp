//#include <iostream>
//int64_t Counter(int* arr, int n) {
//  auto** dp = new int64_t * [n];
//  for (int i = 0; i < n; ++i) {
//    dp[i] = new int64_t[n];
//    for (int j = 0; j < n; ++j) {
//      dp[i][j] = 0;
//    }
//  }
//
//  for (int i = 1; i < n; ++i) {
//    for (int j = 0; j < n - i; ++j) {
//      int t = j + i;
//      dp[j][t] = 1000000000;
//      for (int k = j; k < t; ++k) {
//        dp[j][t] = std::min(dp[j][t], dp[j][k] + dp[k + 1][t] + arr[j] * arr[k + 1] * arr[t + 1]);
//      }
//    }
//  }
//  int64_t ans = dp[0][n - 1];
//  for (int i = 0; i < n; ++i) {
//    delete[] dp[i];
//  }
//  delete[] dp;
//  return ans;
//}
//
//int main() {
//  int n;
//  std::cin >> n;
//  auto* arr = new int[n];
//  for (int i = 0; i < n; ++i) {
//    std::cin >> arr[i];
//  }
//  std::cout << Counter(arr, n - 1);
//  delete[] arr;
//  return 0;
//}