#include <iostream> 
void LCIS(int size_one, int* arr1, int size_two, int* arr2);
void Read() {
  int size_one, size_two;
  std::cin >> size_one;
  auto arr1 = new int[size_one + 1];
  arr1[0] = 0;
  for (int i = 1; i <= size_one; ++i) {
    std::cin >> arr1[i];
  }
  std::cin >> size_two;
  auto arr2 = new int[size_two + 1];
  arr2[0] = 0;
  for (int i = 1; i <= size_two; ++i) {
    std::cin >> arr2[i];
  }
  LCIS(size_one, arr1, size_two, arr2);
  delete[] arr1;
  delete[] arr2;
}
void LCIS(int size_one, int* arr1, int size_two, int* arr2) {
  auto** dp = new int* [size_one + 1];
  for (int i = 0; i <= size_one; ++i) {
    dp[i] = new int[size_two + 1];
  }
  for (int i = 0; i <= size_one; ++i) {
    for (int j = 0; j <= size_two; ++j) {
      dp[i][j] = 0;
    }
  }
  int prev_size = std::max(size_one, size_two) + 1;
  auto* prev = new int[prev_size];
  for (int i = 0; i < prev_size; ++i) {
    prev[i] = 0;
  }
  for (int i = 1; i <= size_one; ++i) {
    int elem_pos = 0;
    int elem_val = 0;
    for (int j = 1; j <= size_two; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (arr1[i] == arr2[j] && dp[i - 1][j] < elem_val + 1) {
        dp[i][j] = elem_val + 1;
        prev[j] = elem_pos;
      }
      if (arr1[i] > arr2[j] && dp[i - 1][j] > elem_val) {
        elem_val = dp[i - 1][j];
        elem_pos = j;
      }
    }
  }
  int pos = 1;
  for (int j = 1; j <= size_two; ++j) {
    if (dp[size_one][pos] < dp[size_one][j]) {
      pos = j;
    }
  }
  int size = 0;
  auto ans = new int[500];
  while (pos != 0) {
    ans[size] = arr2[pos];
    pos = prev[pos];
    ++size;
  }
  std::cout << size << std::endl;
  for (int i = size -1 ; i >= 0; --i) {
    std::cout << ans[i] << ' ';
  }
  delete[] prev;
  delete[] ans;
  for (int i = 0; i <= size_one; ++i) {
    delete[] dp[i];
  }
  delete[] dp;
}
int main() {
  Read();
  return 0;
}