#ifndef MATRIX
#define MATRIX

#include <stdexcept>
#include <iostream>

class MatrixIsDegenerateError : public std::runtime_error {
public:
  MatrixIsDegenerateError() : std::runtime_error("MatrixIsDegenerateError") {
  }
};

class MatrixOutOfRange : public std::out_of_range {
public:
  MatrixOutOfRange() : std::out_of_range("MatrixOutOfRange") {
  }
};

template <class T, int Height, int Width>
class Matrix {
public:
  T array[Height][Width];
  int RowsNumber() const;
  int ColumnsNumber() const;
  T& operator()(int, int);
  const T& operator()(int, int) const;
  T& At(int, int);
  const T& At(int, int) const;
  Matrix<T, Height, Width>& operator*=(double);
  Matrix<T, Height, Width>& operator/=(double);
  Matrix<T, Height, Width>& operator+=(Matrix<T, Height, Width>);
  Matrix<T, Height, Width>& operator-=(Matrix<T, Height, Width>);
  Matrix<T, Height, Width>& operator*=(Matrix<T, Width, Width>);
};

template <class T, int Height, int Width>
int Matrix<T, Height, Width>::RowsNumber() const {
  return Height;
}

template <class T, int Height, int Width>
int Matrix<T, Height, Width>::ColumnsNumber() const {
  return Width;
}

template <class T, int Height, int Width>
T& Matrix<T, Height, Width>::operator()(int i, int j) {
  return array[i][j];
}

template <class T, int Height, int Width>
const T& Matrix<T, Height, Width>::operator()(int i, int j) const {
  return array[i][j];
}

template <class T, int Height, int Width>
T& Matrix<T, Height, Width>::At(int i, int j) {
  if (i >= Height || j >= Width) {
    throw MatrixOutOfRange();
  }
  return array[i][j];
}

template <class T, int Height, int Width>
const T& Matrix<T, Height, Width>::At(int i, int j) const {
  if (i >= Height || j >= Width) {
    throw MatrixOutOfRange();
  }
  return array[i][j];
}

template <class T, int Height, int Width>
Matrix<T, Width, Height> GetTransposed(Matrix<T, Height, Width> first) {
  Matrix<T, Width, Height> matrix;
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      matrix(j, i) = first(i, j);
    }
  }
  return matrix;
}

template <class T, int Height, int Width>
Matrix<T, Height, Width> operator+(Matrix<T, Height, Width> first, Matrix<T, Height, Width> second) {
  Matrix<T, Height, Width> matrix;
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      matrix(i, j) = first(i, j) + second(i, j);
    }
  }
  return matrix;
}

template <class T, int Height, int Width>
Matrix<T, Height, Width> operator-(Matrix<T, Height, Width> first, Matrix<T, Height, Width> second) {
  Matrix<T, Height, Width> matrix;
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      matrix(i, j) = first(i, j) - second(i, j);
    }
  }
  return matrix;
}

template <class T, int Height, int Width, int Q>
Matrix<T, Height, Width> operator*(Matrix<T, Height, Q> first, Matrix<T, Q, Width> second) {
  Matrix<T, Height, Width> matrix;
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      matrix(i, j) = 0;
    }
  }
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      for (int it = 0; it < Q; ++it) {
        matrix(i, j) += first(i, it) * second(it, j);
      }
    }
  }
  return matrix;
}

template <class T, int Height, int Width>
Matrix<T, Height, Width>& Matrix<T, Height, Width>::operator+=(Matrix<T, Height, Width> first) {
  Matrix<T, Height, Width> matrix;
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      array[i][j] += first(i, j);
    }
  }
  return *this;
}

template <class T, int Height, int Width>
Matrix<T, Height, Width>& Matrix<T, Height, Width>::operator-=(Matrix<T, Height, Width> first) {
  Matrix<T, Height, Width> matrix;
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      array[i][j] -= first(i, j);
    }
  }
  return *this;
}

template <class T, int Height, int Width>
Matrix<T, Height, Width>& Matrix<T, Height, Width>::operator*=(Matrix<T, Width, Width> second) {
  Matrix<T, Height, Width> matrix;
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      matrix(i, j) = 0;
    }
  }
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      for (int it = 0; it < Width; ++it) {
        matrix(i, j) += array[i][it] * second(it, j);
      }
    }
  }
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      array[i][j] = matrix(i, j);
    }
  }
  return *this;
}

template <class T, int Height, int Width>
Matrix<T, Height, Width>& Matrix<T, Height, Width>::operator*=(double digit) {
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      array[i][j] *= digit;
    }
  }
  return *this;
}

template <class T, int Height, int Width>
Matrix<T, Height, Width>& Matrix<T, Height, Width>::operator/=(double digit) {
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      array[i][j] /= digit;
    }
  }
  return *this;
}

template <class T, int Height, int Width>
Matrix<T, Height, Width> operator*(double digit, Matrix<T, Height, Width> first) {
  Matrix<T, Height, Width> matrix = first;
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      matrix(i, j) *= digit;
    }
  }
  return matrix;
}

template <class T, int Height, int Width>
Matrix<T, Height, Width> operator*(Matrix<T, Height, Width> first, double digit) {
  Matrix<T, Height, Width> matrix;
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      matrix(i, j) = first(i, j);
    }
  }
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      matrix(i, j) *= digit;
    }
  }
  return matrix;
}

template <class T, int Height, int Width>
Matrix<T, Height, Width> operator/(Matrix<T, Height, Width> first, double digit) {
  Matrix<T, Height, Width> matrix = first;
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      matrix(i, j) /= digit;
    }
  }
  return matrix;
}

template <class T, int Height, int Width>
bool operator==(Matrix<T, Height, Width> first, Matrix<T, Height, Width> second) {
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      if (first(i, j) != second(i, j)) {
        return false;
      }
    }
  }
  return true;
}

template <class T, int Height, int Width>
bool operator!=(Matrix<T, Height, Width> first, Matrix<T, Height, Width> second) {
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      if (first(i, j) != second(i, j)) {
        return true;
      }
    }
  }
  return false;
}

template <class T, int Height, int Width>
std::istream& operator>>(std::istream& io, Matrix<T, Height, Width>& first) {
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width; ++j) {
      io >> first.array[i][j];
    }
  }
  return io;
}

template <class T, int Height, int Width>
std::ostream& operator<<(std::ostream& os, const Matrix<T, Height, Width>& first) {
  for (int i = 0; i < Height; ++i) {
    for (int j = 0; j < Width - 1; ++j) {
      os << first(i, j) << ' ';
    }
    os << first(i, Width - 1) << std::endl;
  }
  return os;
}
#endif
