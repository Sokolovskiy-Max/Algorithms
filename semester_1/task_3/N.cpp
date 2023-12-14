//#include <iostream>
//int64_t Solution(int n) {
//  auto* arr = new int64_t[n];
//  auto* dp = new int64_t[n];
//  for (int i = 0; i < n; ++i) {
//    std::cin >> arr[i];
//    dp[i] = 1;
//  }
//  int64_t ans = 1;
//  for (int i = 0; i < n - 1; ++i) {
//    for (int j = 0; j < i + 1; ++j) {
//      if (arr[i + 1] > arr[j]) {
//        dp[i + 1] += dp[j] % 10000000;
//        dp[i + 1] %= 10000000;
//      }
//    }
//    ans += dp[i + 1];
//  }
//  delete[] dp;
//  delete[] arr;
//  return ans;
//}
//int main() {
//  int n = 0;
//  std::cin >> n;
//  std::cout << Solution(n);
//  return 0;
//}