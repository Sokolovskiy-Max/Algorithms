//#include <iostream>
//struct Student {
//  int points = 100;
//  char name[80];
//};
//
//void Merge(Student* first_begin, Student* first_end, Student* second_begin, Student* second_end, Student* result) {
//  while (first_begin != first_end && second_begin != second_end) {
//    if (first_begin->points >= second_begin->points) {
//      *result++ = *first_begin++;
//    } else {
//      *result++ = *second_begin++;
//    }
//  }
//  while (first_begin != first_end) {
//    *result++ = *first_begin++;
//  }
//  while (second_begin != second_end) {
//    *result++ = *second_begin++;
//  }
//}
//
//Student* MergeSort(Student* begin, Student* end) {
//  if (end - begin == 1) {
//    auto* result = new Student[1];
//    *result = *begin;
//    return result;
//  }
//  Student* mid = begin + (end - begin) / 2;
//  Student* first_res = MergeSort(begin, mid);
//  Student* second_res = MergeSort(mid, end);
//  auto* result = new Student[end - begin];
//  Merge(first_res, first_res + (mid - begin), second_res, second_res + (end - mid), result);
//  delete[] first_res;
//  delete[] second_res;
//  return result;
//}
//
//int main() {
//  int n;
//  std::cin >> n;
//  auto* inf_points = new int[n];
//  auto* math_points = new int[n];
//  auto* rus_points = new int[n];
//  auto* mid = new double[n];
//  auto* students = new Student[n];
//  for (int i = 0; i < n; ++i) {
//    int spases = 0;
//    char a;
//    a = getchar();
//    int tmp = 0;
//    for (int j = 0; spases < 2; ++j) {
//      students[i].name[j] = a;
//      a = getchar();
//      if (a == ' ') {
//        ++spases;
//      }
//      tmp = j + 1;
//    }
//    students[i].name[tmp] = '\0';
//    std::cin >> inf_points[i] >> math_points[i] >> rus_points[i];
//    mid[i] = (inf_points[i] + math_points[i] + rus_points[i]);
//    students[i].points = mid[i];
//  }
//  auto* new_students = MergeSort(students, students + n);
//  for (int i = 0; i < n; ++i) {
//    std::cout << new_students[i].name;
//  }
//  delete[] new_students;
//  delete[] students;
//  delete[] mid;
//  delete[] inf_points;
//  delete[] rus_points;
//  delete[] math_points;
//  return 0;
//}
