//#include <iostream>
//void FindLev(char* string1, int64_t size1, char* string2, int64_t size2);
//void Read() {
//  auto* string1 = new char[5001];
//  auto* string2 = new char[5001];
//  char a = getchar();
//  int64_t size1 = 0;
//  for (int64_t i = 0; a != '\n'; ++i) {
//    string1[i] = a;
//    a = getchar();
//    ++size1;
//  }
//  char b = getchar();
//  int64_t size2 = 0;
//  for (int64_t i = 0; b != '\n'; ++i) {
//    string2[i] = b;
//    b = getchar();
//    ++size2;
//  }
//  FindLev(string1, size1, string2, size2);
//  delete[] string1;
//  delete[] string2;
//}
//void FindLev(char* string1, int64_t size1, char* string2, int64_t size2) {
//  auto** dp = new int64_t*[size1 + 1];
//  for (int64_t i = 0; i <= size1; ++i) {
//    dp[i] = new int64_t[size2 + 1];
//  }
//  for (int64_t i = 0; i <= size1; ++i) {
//    dp[i][0] = i;
//  }
//  for (int64_t i = 0; i <= size2; ++i) {
//    dp[0][i] = i;
//  }
//  for (int64_t i = 1; i <= size1; ++i) {
//    for (int64_t j = 1; j <= size2; ++j) {
//      if (string1[i - 1] == string2[j - 1]) {
//        dp[i][j] = dp[i - 1][j - 1];
//      } else {
//        dp[i][j] = dp[i][j - 1] + 1;
//        dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + 1);
//        dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + 1);
//      }
//    }
//  }
//  std::cout << dp[size1][size2];
//  for (int64_t i = 0; i <= size1; ++i) {
//    delete[] dp[i];
//  }
//  delete[] dp;
//}
//int main() {
//  Read();
//  return 0;
//}