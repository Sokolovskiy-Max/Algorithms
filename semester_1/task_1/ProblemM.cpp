#include <cstdint>
#include <iostream>
void Merge(int* first_begin, int* first_end, int* second_begin, int* second_end,
  int* result, int64_t& count) {
  while (first_begin != first_end && second_begin != second_end) {
    if (*first_begin <= *second_begin) {
      *result++ = *first_begin++;
    } else {
      *result++ = *second_begin++;
      count += first_end - first_begin;
    }
  }
  while (first_begin != first_end) {
    *result++ = *first_begin++;
  }
  while (second_begin != second_end) {
    *result++ = *second_begin++;
  }
}
int* MergeSort(int* begin, int* end, int64_t& count) {
  if (end - begin == 1) {
    int* result = new int[1];
    *result = *begin;
    return result;
  }
  int* mid = begin + (end - begin) / 2;
  int* first_res = MergeSort(begin, mid, count);
  int* second_res = MergeSort(mid, end, count);
  int* result = new int[end - begin];
  Merge(first_res, first_res + (mid - begin), second_res,
    second_res + (end - mid), result, count);
  delete[] first_res;
  delete[] second_res;
  return result;
}
int main() {
  int64_t count = 0;
  int n;
  std::cin >> n;
  auto* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  auto* res = MergeSort(arr, arr + n, count);
  std::cout << count;
  delete[] arr;
  delete[] res;
  return 0;
}

