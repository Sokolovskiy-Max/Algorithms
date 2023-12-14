//#include <iostream>
//#include <algorithm>
//
//int BinarySearch(int* arr, int size, int key) {
//  int left = -1;
//  int right = size;
//  while (left < right - 1) {
//    int mid = (left + right) / 2;
//    if (arr[mid] < key) {
//      left = mid;
//    } else {
//      right = mid;
//    }
//  }
//  return right;
//}
//
//void LIS(int* arr, int n) {
//  auto* dp = new int[n + 1];
//  auto* pos = new int[n + 1];
//  auto* prev = new int[n];
//  int length = 0;
//  pos[0] = -1;
//  dp[0] = -100001;
//  for (int i = 1; i <= n; ++i) {
//    dp[i] = 100000;
//  }
//  for (int i = 0; i < n; ++i) {
//    int j = BinarySearch(dp, n + 1, arr[i]);
//    if (dp[j - 1] < arr[i] && arr[i] < dp[j]) {
//      dp[j] = arr[i];
//      pos[j] = i;
//      prev[i] = pos[j - 1];
//      length = std::max(length, j);
//    }
//  }
//  std::cout << length;
//  delete[] prev;
//  delete[] dp;
//  delete[] pos;
//}
//int main() {
//  int n;
//  std::cin >> n;
//  auto* arr = new int[n];
//  for (int i = 0; i < n; ++i) {
//    std::cin >> arr[i];
//  }
//  LIS(arr, n);
//  delete[] arr;
//  return 0;
//}
