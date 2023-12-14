#include <iostream>
//проверяет можно ли разместить n фото:
bool Possibly(int64_t w, int64_t h, int64_t n, int64_t a) {
  return (int64_t(a / w) * int64_t(a / h) >= n);
}
int BinarySearch(int64_t w, int64_t h, int64_t n) {
  int64_t max = (w > h? w : h) * n;
  int64_t left = 0;
  int64_t right = max;
  //реализую бин поиск по ответу
  while (right - left > 0) {
    int64_t mid = (left + right) / 2;
    if (Possibly(w, h, n, mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}
int main() {
  int64_t w, h, n;
  std::cin >> w >> h >> n;
  std::cout << BinarySearch(w, h, n);
}