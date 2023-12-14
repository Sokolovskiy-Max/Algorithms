#include <iostream>
void rec(int depth, int size, bool* line, bool* height, bool* ldiag, bool* rdiag, int& rcount) {
  if (depth < size) {
    for (int i = 0; i < size; ++i) {
      if (line[i] == 0 && height[i] == 0 && ldiag[i + depth] == 0 && rdiag[size - i + depth] == 0) {
        line[i] = 1;
        height[i] = 1;
        ldiag[i + depth] = 1;
        rdiag[size - i + depth] = 1;
        rec(depth + 1, size, line, height, ldiag, rdiag, rcount);
        line[i] = 0;
        height[i] = 0;
        ldiag[i + depth] = 0;
        rdiag[size - i + depth] = 0;
      }
    }
  }
  if (depth == size - 1) {
    for (int i = 0; i < size; ++i) {
      if (line[i] == 0 && height[i] == 0 && ldiag[i + depth] == 0 && rdiag[size - i + depth] == 0) {
        ++rcount;
      }
    }
    return;
  }
}
int main1() {
  int n;
  std::cin >> n;
  bool* line = new bool[n];
  bool* height = new bool[n];
  bool* ldiag = new bool[2 * n + 1];
  bool* rdiag = new bool[2 * n + 1];
  for (int i = 0; i < n; ++i) {
    line[i] = 0;
    height[i] = 0;
    ldiag[i] = 0;
    rdiag[i] = 0;
    ldiag[i + n] = 0;
    rdiag[i + n] = 0;
  }
  ldiag[2 * n] = 0;
  rdiag[2 * n] = 0;
  int count = 0;
  int& rcount = count;
  rec(0, n, line, height, ldiag, rdiag, rcount);
  std::cout << count;
  return 0;
}