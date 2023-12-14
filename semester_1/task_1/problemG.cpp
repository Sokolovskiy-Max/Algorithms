#include <iostream>
// перекладываем пирамиду из n дисков с start_core_num на end_core_num
void f(int n, int start_core_num, int end_core_num) {
  if (n == 1) {
    std::cout << "1 " << start_core_num << ' ' << end_core_num << std::endl;
  } else {
    if (n == 2) {
      std::cout << "1 " << start_core_num << ' ' << end_core_num << std::endl;
      std::cout << "2 " << start_core_num << ' ' << 2 << std::endl;
      std::cout << "1 " << end_core_num << ' ' << start_core_num << std::endl;
      std::cout << "2 " << 2 << ' ' << end_core_num << std::endl;
      std::cout << "1 " << start_core_num << ' ' << end_core_num << std::endl;
    } else {
      f(n - 1, start_core_num, end_core_num);
      std::cout << n << ' '  << start_core_num <<  " 2" << std::endl;
      f(n - 1, end_core_num, start_core_num);
      std::cout << n << ' ' << "2 " << end_core_num << std::endl;
      f(n - 1, start_core_num, end_core_num);
    }
  }
}
int main() {
  int n;
  std::cin >> n;
  f(n, 1, 3);
  return 0;
}