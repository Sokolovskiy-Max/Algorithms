//#include <iostream>
//#include <algorithm>
//void LCIS(int64_t size_one, int64_t* arr1, int64_t size_two, int64_t* arr2);
//
//int64_t BinarySearch(int64_t* arr, int64_t size, int64_t key) {
//  int64_t left = -1;
//  int64_t right = size;
//  while (left < right - 1) {
//    int64_t mid = (left + right) / 2;
//    if (arr[mid] < key) {
//      left = mid;
//    } else {
//      right = mid;
//    }
//  }
//  return right;
//}
//
//void LIS(int64_t* arr, int64_t n) {
//  auto* dp = new int64_t[n + 1];
//  auto* pos = new int64_t[n + 1];
//  auto* prev = new int64_t[n];
//  int64_t length = 0;
//  pos[0] = -1;
//  dp[0] = -3147483649;
//  for (int64_t i = 1; i <= n; ++i) {
//    dp[i] = 3147483648;
//  }
//  for (int64_t i = 0; i < n; ++i) {
//    int64_t j = BinarySearch(dp, n + 1, arr[i]);
//    if (dp[j - 1] < arr[i] && arr[i] < dp[j]) {
//      dp[j] = arr[i];
//      pos[j] = i;
//      prev[i] = pos[j - 1];
//      length = std::max(length, j);
//    }
//  }
//  int64_t p = pos[length];
//  std::cout << length << std::endl;
//  auto* ans = new int64_t[length];
//
//  for (int64_t i = 0; p != -1; ++i) {
//    ans[i] = arr[p];
//    p = prev[p];
//  }
//  for (int64_t i = length - 1; i >= 0; --i) {
//    std::cout << ans[i] << ' ';
//  }
//  delete[] ans;
//  delete[] prev;
//  delete[] dp;
//  delete[] pos;
//}
//
//void Read() {
//  int64_t size_one, size_two;
//  std::cin >> size_one;
//  auto arr1 = new int64_t[size_one];
//  for (int64_t i = 0; i < size_one; ++i) {
//    std::cin >> arr1[i];
//  }
//  std::cin >> size_two;
//  auto arr2 = new int64_t[size_two];
//  for (int64_t i = 0; i < size_two; ++i) {
//    std::cin >> arr2[i];
//  }
//  LCIS(size_one, arr1, size_two, arr2);
//  delete[] arr1;
//  delete[] arr2;
//}
//void LCIS(int64_t size_one, int64_t* arr1, int64_t size_two, int64_t* arr2) {
//  auto** dp = new int64_t*[size_one + 1];
//  for (int64_t i = 0; i <= size_one; ++i) {
//    dp[i] = new int64_t[size_two + 1];
//  }
//
//
//  for (int64_t i = 1; i <= size_one; ++i) {
//    dp[i][0] = 0;
//  }
//  for (int64_t i = 1; i <= size_two; ++i) {
//    dp[0][i] = 0;
//  }
//  dp[0][0] = 0;
//  for (int64_t i = 1; i <= size_one; ++i) {
//    for (int64_t j = 1; j <= size_two; ++j) {
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
//  int64_t size = dp[size_one][size_two];
//  auto* ans = new int64_t[size];
//  int64_t i = size_one;
//  int64_t j = size_two;
//  for (int64_t k = 0; i > 0 && j > 0;) {
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
//  LIS(ans, size);
//  delete[] ans;
//  for (int64_t i = 0; i <= size_one; ++i) {
//    delete[] dp[i];
//  }
//  delete[] dp;
//}
//int main() {
//  Read();
//  return 0;
//}