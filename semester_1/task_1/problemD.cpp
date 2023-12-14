#include <iostream>
void F(int n,bool forw) {
  if (n == 1) {
    std::cout << 1 << ' ';
  } else {
    if (n == 2) {
      std::cout << 1 << ' ' << 2 << ' ';
    } else {
      int a = -1;
      int b = 3;
      F(2);
      for (int i = 0; i < n - 2; ++i) {
        /*if (a < -1) {
          F(-a - 1);
        }*/
        std::cout << a << ' ' << b << ' ';
        --a;
        ++b;
      }
      F(n - 2);
    }
  }
}
int main() {
  int n;
  std::cin >> n;
  F(n);
}
