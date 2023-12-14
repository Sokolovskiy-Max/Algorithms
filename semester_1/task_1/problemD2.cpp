#include <iostream>
void Erase(int n);
void Draw(int n) {
  if (n == 1) {
    std::cout << 1 << ' ';
    return;
  } else {
    if (n == 2) {
      std::cout << 1 << ' ' << 2 << ' ';
    } else {
      Draw(n - 1);
      Erase(n - 2);
      std::cout << n << ' ';
      Draw(n - 2);
      return;
    }
  }
}
void Erase(int n) {
  if (n == 1) {
    std::cout << -1 << ' ';
    return;
  } else {
    if (n == 2) {
      std::cout << -2 << ' ' << -1 << ' ';
    } else {
      Erase(n - 2);
      std::cout << -n << ' ';
      Draw(n - 2);
      Erase(n - 1);
      return;
    }
  }
}
int main11() {
  Draw(1);
  std::cout << std::endl;
  Draw(2);
  std::cout << std::endl;
  Draw(3);
  std::cout << std::endl;
  Draw(4);
  std::cout << std::endl;
  Draw(5);
  return 0;
}
