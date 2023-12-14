#include "problemR.h"
#include <iostream> 
int main() {
  int array[8]{ 9, 2, 3, 5, 4, 1, 1,3 };

  KthElement(array, array + 2, array + 8); // array = {1, 2, 3, 5, 4}
  for (int i = 0; i < 8; ++i) {
    std::cout << array[i] << ' ';
  }
}