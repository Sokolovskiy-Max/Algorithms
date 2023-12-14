#include <cstdint>
#include <iostream>
#include "problemQ.h"

int main() {
  int32_t arr[19] = { 4, 2, 5, 7, 10, 4, 25, 25, 12, 87, 2, 5, 7, 10, 4, 25, 25, 12, 87 };
  for (int32_t i = 0; i < 10; ++i) {
    std::cout << arr[i] << ' ';
  }
  int32_t* res = MergeSort(arr, arr + 19);
  std::cout << std::endl;
  for (int32_t i = 0; i < 19; ++i) {
    std::cout << res[i] << ' ';
  }
  std::cout << std::endl;
  delete[] res;
  Sort(arr, arr+19);
  for (int32_t i = 0; i < 19; ++i) {
    std::cout << arr[i] << ' ';
  }
  return 0;
}

