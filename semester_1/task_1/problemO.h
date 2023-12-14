#ifndef BINARU_SEARC_H
#define BINARU_SEARC_H
template <class T>
bool BinarySearch(T* begin, T* end, T& value) {
  T* mid;
  T* left = begin;
  T* right = end;
  --left;
  while (left < right - 1) {
    mid = right - (right - left) / 2;
    if (!(*mid < value) && !(value < *mid)) {
      return true;
    }
    if (value < *mid) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return false;
}
template <class T>
T* LowerBound(T* begin, T* end, T& value) {
  T* mid;
  T* left = begin;
  T* right = end;
  while (left < right - 1) {
    mid = right - (right - left) / 2;
    if (value < *mid) {
      right = mid;
    } else {
      ++left;
    }
  }
  return left;
}
template <class T>
T* UpperBound(T* begin, T* end, T& value) {
  T* mid;
  T* left = begin;
  T* right = end;
  while (left < right - 1) {
    mid = right - (right - left) / 2;
    if (!(*mid < value)) {
      right = mid;
    } else {
      ++left;
    }
  }
  return left;
}
#endif