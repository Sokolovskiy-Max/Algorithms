//#ifndef Heap_H
//#define Heap_H
//
//template <class T>
//void Swap(T& a, T& b) {
//  T tmp = a;
//  a = b;
//  b = tmp;
//}
//
//template <class T>
//void Heapify(T* begin, T* end, T* root) {
//  T* parent = root;
//  T* left = begin + 2 * (parent - begin) + 1;
//  T* right = begin + 2 * (parent - begin) + 2;
//
//  if ((left < end) && (*left > *parent)) {
//    parent = left;
//  }
//
//  if ((right < end) && (*right > *parent)) {
//    parent = right;
//  }
//
//  if (parent != root) {
//    Swap(*root, *parent);
//    Heapify(begin, end, parent);
//  }
//}
//
//template <class T>
//void MakeHeap(T* begin, T* end) {
//  for (int i = (end - begin) / 2 - 1; i >= 0; --i) {
//    Heapify(begin, end, begin + i);
//  }
//}
//
//template <class T>
//void SortHeap(T* begin, T* end) {
//  for (int i = (end - begin) / 2 - 1; i >= 0; --i) {
//    Heapify(begin, end, begin + i);
//  }
//  for (int i = end - begin - 1; i >= 0; --i) {
//    Swap(*begin, *(begin + i));
//    Heapify(begin, begin + i, begin);
//  }
//}
//
//#endif