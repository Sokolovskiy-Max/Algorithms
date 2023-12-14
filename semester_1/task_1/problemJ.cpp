#include <string>
#include <iostream>
//Уберем всякий мусор из строки и сделаем все буквы заглавными.
std::string MakeStrNormal(std::string s) {
  std::string new_s;
  for (char i : s) {
    if ('a' <= i && i <= 'z') {
      new_s += char(i + 'A' - 'a');
    } else {
      if ('A' <= i && i <= 'Z') {
        new_s += i;
      }
    }
  }
  return new_s;
}
void IsPanlindrome(std::string s) {
  std::string tmp = s;
  int error_position = 0;
  std::string palindrom;
  int error_count = 0;
  int i = (int(s.size())) / 2 - 1;
  int j = (int(s.size()) + 1) / 2;
  bool is_palindrime = true;
  for (i; i >= 0; --i, ++j) {
    if (s[i] != s[j]) {
      ++error_count;
      s[i] = s[j];
    }
    if (error_count > 1) {
      is_palindrime = false;
      break;
    }
  }
  if (is_palindrime) {
    std::cout << "YES" << std::endl;
    for (char i : s) {
      std::cout << i;
    }
    return;
  }
  std::string new_s;
  s = tmp;
  for (int del = 1; del < int(s.size()) + 1; ++del) {
    new_s = s.substr(0, del - 1) + s.substr(del, s.size() - del);
    bool is_palindrime = true;
    for (int i = 0, j = int(new_s.size()) - 1; i < j; ++i, --j) {
      if (new_s[i] != new_s[j]) {
        is_palindrime = false;
        break;
      }
    }
    if (is_palindrime) {
      std::cout << "YES" << std::endl;
      std::cout << new_s;
      return;
    }
  }
  std::cout << "NO";
}
int main() {
  std::string s;
  getline(std::cin, s);
  std::string new_s = MakeStrNormal(s);
  IsPanlindrome(new_s);
}