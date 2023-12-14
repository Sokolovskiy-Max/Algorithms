//#include <iostream>
//#include <cmath>
//
//bool GetNumberFromProfile(int64_t profile, int64_t i) {
//  return (profile & int64_t(std::pow(2, i))) > 0;
//}
//
//bool PossibleStep(int64_t profile1, int64_t profile2, int64_t n) {
//  for (int64_t i = 0; i < n - 1; ++i) {
//    if (GetNumberFromProfile(profile1, i) == GetNumberFromProfile(profile1, i + 1) && GetNumberFromProfile(profile2, i) == GetNumberFromProfile(profile2, i + 1) && GetNumberFromProfile(profile1, i) == GetNumberFromProfile(profile2, i)) {
//      return false;
//    }
//  }
//  return true;
//}
//void Solution() {
//  int64_t n, m;
//  std::cin >> n >> m;
//  if (n > m) {
//    std::swap(n, m);
//  }
//  auto** dp = new int64_t * [m + 2];
//  for (int64_t i = 0; i < m + 2; ++i) {
//    dp[i] = new int64_t[int64_t(std::pow(2, n))];
//    for (int64_t j = 0; j < int64_t(std::pow(2, n)); ++j) {
//      dp[i][j] = 0;
//    }
//  }
//  int64_t pretty_mask = 0;
//  for (int64_t i = 0; i < n; i += 2) {
//    pretty_mask = pretty_mask | int64_t(std::pow(2, i));
//  }
//  dp[0][pretty_mask] = 1;
//  for (int64_t i = 0; i <= m; ++i) {
//    for (int64_t profile1 = 0; profile1 < int64_t(std::pow(2, n)); ++profile1) {
//      for (int64_t profile2 = 0; profile2 < int64_t(std::pow(2, n)); ++profile2) {
//        if (PossibleStep(profile1, profile2, n)) {
//          dp[i + 1][profile2] += dp[i][profile1];
//        }
//      }
//    }
//  }
//  std::cout << dp[m + 1][pretty_mask];
//  for (int64_t i = 0; i < m + 2; ++i) {
//    delete[] dp[i];
//  }
//  delete[] dp;
//}
//int main(){
//  Solution();
//  return 0;
//}
// 