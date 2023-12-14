#include <iostream>
#include <cstdint>
int n, m, ans_size, final_size;
int64_t maxs;
void RecurrentEnumeration(int* coins, int m, int* ans, int* final_ans, int pos = 0, int sum = 0) {  //рекурентный перебор
  if (pos == m) {
    if (sum == n) {
      if (!final_size || (ans_size < final_size)) {
        for (int i = 0; i < 2 * m; ++i) {
          final_ans[i] = ans[i];
        }
        final_size = ans_size;
      }
      return;
    }
    return;
  }
  RecurrentEnumeration(coins, m, ans, final_ans, pos + 1, sum);
  ans[ans_size] = coins[pos];
  ++ans_size;
  RecurrentEnumeration(coins, m, ans, final_ans, pos + 1, sum + coins[pos]);
  ans[ans_size] = coins[pos];
  ++ans_size;
  RecurrentEnumeration(coins, m, ans, final_ans, pos + 1, sum + coins[pos] * 2);
  ans[ans_size - 1] = 0;
  --ans_size;
  ans[ans_size - 1] = 0;
  --ans_size;
}
int main() {
  std::cin >> n >> m;
  ans_size = 0;
  final_size = 0;
  auto* coins = new int[m];
  auto* ans = new int[m * 2];
  auto* final_ans = new int[m * 2];
  for (int i = 0; i < m; ++i) {
    std::cin >> coins[i];
    maxs += coins[i] * 2;
  }
  for (int i = 0; i < m * 2; ++i) {
    ans[i] = 0;
    final_ans[i] = 0;
  }
  if (maxs < n) {
    std::cout << -1;
    delete[] coins;
    delete[] final_ans;
    delete[] ans;
    return 0;
  }
  RecurrentEnumeration(coins, m, ans, final_ans);
  if (final_size == 0) {
    std::cout << 0;
    delete[] coins;
    delete[] final_ans;
    delete[] ans;
    return 0;
  }
  std::cout << final_size << std::endl;
  for (int i = 0; i < final_size; i++) {
    std::cout << final_ans[i] << " ";
  }
  delete[] coins;
  delete[] final_ans;
  delete[] ans;
  return 0;
}