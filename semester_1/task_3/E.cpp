//#include <iostream>
//int64_t Counter(int button_count) {
//  if (button_count == 1) {
//    return 8;
//  }
//  auto** dp = new int*[10];
//  for (int i = 0; i <= 9; ++i) {
//    dp[i] = new int[button_count + 1];
//  }
//  for (int i = 0; i < 10; ++i) {
//    dp[i][0] = 0;
//  }
//  for (int i = 0; i < 10; ++i) {
//    if (i == 5) {
//      dp[i][1] = 0;
//    } else {
//      dp[i][1] = 1;
//    }
//  }
//  for (int i = 2; i <= button_count; ++i) {
//    dp[0][i] = dp[4][i - 1] + dp[6][i - 1];
//    dp[1][i] = dp[8][i - 1] + dp[6][i - 1];
//    dp[2][i] = dp[7][i - 1] + dp[9][i - 1];
//    dp[3][i] = dp[4][i - 1] + dp[8][i - 1];
//    dp[4][i] = dp[0][i - 1] + dp[3][i - 1] + dp[9][i - 1];
//    dp[6][i] = dp[0][i - 1] + dp[1][i - 1] + dp[7][i - 1];
//    dp[7][i] = dp[2][i - 1] + dp[6][i - 1];
//    dp[8][i] = dp[1][i - 1] + dp[3][i - 1];
//    dp[9][i] = dp[2][i - 1] + dp[4][i - 1];
//  }
//  int64_t count = 0;
//  for (int i = 0; i < 10; ++i) {
//    if (i != 5) {
//      count += dp[i][button_count];
//    }
//  }
//  count -= (dp[0][button_count] + dp[8][button_count]);
//  for (int i = 0; i < 10; ++i) {
//    delete[] dp[i];
//  }
//  delete dp;
//  return count;
//}
//
//int main() {
//  int n;
//  std::cin >> n;
//  int64_t count = Counter(n);
//  std::cout << count;
//}