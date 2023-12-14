#include <iostream>
int CheckCase(int** arr, int n, int m) {
  if (n == 1 || m == 1) {
    return 3;
  }
  int vertical = 0;
  int horizontal = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i][0] == 1 && arr[i][1] == 1) {
      ++horizontal;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (arr[0][i] == 1 && arr[1][i] == 1) {
      ++vertical;
    }
  }
  if (vertical > 0 && horizontal > 0) {
    return 0;
  }
  int delta_h = -1;
  int first_h = -1;
  int second_h = -1;
  if (horizontal > 1) {
    for (int i = 0; i < n; ++i) {
      if (arr[i][0] == 1 && arr[i][1] == 1 && first_h == -1) {
        first_h = i;
        continue;
      }
      if (arr[i][0] == 1 && arr[i][1] == 1 && first_h != -1) {
        second_h = i;
        break;
      }
    }
    delta_h = second_h - first_h - 1;
  }
  int delta_v = -1;
  int first_v = -1;
  int second_v = -1;
  if (vertical > 1) {
    for (int i = 0; i < m; ++i) {
      if (arr[0][i] == 1 && arr[1][i] == 1 && first_v == -1) {
        first_v = i;
        continue;
      }
      if (arr[0][i] == 1 && arr[1][i] == 1 && first_v != -1) {
        second_v = i;
        break;
      }
    }
    delta_v = second_v - first_v - 1;
  }
  if (vertical > 1 && delta_v < n) {
    return 1;
  }
  if (horizontal > 1 && delta_h < m) {
    return 2;
  }
  return 3;
}
int main() {
  int n, m;
  std::cin >> n >> m;
  auto** arr = new int*[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = new int[m];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      std::cin >> c;
      arr[i][j] = c - '0';
    }
  }
  int our_case = CheckCase(arr, n, m);
  switch (our_case) {
    case 0:
      std::cout << "Square";
      break;
    case 1:
      std::cout << "Vertical Line";
      break;
    case 2:
      std::cout << "Line";
      break;
    case 3:
      std::cout << "?";
      break;
    default:
      break;
  }
}