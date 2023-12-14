//#include <iostream> 
//void LCS(int size_one, int* arr1, int size_two, int* arr2);
//void Read() {
//  int size_one, size_two;
//  std::cin >> size_one;
//  auto arr1 = new int[size_one];
//  for (int i = 0; i < size_one; ++i) {
//    std::cin >> arr1[i];
//  }
//  std::cin >> size_two;
//  auto arr2 = new int[size_two];
//  for (int i = 0; i < size_two; ++i) {
//    std::cin >> arr2[i];
//  }
//  LCS(size_one, arr1, size_two, arr2);
//  delete[] arr1;
//  delete[] arr2;
//}
//void LCS(int size_one, int* arr1, int size_two, int* arr2) {
//  auto** dp = new int* [size_one + 1];
//  for (int i = 0; i <= size_one; ++i) {
//    dp[i] = new int[size_two + 1];
//  }
//
//
//  for (int i = 1; i <= size_one; ++i) {
//    dp[i][0] = 0;
//  }
//  for (int i = 1; i <= size_two; ++i) {
//    dp[0][i] = 0;
//  }
//  dp[0][0] = 0;
//  for (int i = 1; i <= size_one; ++i) {
//    for (int j = 1; j <= size_two; ++j) {
//      if (arr1[i - 1] == arr2[j - 1]) {
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
//
//  int size = dp[size_one][size_two];
//  auto* ans = new int[size];
//  int i = size_one;
//  int j = size_two;
//  for (int k = 0; i > 0 && j > 0;) {
//    if (arr1[i - 1] == arr2[j - 1]) {
//      ans[size - k - 1] = arr1[i - 1];
//      --i;
//      --j;
//      ++k;
//    } else {
//      if (dp[i - 1][j] == dp[i][j]) {
//        --i;
//      } else {
//        --j;
//      }
//    }
//  }
//  for (int k = 0; k < size; ++k) {
//    std::cout << ans[k] << ' ';
//  }
//  delete[] ans;
//  for (int i = 0; i <= size_one; ++i) {
//    delete[] dp[i];
//  }
//  delete dp;
//}
//int main() {
//  Read();
//  return 0;
//}