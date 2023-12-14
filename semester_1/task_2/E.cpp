//#include <iostream>
//
//void Swap(int& a, int& b) {
//  int temp = a;
//  a = b;
//  b = temp;
//}
//void Sift(int& size, int* arr) {
//  int i = 0;
//  int right, left, parent;
//  while (2 * i + 2 < size) {
//    right = 2 * i + 2;
//    left = 2 * i + 1;
//    parent = left;
//    if (right < size - 1) {
//      if (arr[right] > arr[left]) {
//        parent = right;
//      }
//    }
//    if (arr[i] >= arr[parent]) {
//      break;
//    }
//    Swap(arr[i], arr[parent]);
//    i = parent;
//  }
//  std::cout << i + 1 << ' ';
//}
//void GetMax(int* arr, int& size) {
//  int left = 0;
//  int right = 0;
//  int parent = 0;
//  if (size <= 0) {
//    std::cout << -1 << std::endl;
//    return;
//  }
//  int max = *arr;
//  *arr = *(arr + size - 1);
//  if (size == 1) {
//    std::cout << 0 << " " << max << std::endl;
//    return;
//  }
//  Sift(size, arr);
//  std::cout << max << std::endl;
//  --size;
//}
//
//void Insert(int inseart_elem, int* arr, int& size, int max_size) {
//  if (size >= max_size) {
//    std::cout << -1 << std::endl;
//    return;
//  }
//  int i, parent;
//  i = size;
//  arr[i] = inseart_elem;
//  parent = (i - 1) / 2;
//  while (arr[i] > arr[parent]) {
//    Swap(arr[i], arr[parent]);
//    i = parent;
//    parent = (i - 1) / 2;
//  }
//  ++size;
//  std::cout << i + 1 << std::endl;
//}
//
//
//void DeleteElem(int argument, int* arr, int& size) {
//  if (size < argument || argument < 1) {
//    std::cout << -1 << std::endl;
//    return;
//  }
//  int left = 0;
//  int right = 0;
//  int point = 0;
//  int del = arr[argument - 1];
//  *(arr + argument - 1) = *(arr + size - 1);
//  int i = argument - 1;
//  --size;
//  while (2 * i + 1 < size) {
//    right = 2 * i + 2;
//    left = 2 * i + 1;
//    point = left;
//    if (right < size && arr[right] > arr[left]) {
//      point = right;
//    }
//    if (arr[i] >= arr[point]) {
//      break;
//    }
//    Swap(arr[i], arr[point]);
//    i = point;
//  }
//  i = argument - 1;
//  while (arr[i] > arr[(i - 1) / 2]) {
//    Swap(arr[i], arr[(i - 1) / 2]);
//    i = (i - 1) / 2;
//  }
//  std::cout << del << std::endl;
//}
//
//void Solution(int* arr, int n, int m) {
//  int size = 0;
//  int event;
//  int argument;
//  for (int i = 0; i < m; ++i) {
//    std::cin >> event;
//    if (event == 1) {
//      GetMax(arr, size);
//    } else {
//      if (event == 2) {
//        std::cin >> argument;
//        Insert(argument, arr, size, n);
//      } else {
//        if (event == 3) {
//          std::cin >> argument;
//          DeleteElem(argument, arr, size);
//        }
//      }
//    }
//  }
//  for (int i = 0; i < size; ++i) {
//    std::cout << arr[i] << ' ';
//  }
//}
//
//int main() {
//  int n;
//  int m;
//
//  std::cin >> n;
//  std::cin >> m;
//
//  int size;
//  auto arr = new int[n];
//  Solution(arr, n, m);
//  delete[] arr;
//  return 0;
//}