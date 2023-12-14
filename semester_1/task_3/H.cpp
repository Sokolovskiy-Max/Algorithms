//#include <iostream>
//#include <cmath>
//
//void MaxPow(int m, int* d, int& pow) {
//  d[0] = 0;
//  pow = m == 0 ? 1 : 0;
//  int pos = 0;
//  while (m > 0) {
//    d[pos++] = m % 4;
//    m /= 4;
//    ++pow;
//  }
//}
//
//int Weights(int m, int prefix, int max_pow, int* pows, int* pows_prefs) {
//  if (max_pow < 0) {
//    return prefix > m ? 0 : 1;
//  }
//  if (prefix + pows_prefs[max_pow] <= m) {
//    return std::pow(3, max_pow + 1);
//  }
//  if (prefix - pows_prefs[max_pow] > m) {
//    return 0;
//  }
//  int ans = 0;
//  ans += Weights(m, prefix - pows[max_pow], max_pow - 1, pows, pows_prefs);
//  ans += Weights(m, 0, max_pow - 1, pows, pows_prefs);
//  ans += Weights(m, prefix + pows[max_pow], max_pow - 1, pows, pows_prefs);
//  return ans;
//}
//
//int gen_nums(int m, int prefix, int pow4) {
//  if (pow4 < 0) {
//    return prefix > m ? 0 : 1;
//  }
//
//  if (prefix + pows_prefs[pow4] <= m) {
//    return my_pow(3, pow4 + 1);
//  }
//
//  if (prefix - pows_prefs[pow4] > m) {
//    return 0;
//  }
//
//  int v = pows[pow4], res = 0, k;
//  for (k = -1; k <= 1; ++k) {
//    res += gen_nums(m, prefix + v * k, pow4 - 1);
//  }
//  return res;
//}
//
//
//int Solution(int m, int n) {
//  auto* pows = new int[16];
//  auto* pows_prefs = new int[16];
//  auto* prefs = new int[16];
//  prefs[0] = pows_prefs[0] = pows[0] = 1;
//  for (int i = 1; i < 16; ++i) {
//    pows[i] = pows[i - 1] << 2;
//    pows_prefs[i] = pows_prefs[i - 1] + pows[i];
//    prefs[i] = prefs[i - 1] * 3 + 1;
//  }
//  int pow = 0;
//  auto* d = new int[20];
//  MaxPow(m, d, pow);
//  int max_pow;
//  max_pow = d[pow - 1] > 1 ? pow : pow - 1;
//  int ans;
//  if (max_pow + 1 > n) {
//    ans = prefs[n - 1];
//    delete[] pows;
//    delete[] pows_prefs;
//    delete[] prefs;
//    delete[] d;
//    return ans;
//  }
//  ans = Weights(m, pows[max_pow], max_pow - 1, pows, pows_prefs);
//  ans += max_pow > 0 ? prefs[max_pow - 1] : 0;
//  delete[] pows;
//  delete[] pows_prefs;
//  delete[] prefs;
//  delete[] d;
//  return ans;
//}
//
//int main() {
//  int m, n;
//  std::cin >> n >> m;
//  std::cout << Solution(m, n);
//  return 0;
//}