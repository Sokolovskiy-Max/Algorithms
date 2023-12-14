//#include <iostream>
//void Recovery(int** dp, int* weight, int i, int j);
//void Backpack() {
//  int n, w;
//  std::cin >> n;
//  std::cin >> w;
//  auto* weight = new int[n + 1];
//  auto* cost = new int[n + 1];
//  for (int i = 1; i <= n; ++i) {
//    std::cin >> weight[i];
//  }
//  for (int i = 1; i < n + 1; ++i) {
//    std::cin >> cost[i];
//  }
//  auto** dp = new int* [n + 1];
//  for (int i = 0; i <= n; ++i) {
//    dp[i] = new int[w + 1];
//  }
//  for (int i = 0; i <= n; ++i) {
//    dp[i][0] = 0;
//  }
//  for (int i = 0; i <= w; ++i) {
//    dp[0][i] = 0;
//  }
//  for (int i = 1; i <= n; ++i) {
//    for (int j = 1; j <= w; ++j) {
//      if (j >= weight[i]) {
//        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight[i]] + cost[i]);
//      } else {
//        dp[i][j] = dp[i - 1][j];
//      }
//    }
//  }
//  Recovery(dp, weight, n, w);
//  delete[] weight;
//  delete[] cost;
//  for (int i = 0; i <= n; ++i) {
//    delete[] dp[i];
//  }
//  delete[] dp;
//}
//
//void Recovery(int** dp, int* weight, int i, int j) {
//  if (dp[i][j] == 0) {
//    return;
//  }
//  if (dp[i - 1][j] == dp[i][j]) {
//    Recovery(dp, weight, i - 1, j);
//  } else {
//    Recovery(dp, weight, i - 1, j - weight[i]);
//    std::cout << i << std::endl;
//  }
//}
//
//int main() {
//  Backpack();
//  return 0;
//}