#ifndef STRING_H
#define STRING_H
#include <stdexcept>
class StringViewOutOfRange : public std::out_of_range {
 public:
  StringViewOutOfRange() : std::out_of_range("StringViewOutOfRange") {
  }
};

class StringView {
 private:
  size_t size_;
  const char* ptr_;

 public:
  StringView();

  StringView(const char* ptr);  // NOLINT"

  StringView(const char* ptr, size_t size);

  const char& operator[](size_t idx) const;

  const char& At(size_t idx) const;

  const char& Front() const;

  const char& Back() const;

  size_t Size() const;

  size_t Length() const;

  bool Empty() const;

  const char* Data() const;


  void Swap(StringView&);

  void RemovePrefix(size_t prefix_size);

  void RemoveSuffix(size_t suffix_size);

  StringView Substr(size_t pos, size_t count = -1);
};