#ifndef Heap_H
#define Heap_H

template <class T>
void Swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}
template <class T>
void PushHeap(T* begin, T* end) {
  T* elem_to_insert = end - 1;
  T* parent = begin + (elem_to_insert - begin - 1) / 2;
  while ((begin < elem_to_insert) && (*parent < *elem_to_insert)) {
    Swap(*elem_to_insert, *parent);
    elem_to_insert = parent;
    parent = begin + (elem_to_insert - begin - 1) / 2;
  }
}

template <class T>
void PopHeap(T* begin, T* end) {
  T tmp = *begin;
  *begin = *(end - 1);
  *(end - 1) = tmp;
  T* parent = begin;
  T* left_child = begin + 2 * (parent - begin) + 1;
  T* right_child = begin + 2 * (parent - begin) + 2;
  T* max = (*left_child < *right_child ? right_child : left_child);
  while ((left_child < end - 1) && (right_child < end - 1) && (*parent < *left_child || *parent < *right_child)) {
    max = (*left_child < *right_child ? right_child : left_child);
    T tmp = *parent;
    *parent = *max;
    *max = tmp;
    parent = max;
    left_child = begin + 2 * (parent - begin) + 1;
    right_child = begin + 2 * (parent - begin) + 2;
  }
  while ((left_child < end - 1) && *parent < *left_child) {
    T tmp = *parent;
    *parent = *left_child;
    *left_child = tmp;
    parent = left_child;
    left_child = begin + 2 * (parent - begin) + 1;
  }
  while ((right_child < end - 1) && *parent < *right_child) {
    T tmp = *parent;
    *parent = *right_child;
    *right_child = tmp;
    parent = right_child;
    right_child = begin + 2 * (parent - begin) + 1;
  }
}
#endif