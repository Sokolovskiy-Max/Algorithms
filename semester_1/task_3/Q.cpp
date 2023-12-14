//#include <iostream>
//void Solution() {
//  int x, y, h, w;
//  std::cin >> x;
//  std::cin >> y;
//  std::cin >> h;
//  std::cin >> w;
//  auto** a = new int* [x];
//  for (int i = 0; i < x; ++i) {
//    a[i] = new int[y];
//  }
//  for (int i = 0; i < x; ++i) {
//    for (int j = 0; j < y; ++j) {
//      std::cin >> a[i][j];
//    }
//  }
//  int width_pos = 0;
//  int height_pos = 0;
//  int new_width_pos = 0;
//  int new_height_pos = 0;
//  while (true) {
//    int max_num = -1;
//    for (int i = height_pos; i < std::min(height_pos + h, x); ++i) {
//      for (int j = width_pos; j < std::min(width_pos + w, y); ++j) {
//        if (!(height_pos == i && width_pos == j) && max_num < a[i][j]) {
//          new_height_pos = i;
//          new_width_pos = j;
//          max_num = a[i][j];
//        }
//      }
//    }
//    height_pos = new_height_pos;
//    width_pos = new_width_pos;
//    if (width_pos == new_width_pos && height_pos == new_height_pos) {
//      std::cout << height_pos << ' ' << width_pos;
//      break;
//    }
//  }
//  for (int i = 0; i < x; ++i) {
//    delete[] a[i];
//  }
//  delete[] a;
//}
//int main() {
//  Solution();
//  return 0;
//}