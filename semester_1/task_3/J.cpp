//#include <iostream>
//#include <algorithm>
//
//int MaxLength(int i, int n, int* dist, int* memoisation) {
//  if (i > n - 3) {
//    return 0;
//  }
//  if (memoisation[i] == 0) {
//    memoisation[i] = dist[i + 1] - dist[i] + std::max(MaxLength(i + 2, n, dist, memoisation), MaxLength(i + 3, n, dist, memoisation));
//  }
//  return memoisation[i];
//}
//
//int main() {
//  int n;
//  std::cin >> n;
//  auto* dist = new int[n];
//  auto* memoisation = new int[n];
//  for (int i = 0; i < n; ++i) {
//    std::cin >> dist[i];
//    memoisation[i] = 0;
//  }
//  std::sort(dist, dist + n);
//  int max_length_to_del = std::max(MaxLength(1, n, dist, memoisation), MaxLength(2, n, dist, memoisation));
//  int ans = dist[n - 1] - dist[0] - max_length_to_del;
//  std::cout << ans;
//  delete[] dist;
//  delete[] memoisation;
//  return 0;
//}
//
//
