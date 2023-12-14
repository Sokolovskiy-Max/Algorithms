#include <iostream>
int size = 0;
void Merge(int* all_arr, int begin, int end, int mid) {
  int i = begin;
  int j = mid;
  auto* tmp = new int[end - begin];
  int last = 0;
  for (int k = 0; i < mid && j < end; ++k) {
    if (all_arr[i] <= all_arr[j]) {
      tmp[k] = all_arr[i];
      ++i;
    } else {
      tmp[k] = all_arr[j];
      ++j;
    }
    last = k;
  }
  ++last;
  for (int k = last; i < mid; ++k) {
    tmp[k] = all_arr[i];
    ++i;
  }
  for (int k = last; j < end; ++k) {
    tmp[k] = all_arr[j];
    ++j;
  }
  for (int p = 0; p < end - begin; ++p) {
    all_arr[p + begin] = tmp[p];
  }
  delete[] tmp;
}
void ReductionSeparators(int k, int* separator) {
  auto* tmp_separator = new int[k + 1];
  for (int i = 0; i <= k; i += 2) {
    separator[i / 2] = separator[i];
  }
  if (k % 2 != 0) {
    separator[(k + 1) / 2] = separator[k];
  }
  delete[] tmp_separator;
}
void MergeAll(int k, int* all_arrs, int* separator) {
  if (k == 1) {
    return;
  }
  for (int i = 0; i < k - 1; i += 2) {
    Merge(all_arrs, separator[i], separator[i + 2], separator[i + 1]);
  }
  while (k != 1) {
    ReductionSeparators(k, separator);
    k = (k + 1) / 2;
    if (k > 1) {
      for (int i = 0; i < k - 1; i += 2) {
        Merge(all_arrs, separator[i], separator[i + 2], separator[i + 1]);
      }
    }
  }
  for (int i = 0; i < size; ++i) {
    std::cout << all_arrs[i] << ' ';
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k;
  auto* all_arrs = new int[1000000];
  std::cin >> k;
  auto* separator = new int[k + 1];
  separator[0] = 0;
  for (int i = 0; i < k; ++i) {
    std::cin >> n;
    for (int j = separator[i]; j < separator[i] + n; ++j) {
      std::cin >> all_arrs[j];
    }
    separator[i + 1] = separator[i] + n;
  }
  size = separator[k];
  MergeAll(k, all_arrs, separator);
  delete[] separator;
  delete[] all_arrs;
  return 0;
}