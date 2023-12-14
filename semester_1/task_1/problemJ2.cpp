#include <string>
#include <iostream>
int size = 0;
int new_size = 0;
//Уберем всякий мусор из строки и сделаем все буквы заглавными.
void MakeStrNormal(char* string, char* new_string) {
  for (int i = 0; i < size; ++i) {
    if ('a' <= string[i] && string[i] <= 'z') {
      new_string[new_size] = char(string[i] + 'A' - 'a');
      ++new_size;
    } else {
      if ('A' <= string[i] && string[i] <= 'Z') {
        new_string[new_size] = string[i];
        ++new_size;
      }
    }
  }
}
void IsPanlindrome(char* string) {
  int error_count = 0;
  int erroe_position = -1;
  bool is_palindrime = true;
  for (int i = 0, j = new_size - 1; i < j; ++i, --j) {
    if (string[i] != string[j]) {
      ++error_count;
      erroe_position = i;
    }
    if (error_count > 1) {
      is_palindrime = false;
      break;
    }
  }
  if (is_palindrime) {
    std::cout << "YES" << std::endl;
    for (int i = 0; i < new_size; ++i) {
      if (i != erroe_position) {
        std::cout << string[i];
      } else {
        std::cout << string[new_size - 1 - erroe_position];
      }
    }
    return;
  }
  for (int j = 0; j < new_size; ++j) {
    bool is_palindrime = true;
    for (int i = 0, k = new_size - 1; i < k; ++i, --k) {
      if (i == j) {
        ++i;
      }
      if (k == j) {
        --k;
      }
      if (string[i] != string[k]) {
        is_palindrime = false;
        break;
      }
    }
    if (is_palindrime) {
      std::cout << "YES" << std::endl;
      for (int k = 0; k < new_size; ++k) {
        if (k != j) {
          std::cout << string[k];
        }
      }
      return;
    }
  }
  std::cout << "NO";
}
void Read(char* string) {
  char a;
  for (int i = 0;; ++i) {
    a = getchar();
    if (a != '\n') {
      string[i] = a;
    } else {
      size = i;
      break;
    }
  }
}
int main() {
  auto* string = new char[100001];
  auto* new_string = new char[100001];
  Read(string);
  MakeStrNormal(string, new_string);
  IsPanlindrome(new_string);
  delete[] string;
  delete[] new_string;
  return 0;
}