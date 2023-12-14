//#ifndef ARRAY 
//#define ARRAY 
//
//#include <iostream> 
//#include <stdexcept> 
//
//class ArrayOutOfRange : public std::out_of_range {
//public:
//  ArrayOutOfRange() : std::out_of_range("ArrayOutOfRange") {
//  }
//};
//
//template <class T, size_t SIZE>
//class Array {
//public:
//  T my_arr[SIZE];
//
//  T& operator[](size_t idx);
//  const T& operator[](size_t idx) const;
//
//  const T& At(size_t idx) const;
//  T& At(size_t idx);
//
//  const T& Front() const;
//  T& Front();
//
//  const T& Back() const;
//  T& Back();
//
//  const T* Data() const;
//  T* Data();
//
//  size_t Size() const;
//
//  bool Empty() const;
//
//  void Fill(const T& value);
//
//  void Swap(Array<T, SIZE>& other);
//};
//
//template <class T, size_t SIZE>
//T& Array<T, SIZE>::operator[](size_t idx) {
//  return my_arr[idx];
//}
//
//template <class T, size_t SIZE>
//const T& Array<T, SIZE>::operator[](size_t idx) const {
//  return my_arr[idx];
//}
//
//template <class T, size_t SIZE>
//const T& Array<T, SIZE>::At(size_t idx) const {
//  if (idx >= SIZE) {
//    throw ArrayOutOfRange{};
//  }
//  return my_arr[idx];
//}
//
//template <class T, size_t SIZE>
//T& Array<T, SIZE>::At(size_t idx) {
//  if (idx >= SIZE) {
//    throw ArrayOutOfRange{};
//  }
//  return my_arr[idx];
//}
//
//template <class T, size_t SIZE>
//const T& Array<T, SIZE>::Front() const {
//  return *my_arr;
//}
//
//template <class T, size_t SIZE>
//T& Array<T, SIZE>::Front() {
//  return *my_arr;
//}
//
//template <class T, size_t SIZE>
//const T& Array<T, SIZE>::Back() const {
//  return my_arr[SIZE - 1];
//}
//
//template <class T, size_t SIZE>
//T* Array<T, SIZE>::Data() {
//  return my_arr;
//}
//
//template <class T, size_t SIZE>
//const T* Array<T, SIZE>::Data() const {
//  return my_arr;
//}
//
//template <class T, size_t SIZE>
//T& Array<T, SIZE>::Back() {
//  return my_arr[SIZE - 1];
//}
//
//template <class T, size_t SIZE>
//void Array<T, SIZE>::Fill(const T& value) {
//  for (int i = 0; i < SIZE; ++i) {
//    my_arr[i] = value;
//  }
//}
//
//template <class T, size_t SIZE>
//size_t Array<T, SIZE>::Size() const {
//  return SIZE;
//}
//
//template <class T, size_t SIZE>
//bool Array<T, SIZE>::Empty() const {
//  return Size() == 0;
//}
//
//template <class T, size_t SIZE>
//void Array<T, SIZE>::Swap(Array<T, SIZE>& other) {
//  for (int i = 0; i < SIZE; ++i) {
//    T tmp = my_arr[i];
//    my_arr[i] = other[i];
//    other[i] = tmp;
//  }
//}
//#endif