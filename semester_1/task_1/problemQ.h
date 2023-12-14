#ifndef SORT_H
#define SORT_H

template <class T>
void Merge(T* first_begin, T* first_end, T* second_begin, T* second_end,
  T* result) {
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
    T* result = new T[1];
    *result = *begin;
    return result;
  }
  T* mid = begin + (end - begin) / 2;
  T* first_res = MergeSort(begin, mid);
  T* second_res = MergeSort(mid, end);
  T* result = new T[end - begin];
  Merge(first_res, first_res + (mid - begin), second_res,
    second_res + (end - mid), result);
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
#endif
