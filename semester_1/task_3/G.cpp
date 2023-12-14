//#include <iostream>
//
//int main() {
//  int m;
//  std::cin >> m;
//  auto* string = new char[1000];
//  char a = getchar();
//  a = getchar();
//  int size = 0;
//  for (int i = 0; a != '\n'; ++i) {
//    string[i] = a;
//    a = getchar();
//    ++size;
//  }
//  int first_nulls = 0;
//  while (string[first_nulls] - '0' == 0) {
//    ++first_nulls;
//  }
//  auto* arr = new int[100000];
//  int d = 0;
//  for (first_nulls; first_nulls < size; ++first_nulls) {
//    if (string[first_nulls] - '0' == 0) {
//      d++;
//      if (d > 4) {
//        continue;
//      }
//      a.push_back(0);
//      continue;
//    }
//    a.push_back(string[first_nulls] - '0');
//    d = 0;
//  }
//
//  N = a.size();
//  vector <vector <bool> > p(N, vector <bool>(20001, false));
//  vector <vector <int> > last(N, vector<int>(5));
//  p[0][10000 + a[0]] = true;
//  p[0][10000 - a[0]] = true;
//  last[0][1] = a[0];
//
//  for (int i = 1; i < N; ++i) {
//    for (int k = 1; k < 6 && k <= i; ++k) {
//      last[i][k] = last[i - 1][k - 1] * 10 + a[i];
//
//    }
//    if (i < 5) {
//      last[i][i + 1] = last[i - 1][i] * 10 + a[i];
//    }
//    for (int j = 0; j <= 20000; ++j) {
//      for (int k = 1; k < 6 && k <= i; ++k) {
//        if (j - last[i][k] >= 0 && p[i - k][j - last[i][k]] == true) {
//          p[i][j] = true;
//        }
//        if (j + last[i][k] <= 20000 && p[i - k][j + last[i][k]] == true) {
//          p[i][j] = true;
//        }
//      }
//    }
//    if (i < 5) {
//      if (last[i][i + 1] <= 10000) {
//        p[i][10000 - last[i][i + 1]] = true;
//        p[i][10000 + last[i][i + 1]] = true;
//      }
//    }
//  }
//  for (int k = 1; k < 6 && k < N; ++k) {
//    if (M <= 10000 && M >= -10000 && p[N - 1][M + 10000] == true) {
//      cout << "YES";
//      return 0;
//    }
//
//  }
//  if (N < 6) {
//    if (last[N - 1][N] == M) {
//      cout << "YES";
//      return 0;
//    }
//    if (-last[N - 1][N] == M) {
//      cout << "YES";
//      return 0;
//    }
//  }
//  cout << "NO";
//  return 0;
//}