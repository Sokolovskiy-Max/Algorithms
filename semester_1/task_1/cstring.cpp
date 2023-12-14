#include "cstring.h"
#include <iostream>
size_t Strlen(const char* str) {
  size_t size = 0;
  while (str[size] != '\0') {
    ++size;
  }
  return size;
}
int Strcmp(const char* first, const char* second) {
  size_t min = Strlen(first) < Strlen(second) ? Strlen(first) : Strlen(second);
  for (size_t i = 0; i < min; ++i) {
    if (first[i] < second[i]) {
      return -1;
    }
    if (first[i] > second[i]) {
      return 1;
    }
  }
  if (Strlen(first) == Strlen(second)) {
    return 0;
  }
  return (Strlen(first) < Strlen(second) ? -1 : 1);
}
int Strncmp(const char* first, const char* second, size_t count) {
  size_t min = Strlen(first) < Strlen(second) ? Strlen(first) : Strlen(second);
  size_t minimum = (min < count ? min : count);
  for (size_t i = 0; i < minimum; ++i) {
    if (first[i] < second[i]) {
      return -1;
    }
    if (first[i] > second[i]) {
      return 1;
    }
  }
  if (Strlen(first) < count || Strlen(second) < count) {
    if (Strlen(first) > minimum && Strlen(second) == minimum) {
      return 1;
    }
    if (Strlen(second) > minimum && Strlen(first) == minimum) {
      return -1;
    }
  }
  return 0;
}
char* Strcpy(char* dest, const char* src) {
  size_t size = Strlen(src);
  for (size_t i = 0; i < size; ++i) {
    dest[i] = src[i];
  }
  dest[size] = '\0';
  return dest;
}
char* Strncpy(char* dest, const char* src, size_t count) {
  size_t size = Strlen(src);
  for (size_t i = 0; i < count; ++i) {
    if (i < size) {
      dest[i] = src[i];
    } else {
      dest[i] = '\0';
    }
  }
  return dest;
}
char* Strcat(char* dest, const char* src) {
  size_t size_dest = Strlen(dest);
  size_t size_src = Strlen(src);
  for (size_t i = 0; i < size_src; ++i) {
    dest[i + size_dest] = src[i];
  }
  dest[size_dest + size_src] = '\0';
  return dest;
}
char* Strncat(char* dest, const char* src, size_t count) {
  size_t size_dest = Strlen(dest);
  size_t size_src = Strlen(src);
  if (count >= size_src) {
    return Strcat(dest, src);
  }
  for (size_t i = 0; i < count; ++i) {
    dest[i + size_dest] = src[i];
  }
  dest[size_dest + size_src] = '\0';
  return dest;
}
const char* Strchr(const char* str, char symbol) {
  for (size_t i = 0; i <= Strlen(str); ++i) {
    if (str[i] == symbol) {
      return (str + i);
    }
  }
  return nullptr;
}
const char* Strrchr(const char* str, char symbol) {
  for (int i = Strlen(str); i >= 0; --i) {
    if (str[i] == symbol) {
      return (str + i);
    }
  }
  return nullptr;
}
size_t Strspn(const char* dest, const char* src) {
  size_t count = 0;
  for (size_t i = 0; i < Strlen(dest); ++i) {
    if (Strchr(src, dest[i]) == nullptr) {
      break;
    }
    ++count;
  }
  return count;
}
size_t Strcspn(const char* dest, const char* src) {
  size_t count = 0;
  for (size_t i = 0; i < Strlen(dest); ++i) {
    if (Strchr(src, dest[i]) != nullptr) {
      break;
    }
    ++count;
  }
  return count;
}
const char* Strpbrk(const char* dest, const char* breakset) {
  size_t size_dest = Strlen(dest);
  for (size_t i = 0; i < size_dest; ++i) {
    if (Strchr(breakset, dest[i]) != nullptr) {
      return (dest + i);
    }
  }
  return nullptr;
}
const char* Strstr(const char* str, const char* pattern) {
  if (*pattern == '\0') {
    return str;
  }
  const char* ptr = nullptr;
  bool is_in;
  for (size_t i = 0; i < Strlen(str); ++i) {
    if (Strlen(pattern) <= Strlen(str) - i) {
      is_in = true;
      for (size_t j = 0; j < Strlen(pattern); ++j) {
        if (str[i + j] != pattern[j]) {
          is_in = false;
          break;
        }
      }
    }
    if (is_in) {
      ptr = str + i;
      return ptr;
    }
  }
  return ptr;
}