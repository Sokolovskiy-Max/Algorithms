//#include <iostream>
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
//
//  }
//}
//
//template <class T>
//void MakeHeap(T* begin,T* end) {
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
//int main() {
//  int arr[6] = { 3, 1, 4, 1, 5, 9 };
//  for (int i = 0; i < 6; ++i) {
//    std::cout << arr[i] << ' ';
//  }
//  std::cout << std::endl;
//  MakeHeap(arr, arr + 6); // arr == [9, 4, 5, 1, 1, 3]
//  for (int i = 0; i < 6; ++i) {
//    std::cout << arr[i] << ' ';
//  }
//  std::cout << std::endl;
//
//  SortHeap(arr, arr + 6); // arr == [1, 1, 3, 4, 5, 9]
//
//  for (int i = 0; i < 6; ++i) {
//    std::cout << arr[i] << ' ';
//  }
//  return 0;
//}