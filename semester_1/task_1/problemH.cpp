#include <iostream>
void Decoder(char* code, int size) {
  for (int i = 0; i < size; i += 2) {
    std::cout << code[i];
  }
  int second_part_start = 0;
  size % 2 == 0 ? second_part_start = size - 1 : second_part_start = size-2;
  for (int i = second_part_start; i > 0; i -= 2) {
    std::cout << code[i];
  }
}
int main8() {
  char* code = new char[100000];
  char l = 'f';
  int i = 0;
  while (l != '#') {
    std:: cin >> l;
    code[i] = l;
    ++i;
  }
  int size = i - 1;
  char* newCode = new char[size];
  for (int i = 0; i < size; ++i) {
    newCode[i] = code[i];
  }
  Decoder(newCode, size);
  delete[] code;
  delete[] newCode;
  return 0;
}