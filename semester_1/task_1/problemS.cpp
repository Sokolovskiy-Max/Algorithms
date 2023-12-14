#include "problemS.h"
#include <iostream>
int main() {
  int heap[7]{ 9, 5, 4, 1, 2, 3, 6 };

  PushHeap(heap, heap + 7); // heap == {9, 5, 6, 1, 2, 3, 4} (вставили 6)

  for (int i = 0; i < 7; ++i) {
    std::cout << heap[i] << ' ';
  }
  std::cout << std::endl;
  PopHeap(heap, heap + 7); // heap == {6, 5, 4, 1, 2, 3, 9} (извлекли 9)
  for (int i = 0; i < 7; ++i) {
    std::cout << heap[i] << ' ';
  }
  int heap1[1]{ 9};
  std::cout << std::endl;
  PushHeap(heap, heap + 1); // heap == {9, 5, 6, 1, 2, 3, 4} (вставили 6)

  for (int i = 0; i < 1; ++i) {
    std::cout << heap[i] << ' ';
  }
  std::cout << std::endl;
  PopHeap(heap, heap + 1); // heap == {6, 5, 4, 1, 2, 3, 9} (извлекли 9)
  for (int i = 0; i < 1; ++i) {
    std::cout << heap[i] << ' ';
  }

}