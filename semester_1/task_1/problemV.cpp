#include <iostream>
template <class T>
void Merge(T* first_begin, T* first_end, T* second_begin, T* second_end, T* result) {
  while (first_begin != first_end && second_begin != second_end) {
    if (*first_begin <= *second_begin) {
      *result++ = *first_begin++;
    } else {
      *result++ = *second_begin++;
    }
  }
  while (first_begin != first_end) {
    *result++ = *first_begin++;
  }
  while (second_begin != second_end) {
    *result++ = *second_begin++;
  }
}

template <class T>
T* MergeSort(T* begin, T* end) {
  if (end - begin == 1) {
    auto* result = new T[1];
    *result = *begin;
    return result;
  }
  T* mid = begin + (end - begin) / 2;
  T* first_res = MergeSort(begin, mid);
  T* second_res = MergeSort(mid, end);
  auto* result = new T[end - begin];
  Merge(first_res, first_res + (mid - begin), second_res, second_res + (end - mid), result);
  delete[] first_res;
  delete[] second_res;
  return result;
}

template <class T>
void Sort(T* begin, T* end) {
  int l = end - begin;
  T* ans = MergeSort(begin, end);
  for (int i = 0; i < l; ++i) {
    *begin++ = ans[i];
  }
  delete[] ans;
}
int main() {
  int n;
  std::cin >> n;
  auto* a = new int[n];
  int all_sum = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    all_sum += a[i];
  }
  Sort(a, a + n);
  int count = 2;
  int sum = 0;
  int max_count = 0;
  int max_sum = 0;
  int elements_not_in_sum = 0;
  if (n == 1) {
    std::cout << 1 << ' ' << a[0];
    delete[] a;
    return 0;
  }
  max_count = 2;
  max_sum = a[n - 1] + a[n - 2];
  sum = max_sum + a[n - 1];
  int previos_right_pos = n - 1;
  int previos_left_pos = n - 3;
  for (int i = previos_right_pos; i > 1; --i) {
    elements_not_in_sum += a[i];
    sum -= a[previos_right_pos];
    for (int j = previos_left_pos; j >= 0; --j) {
      if (a[j] + a[j + 1] >= a[i]) {
        sum += a[j];
      } else {
        previos_left_pos = j ;
        count = i - j - 1;
        break;
      }
    }
    if (sum > max_sum) {
      max_sum = sum;
      max_count = (count + 1) * count / 2;
    }
    if (max_sum + elements_not_in_sum >= all_sum) {
      break;
    }
    previos_right_pos = i;
  }
  std::cout << max_count << ' ' << max_sum;
  delete[] a;
  return 0;
}