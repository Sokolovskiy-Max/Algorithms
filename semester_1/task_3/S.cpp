//#include <iostream>
//#include <iostream>
//
//int LCS(int size_one, char* string1, int size_two, char* string2) {
//  auto** dp = new int*[size_one + 1];
//  for (int i = 0; i <= size_one; ++i) {
//    dp[i] = new int[size_two + 1];
//  }
//  for (int i = 1; i <= size_one; ++i) {
//    dp[i][0] = 0;
//  }
//  for (int i = 1; i <= size_two; ++i) {
//    dp[0][i] = 0;
//  }
//  dp[0][0] = 0;
//  for (int i = 1; i <= size_one; ++i) {
//    for (int j = 1; j <= size_two; ++j) {
//      if (string1[i - 1] == string2[j - 1]) {
//        dp[i][j] = dp[i - 1][j - 1] + 1;
//      } else {
//        if (dp[i - 1][j] >= dp[i][j - 1]) {
//          dp[i][j] = dp[i - 1][j];
//        } else {
//          dp[i][j] = dp[i][j - 1];
//        }
//      }
//    }
//  }
//  int size = dp[size_one][size_two];
//  for (int i = 0; i <= size_one; ++i) {
//    delete[] dp[i];
//  }
//  delete[] dp;
//  return size;
//}
//
//void Read() {
//  auto* string1 = new char[100000];
//  char a = getchar();
//  int size = 0;
//  for (int i = 0; a != '\n'; ++i) {
//    string1[i] = a;
//    a = getchar();
//    ++size;
//  }
//  auto* string2 = new char[size];
//  for (int i = size - 1; i >= 0; --i) {
//    string2[i] = string1[size - 1 - i];
//  }
//  std::cout << size - LCS(size, string1, size, string2);
//}
//int main() {
//  Read();
//  return 0;
//}