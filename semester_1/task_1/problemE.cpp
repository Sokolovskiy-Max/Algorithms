#include <iostream>
// перекладываем пирамиду из n дисков с startCoreNum на endCoreNum
void F(int n, int start_core_num, int end_core_num, int reserve) {
  if (n == 1) {
    std::cout << "1 " << start_core_num << ' ' << end_core_num << std::endl;
  } else {
    F(n - 1, start_core_num, reserve, end_core_num);
    std::cout << n << ' ' << start_core_num << ' ' << end_core_num << std::endl;
    F(n - 1, reserve, end_core_num, start_core_num);
  //}
}
int main() {
  int n;
  std::cin >> n;
  F(n, 1, 3, 2);
  return 0;
}