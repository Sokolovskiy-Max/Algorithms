#include <iostream>
class IntVector {
public:
  int myVector() {
    int* arr = new int[1];
    maxSize = 1;
  }
  [[nodiscard]] 
  bool isMyVecEmpty() const {
    return size == 0;
  }
  [[nodiscard]] 
  int myVecSize() const {
    return size;
  }
  [[nodiscard]] 
  int myVecMaxSize() const {
    return maxSize;
  }
  void myPushBack(const int value) {
    if (size >= maxSize) addMemory();
    arr[size++] = value;
  }
  void myRemove(int index) {
    for (int i = index + 1; i < size; ++i) {
      arr[i - 1] = arr[i];
    }
    --size;
  }
  int& operator[](int index) {
    return arr[index];
  }
  const int& operator[](int index) const {
    return arr[index];
  }
  ~IntVector() {
    delete[] arr;
  }
  IntVector(IntVector& other) {
    if (this != &other) {
      delete[] arr;
      arr = new int[other.maxSize];
      for (size_t i = 0; i < other.size; ++i) arr[i] = other.arr[i];
      size = other.size;
      maxSize = other.maxSize;
    }
  }
  IntVector& operator=(IntVector& other) {
    if (this != &other) {
      delete[] arr;
      arr = new int[other.maxSize];
      for (size_t i = 0; i < other.size; ++i) arr[i] = other.arr[i];
      size = other.size;
      maxSize = other.maxSize;
    }
    return *this;
  }

private:
  int* arr;
  int size{};
  int maxSize{};
  void addMemory() {
    maxSize *= 2;
    int* tmp = arr;
    int* arr = new int[maxSize];
    for (size_t i = 0; i < size; ++i) arr[i] = tmp[i];
    delete[] tmp;
  }
};
int main() {
  IntVector vec = new IntVector(10);
}