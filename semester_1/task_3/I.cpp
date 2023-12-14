//#include <iostream>
//
//int MinSteps(int n) {
//  auto* arr = new int[n + 1];
//  arr[1] = 0;
//  int m;
//  for (int i = 2; i < n + 1; i++) {
//    m = arr[i - 1] + 1;
//    if (i % 2 == 0) {
//      m = std::min(m, arr[i / 2] + 1);
//    }
//    if (i % 3 == 0) {
//      m = std::min(m, arr[i / 3] + 1);
//    }
//    arr[i] = m;
//  }
//  int tmp = arr[n];
//  delete[] arr;
//  return tmp;
//}
//int main() {
//  int n;
//  std::cin >> n;
//  std::cout << MinSteps(n);
//}