#ifndef SORT_H
#define SORT_H

template <class T>
void KthElement(T* begin, T* kth, T* end) {
 end--;
  while (begin < end - 1) {
    T tmp = *kth;
    T* left = begin;
    T* right = end;
    while (left < right) {
      while (*left < tmp) {
        ++left;
      }
      while (tmp < *right) {
        --right;
      }
      if (left <= right) {
        T ttmp = *left;
        *left = *right;
        *right = ttmp;
        ++left;
        --right;
      }
    }
    if (right < kth) {
      begin = left;
    } 
    if (kth < left) {
      end = right;
    }
  }
}
#endif
