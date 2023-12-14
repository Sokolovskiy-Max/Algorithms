//#include <iostream>
//#include <algorithm>
//int64_t CountThreeSame(int64_t* x_repeats, int64_t dif) {
//  int64_t count = 0;
//  for (int64_t i = 0; i < dif; ++i) {
//    if (x_repeats[i] >= 3) {
//      ++count;
//    }
//  }
//  return count;
//}
//
//int64_t CountTwoSame(int64_t* x_values, int64_t* x_repeats, int64_t k, int64_t size) {
//  int64_t count = 0;
//  int64_t j = 0;
//  for (int64_t i = 0; i < size; ++i) {
//    if (x_repeats[i] > 1) {
//      while (j < i && x_values[i] > x_values[j] * k) {
//        ++j;
//      }
//      count += 3 * (i - j);
//    }
//  }
//  j = size - 1;
//  for (int64_t i = j - 1; i >= 0; --i) {
//    if (x_repeats[i] > 1) {
//      while (j > i && x_values[i] * k < x_values[j]) {
//        --j;
//      }
//      count += 3 * (j - i);
//    }
//  }
//  return count;
//}
//
//int64_t CountDiffrent(int64_t* x_values, int64_t k, int64_t size) {
//  int64_t count = 0;
//  int64_t j = 0;
//  for (int64_t i = 0; i < size; ++i) {
//    while (j < i && x_values[i] > x_values[j] * k) {
//      ++j;
//    }
//    count += 6 * (i - j) * (i - j - 1) / 2;  // 6, так как можно 6 способами поиенять игроков
//  }
//  return count;
//}
//
//int main() {
//  int64_t n, k;
//  std::cin >> n >> k;
//  auto* x = new int64_t[n];
//  for (int64_t i = 0; i < n; ++i) {
//    std::cin >> x[i];
//  }
//  auto* x_values = new int64_t[n];
//  auto* x_repeats = new int64_t[n];
//  int64_t size = 1;
//  std::sort(x, x + n);
//  x_values[0] = x[0];
//  int64_t count = 1;
//  for (int64_t i = 1, j = 1; i < n; ++i) {
//    if (x[i - 1] != x[i]) {
//      x_repeats[j - 1] = count;
//      x_values[j] = x[i];
//      ++j;
//      count = 1;
//    } else {
//      ++count;
//    }
//    size = j;
//    if (i == n - 1) {
//      x_repeats[j - 1] = count;
//    }
//  }
//  int64_t case_1 = CountThreeSame(x_repeats, size);
//  int64_t case_2 = CountTwoSame(x_values, x_repeats, k, size);
//  int64_t case_3 = CountDiffrent(x_values, k, size);
//  std::cout << (case_1 + case_2 + case_3);
//  delete[] x;
//  delete[] x_values;
//  delete[] x_repeats;
//  return 0;
//}