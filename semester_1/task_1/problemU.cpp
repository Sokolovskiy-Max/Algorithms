#include <iostream>
//делим строковое число на 2, остаток отбрасываем
char* DivTwo(char* string, int size) {
  int new_size = string[0] == '1' ? size : size + 1;
  auto* new_string = new char[new_size];
  int digit;
  int d = 0;
  for (int i = size - 1; i >= 0; i--) {
    digit = string[i] - '0';
    digit = digit * 5 + d;
    d = digit / 10;
    new_string[i + new_size - size] = digit % 10 + '0';
  }
  if (d != 0) {
    new_string[0] = d + '0';
  }
  new_string[new_size - 1] = '\0';
  return new_string;
}
//переводим строковое десятичное чило в строковое двоичное и сразу рекурсивно выводим
void FromDecimalToBinaty(char* string, int size) {
  if (string[0] == '1' && size == 1) {
    std::cout << '1';
  } else {
    auto* new_string = DivTwo(string, size);
    FromDecimalToBinaty(new_string, (string[0] == '1' ? size - 1 : size));
    delete[] new_string;
    std::cout << (string[size - 1] % 2 == 0 ? 0 : 1);
  }
}
void Read(char* string) {
  char simbol;
  simbol = getchar();
  int size = 0;
  for (int i = 0; simbol != '\n'; ++i) {
    string[i] = simbol;
    simbol = getchar();
    size = i;
  }
  string[size + 1] = '\n';
}
void PrintString(char* string) {
  for (int i = 0; string[i] != '\n'; ++i) {
    if (string[i] > 57 || string[i] < 48) {
      std::cout << string[i];
    } else {
      auto* number = new char[256];
      int size = 0;
      while (string[i] < 58 && string[i] > 47 && string[i] != '\n') {
        number[size] = string[i];
        ++size;
        ++i;
      }
      --i;
      FromDecimalToBinaty(number, size);
      delete[] number;
    }
  }
}
int main() {
  auto* string = new char[256];
  Read(string);
  PrintString(string);
  delete[] string;
  return 0;
}