#include <iostream>
void Partition(int* arr, int pivot_idx, int left, int right, int& left_eq,
  int& right_eq) {
  std::swap(arr[left], arr[pivot_idx]);
  left_eq = left;
  right_eq = left_eq + 1;
  while (right_eq < right) {
    if (arr[right_eq] > arr[left_eq]) {
      std::swap(arr[right_eq], arr[--right]);
    } else if (arr[right_eq] < arr[left_eq]) {
      std::swap(arr[right_eq++], arr[left_eq++]);
    } else {
      ++right_eq;
    }
  }
}
void QuickSort(int* arr, int left, int right) {
  if (right - left < 2) {
    return;
  }
  int left_eq, right_eq;
  Partition(arr, left + rand() % (right - left), left, right, left_eq,
    right_eq);
  QuickSort(arr, left, left_eq);
  QuickSort(arr, right_eq, right);
}
std::pair<int*, int> MakeUnique(int* arr, int size) {
  int new_size = size;
  for (int i = 0; i < size - 1; ++i) {
    if (arr[i] == arr[i + 1]) {
      arr[i] = 1000000001;
      new_size -= 1;
    }
  }
  auto* unique = new int[new_size];
  int j = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i] != 1000000001) {
      unique[j] = arr[i];
      j++;
    }
  }
  return std::make_pair(unique, new_size);
}
int main() {
  int size1, size2;
  std::cin >> size1;
  auto* arr1 = new int[size1];
  for (int i = 0; i < size1; ++i) {
    std::cin >> arr1[i];
  }
  std::cin >> size2;
  auto* arr2 = new int[size2];
  for (int i = 0; i < size2; ++i) {
    std::cin >> arr2[i];
  }
  QuickSort(arr1, 0, size1);
   QuickSort(arr2, 0, size2);
  std::pair<int*, int> pair1 = MakeUnique(arr1, size1);
  std::pair<int*, int> pair2 = MakeUnique(arr2, size2);
  int new_size1 = pair1.second;
  int new_size2 = pair2.second;
  auto* new_arr1 = pair1.first;
  auto* new_arr2 = pair2.first;
  if (new_size1 != new_size2) {
    std::cout << "NO";
    delete[] arr1;
    delete[] arr2;
    delete[] new_arr1;
    delete[] new_arr2;
    return 0;
  }
  bool equal = true;
  for (int i = 0; i < new_size1; ++i) {
    if (new_arr1[i] != new_arr2[i]) {
      equal = false;
      break;
    }
  }
  if (equal) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  delete[] arr1;
  delete[] arr2;
  delete[] new_arr1;
  delete[] new_arr2;
  return 0;
}