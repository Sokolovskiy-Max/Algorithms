#include "problemO.h"
#include <iostream>
int main() {
  int n, value;
  std::cin >> n >> value;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  std::cout << BinarySearch(arr, arr + n, value);
}