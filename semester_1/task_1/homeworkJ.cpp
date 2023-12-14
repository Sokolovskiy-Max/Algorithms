#include <iostream>
int CountNeighbour(int p, int q, int** arr) {
  int k = 0;
  if (arr[p][q + 1] == 1) {
    ++k;
  }
  if (arr[p][q - 1] == 1) {
    ++k;
  }
  if (arr[p + 1][q] == 1) {
    ++k;
  }
  if (arr[p - 1][q] == 1) {
    ++k;
  }
  if (arr[p - 1][q - 1] == 1) {
    ++k;
  }
  if (arr[p + 1][q + 1] == 1) {
    ++k;
  }
  if (arr[p + 1][q - 1] == 1) {
    ++k;
  }
  if (arr[p - 1][q + 1] == 1) {
    ++k;
  }
  return k;
}
void OneSecondChange(int** narr, int**arr, int n) {
  for (int p = 1; p < n + 1; p++) {
    for (int q = 1; q < n + 1; q++) {
      int k = CountNeighbour(p, q, arr);
      if (arr[p][q] == 1) {
        if (k < 2 || k > 3) {
          narr[p][q] = 0;
        } else {
          narr[p][q] = 1;
        }
      } else {
        if (k == 3) {
          narr[p][q] = 1;
        } else {
          narr[p][q] = 0;
        }
      }
    }
  }
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < n + 1; ++j) {
      arr[i][j] = narr[i][j];
    }
  }
}
void MainSolution(int** arr, int t, int n) {
  auto** narr = new int*[n + 2];
  for (int i = 0; i < n + 2; ++i) {
    narr[i] = new int[n + 2];
  }
  for (int time = 0; time < t; time++) {
    OneSecondChange(narr, arr, n);
  }
}
int main() {
  int n, t;
  std::cin >> n >> t;
  auto** arr = new int*[n + 2];
  for (int i = 0; i < n + 2; ++i) {
    arr[i] = new int[n + 2];
  }
  for (int i = 0; i < n + 2; ++i) {
    arr[0][i] = 0;
    arr[n + 1][i] = 0;
    arr[i][0] = 0;
    arr[i][n + 1] = 0;
  }
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < n + 1; ++j) {
      std::cin >> arr[i][j];
    }
  }
  auto** narr = new int* [n + 2];
  for (int i = 0; i < n + 2; ++i) {
    narr[i] = new int[n + 2];
  }
  MainSolution(arr, t, n);
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < n + 1; ++j) {
      std::cout << arr[i][j] << ' ';
    }
    if (i != n) {
      std::cout << std::endl;
    }
  }
  for (int i = 0; i < n + 2; ++i) {
    delete[] arr[i];
  }
  delete[] arr;
  return 0;
}