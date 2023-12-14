//#include <iostream>
//void Solution() {
//  int n;
//  std::cin >> n;
//  int64_t a_last_count = 1;
//  int64_t bc_bast_count = 2;
//  for (int i = 1; i < n; ++i) {
//    int64_t tmp = a_last_count;
//    a_last_count = bc_bast_count;
//    bc_bast_count = tmp * 2 + bc_bast_count * 2;
//  }
//  std::cout << a_last_count + bc_bast_count;
//}
//int main() {
//  Solution();
//  return 0;
//}