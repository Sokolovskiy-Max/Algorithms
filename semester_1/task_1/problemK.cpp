#include <iostream>
int64_t CountMethods(char* line, int size, int k) {
  int64_t count = 0;
  for (int i = 0; i < size - k + 1; ++i) {
    int64_t local_count = 0;
    for (int j = 0; j < size + 1; ++j) {
      if ((line[i + j] == line[i + j + k]) && line[i + j] != '?' && line[i + j + k] != '?') {
        ++local_count;
      } else {
        break;
      }
    }
    count += local_count * (local_count + 1) / 2;
    i += local_count;
  }
  return count;
}
int Read(char* line) {
  char a;
  a = getchar();
  int size = 0;
  for (int i = 0;; ++i) {
    a = getchar();
    if (a != '\n') {
      line[i] = a;
    } else {
      size = i;
      break;
    }
  }
  //добавю лишний символ в конец строки, чтоб можно было нормально проверять совпадения элементов
  line[size] = '?';
  return size;
}
int main() {
  int k;
  std::cin >> k;
  auto* line = new char[1000100];
  int size = Read(line);
  std::cout << CountMethods(line, size, k);
  delete[] line;
  return 0;
}