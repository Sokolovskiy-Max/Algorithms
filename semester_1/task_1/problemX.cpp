#include <iostream>
int m, n, q;
void ReadVL(int* v, int* l) {
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> l[i];
  }
}
void ReadAF(int* a, int* f) {
  a[0] = 0;
  for (int i = 1; i < m; ++i) {
    std::cin >> a[i];
  }
  f[0] = 0;
  for (int i = 1; i < m + 1; ++i) {
    std::cin >> f[i];
  }
}
void ReadST(int* s, int* t) {
  for (int i = 0; i < q; ++i) {
    std::cin >> s[i];
    std::cin >> t[i];
  }
}
bool Possibly(int s, int t, int* v, int* l, int e) {
  double min_time = 0;
  for (int i = 0; i < n; ++i) {
    min_time += double(l[i]) / double(v[i] + e);
  }
  return (min_time <= t - s);
}
void BinarySearch(int s, int t, int* v, int* l, int* a, int* f) {
  //реализую бин поиск по ответу
  int left = -1;
  int right = m;
  while (right - left > 1) {
    int mid = left + (right - left) / 2;

    if (Possibly(s, t, v, l, a[mid])) {
      right = mid;
    } else {
      left = mid;
    }
  }
  std::cout << f[right] << "\n";
}
void SolutionForAllCars(int* v, int* l, int* a, int* f, int* s, int* t) {
  for (int i = 0; i < q; ++i) {
    BinarySearch(s[i], t[i], v, l, a, f);
  }
}
int main() {
  std::cin >> n;
  int* v = new int[n];
  int* l = new int[n];
  ReadVL(v, l);
  std::cin >> m;
  int* a = new int[m];
  int* f = new int[m + 1];
  ReadAF(a, f);
  std::cin >> q;
  int* s = new int[q];
  int* t = new int[q];
  ReadST(s, t);
  SolutionForAllCars(v, l, a, f, s, t);
  delete[] v;
  delete[] l;
  delete[] a;
  delete[] f;
  delete[] s;
  delete[] t;
}