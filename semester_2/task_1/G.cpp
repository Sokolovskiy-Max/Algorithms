//#include <cmath>
//#include <iostream>
//#include <vector>
//class Point {
// public:
//  int64_t x_;
//  int64_t y_;
//  Point();
//  Point(int, int);
//  friend std::istream& operator>>(std::istream& in, Point&);
//};
//Point::Point() : x_(0), y_(0) {
//}
//Point::Point(int x, int y) : x_(x), y_(y) {
//}
//
//std::istream& operator>>(std::istream& in, Point& point) {
//  int64_t x, y;
//  in >> x >> y;
//  point.x_ = x;
//  point.y_ = y;
//  return in;
//}
//
//class Vector {
// public:
//  int x_;
//  int y_;
//  Vector();
//  Vector(int, int);
//  Vector(Point, Point);
//  double Length();
//  friend std::istream& operator>>(std::istream& in, Vector& vector);
//};
//
//Vector::Vector() : x_(0), y_(0) {
//}
//Vector::Vector(#include <cmath>
//#include <iostream>
//#include <vector>
//class Point {
// public:
//  int64_t x_;
//  int64_t y_;
//  Point();
//  Point(int, int);
//  friend std::istream& operator>>(std::istream& in, Point&);
//};
//Point::Point() : x_(0), y_(0) {
//}
//Point::Point(int x, int y) : x_(x), y_(y) {
//}
//
//std::istream& operator>>(std::istream& in, Point& point) {
//  int64_t x, y;
//  in >> x >> y;
//  point.x_ = x;
//  point.y_ = y;
//  return in;
//}
//
//class Vector {
// public:
//  int x_;
//  int y_;
//  Vector();
//  Vector(int, int);
//  Vector(Point, Point);
//  double Length();
//  friend std::istream& operator>>(std::istream& in, Vector& vector);
//};
//
//Vector::Vector() : x_(0), y_(0) {
//}
//Vector::Vector(int x, int y) : x_(x), y_(y) {
//}
//Vector::Vector(Point p1, Point p2) : x_(p2.x_ - p1.x_), y_(p2.y_ - p1.y_) {
//}
//
//double Vector::Length() {
//  double length = sqrt(x_ * x_ + y_ * y_);
//  return length;
//}
//
//std::istream& operator>>(std::istream& in, Vector& vector) {
//  int64_t x, y;
//  in >> x >> y;
//  vector.x_ = x;
//  vector.y_ = y;
//  return in;
//}
//
//int64_t ScalarProduct(const Vector& first, const Vector& second) {
//  int64_t product = first.x_ * second.x_ + first.y_ * second.y_;
//  return product;
//}
//
//int64_t VectorProduct(const Vector& first, const Vector& second) {
//  int64_t product = first.x_ * second.y_ - first.y_ * second.x_;
//  return product;
//}
//
//bool IsConvex() {
//  int64_t n;
//  std::cin >> n;
//  std::vector<Point> points(n);
//  for (int64_t i = 0; i < n; ++i) {
//    std::cin >> points[i];
//  }
//  if (points[0].x_ == points[n - 1].x_ && points[0].y_ == points[n - 1].y_) {
//    return false;
//  }
//  for (int i = 0; i < n - 1; i++) {
//    if (points[i].x_ == points[i + 1].x_ && points[i].y_ == points[i + 1].y_) {
//      return false;
//    }
//  }
//  if (n > 3) {
//    std::vector<int64_t> dir(n);
//    for (int64_t i = 0; i < n - 2; ++i) {
//      int64_t a = VectorProduct(Vector(points[i], points[i + 1]), Vector(points[i + 1], points[i + 2]));
//      if (a != 0) {
//        a /= std::abs(VectorProduct(Vector(points[i], points[i + 1]), Vector(points[i + 1], points[i + 2])));
//      }
//      dir[i + 1] = a;
//    }
//    int64_t a = VectorProduct(Vector(points[n - 2], points[n - 1]), Vector(points[n - 1], points[0]));
//    if (a != 0) {
//      a /= std::abs(VectorProduct(Vector(points[n - 2], points[n - 1]), Vector(points[n - 1], points[0])));
//    }
//    dir[n - 1] = 0;
//    a = VectorProduct(Vector(points[n - 1], points[0]), Vector(points[0], points[1]));
//    if (a != 0) {
//      a /= std::abs(VectorProduct(Vector(points[n - 1], points[0]), Vector(points[0], points[1])));
//    }
//    dir[0] = a;
//    int64_t pref = dir[0];
//    int64_t tmp = pref;
//    for (int i = 1; i < n; ++i) {
//      pref += dir[i];
//      if (std::abs(tmp) > std::abs(pref)) {
//        return false;
//      }
//      tmp = pref;
//    }
//  }
//  return true;
//}
//
//int main() {
//  if (IsConvex()) {
//    std::cout << "YES";
//  } else {
//    std::cout << "NO";
//  }
//} x, int y) : x_(x), y_(y) {
//}
//Vector::Vector(Point p1, Point p2) : x_(p2.x_ - p1.x_), y_(p2.y_ - p1.y_) {
//}
//
//double Vector::Length() {
//  double length = sqrt(x_ * x_ + y_ * y_);
//  return length;
//}
//
//std::istream& operator>>(std::istream& in, Vector& vector) {
//  int64_t x, y;
//  in >> x >> y;
//  vector.x_ = x;
//  vector.y_ = y;
//  return in;
//}
//
//int64_t ScalarProduct(const Vector& first, const Vector& second) {
//  int64_t product = first.x_ * second.x_ + first.y_ * second.y_;
//  return product;
//}
//
//int64_t VectorProduct(const Vector& first, const Vector& second) {
//  int64_t product = first.x_ * second.y_ - first.y_ * second.x_;
//  return product;
//}
//
//bool IsConvex() {
//  int64_t n;
//  std::cin >> n;
//  std::vector<Point> points(n);
//  for (int64_t i = 0; i < n; ++i) {
//    std::cin >> points[i];
//  }
//  if (points[0].x_ == points[n - 1].x_ && points[0].y_ == points[n - 1].y_) {
//    return false;
//  }
//  for (int i = 0; i < n - 1; i++) {
//    if (points[i].x_ == points[i + 1].x_ && points[i].y_ == points[i + 1].y_) {
//      return false;
//    }
//  }
//  if (n > 3) {
//    std::vector<int64_t> dir(n);
//    for (int64_t i = 0; i < n - 2; ++i) {
//      int64_t a = VectorProduct(Vector(points[i], points[i + 1]), Vector(points[i + 1], points[i + 2]));
//      if (a != 0) {
//        a /= std::abs(VectorProduct(Vector(points[i], points[i + 1]), Vector(points[i + 1], points[i + 2])));
//      }
//      dir[i + 1] = a;
//    }
//    int64_t a = VectorProduct(Vector(points[n - 2], points[n - 1]), Vector(points[n - 1], points[0]));
//    if (a != 0) {
//      a /= std::abs(VectorProduct(Vector(points[n - 2], points[n - 1]), Vector(points[n - 1], points[0])));
//    }
//    dir[n - 1] = 0;
//    a = VectorProduct(Vector(points[n - 1], points[0]), Vector(points[0], points[1]));
//    if (a != 0) {
//      a /= std::abs(VectorProduct(Vector(points[n - 1], points[0]), Vector(points[0], points[1])));
//    }
//    dir[0] = a;
//    int64_t pref = dir[0];
//    int64_t tmp = pref;
//    for (int i = 1; i < n; ++i) {
//      pref += dir[i];
//      if (std::abs(tmp) > std::abs(pref)) {
//        return false;
//      }
//      tmp = pref;
//    }
//  }
//  return true;
//}
//
//int main() {
//  if (IsConvex()) {
//    std::cout << "YES";
//  } else {
//    std::cout << "NO";
//  }
//}