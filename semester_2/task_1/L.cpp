//#include <cmath>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//class Point {
//public:
//  int64_t x_;
//  int64_t y_;
//  Point();
//  Point(int64_t, int64_t);
//  friend std::istream& operator>>(std::istream& in, Point&);
//};
//Point::Point() : x_(0), y_(0) {
//}
//Point::Point(int64_t x, int64_t y) : x_(x), y_(y) {
//}
//bool operator==(const Point& first, const Point& second) {
//  return (first.x_ == second.x_ && first.y_ == second.y_);
//}
//std::istream& operator>>(std::istream& in, Point& point) {
//  int64_t x, y;
//  in >> x >> y;
//  point.x_ = x;
//  point.y_ = y;
//  return in;
//}
//
//class Vector {
//public:
//  int64_t x_;
//  int64_t y_;
//  Vector();
//  Vector(int64_t, int64_t);
//  Vector(const Point&, const Point&);
//  double Length();
//  friend std::istream& operator>>(std::istream& in, Vector& vector);
//};
//Vector::Vector() : x_(0), y_(0) {
//}
//Vector::Vector(int64_t x, int64_t y) : x_(x), y_(y) {
//}
//Vector::Vector(const Point& first, const Point& second) : x_(second.x_ - first.x_), y_(second.y_ - first.y_) {
//}
//double Vector::Length() {
//  double length = sqrt(x_ * x_ + y_ * y_);
//  return length;
//}
//std::istream& operator>>(std::istream& in, Vector& vector) {
//  int64_t x, y;
//  in >> x >> y;
//  vector.x_ = x;
//  vector.y_ = y;
//  return in;
//}
//Vector operator+(const Vector& first, const Vector& second) {
//  auto new_vector = Vector();
//  new_vector.x_ = (first.x_ + second.x_);
//  new_vector.y_ = (first.y_ + second.y_);
//  return new_vector;
//}
//Vector operator-(const Vector& first, const Vector& second) {
//  auto new_vector = Vector();
//  new_vector.x_ = (first.x_ - second.x_);
//  new_vector.y_ = (first.y_ - second.y_);
//  return new_vector;
//}
//int64_t ScalarProduct(const Vector& first, const Vector& second) {
//  int64_t product = first.x_ * second.x_ + first.y_ * second.y_;
//  return product;
//}
//int64_t VectorProduct(const Vector& first, const Vector& second) {
//  int64_t product = first.x_ * second.y_ - first.y_ * second.x_;
//  return product;
//}
//
//void PolygomSquare(std::vector<Point>& points) {
//  int64_t n = points.size();
//  int64_t square = -points[0].x_ * points[n - 1].y_;
//  for (int64_t i = 0; i < n - 1; ++i) {
//    square += (points[i].x_ * points[i + 1].y_);
//    square -= (points[i].y_ * points[i + 1].x_);
//  }
//  square += points[n - 1].x_ * points[0].y_;
//  if (std::abs(square) % 2 == 0) {
//    std::cout << std::abs(square) / 2 << ".0";
//  } else {
//    std::cout << (std::abs(square) - 1) / 2 << ".5";
//  }
//}
//
//bool Comp(const Point& a, const Point& b) {
//  if (a.x_ * b.y_ == a.y_ * b.x_) {
//    return (a.x_ * a.x_ + a.y_ * a.y_ < b.x_* b.x_ + b.y_ * b.y_);
//  }
//  return (a.x_ * b.y_ < a.y_* b.x_);
//}
//
//void JarvisShell(int64_t n, std::vector<Point>& points, std::vector<Point>& shell) {
//  for (int64_t i = 1; i < n; ++i) {
//    if (points[i].x_ < points[0].x_ || (points[i].x_ == points[0].x_ && points[i].y_ < points[0].y_)) {
//      std::swap(points[i], points[0]);
//    }
//  }
//  uint64_t tmp = 0;
//  uint64_t inf = 1000000;
//  while (true) {
//    shell.push_back(points[tmp]);
//    uint64_t next = inf;
//    for (uint64_t i = 0; i < points.size(); ++i) {
//      if (i != tmp &&
//        (next == inf || VectorProduct(Vector(points[tmp], points[i]), Vector(points[tmp], points[next])) <= 0)) {
//        if (next == inf || VectorProduct(Vector(points[tmp], points[i]), Vector(points[tmp], points[next])) != 0) {
//          next = i;
//        } else {
//          if (Vector(points[tmp], points[next]).Length() < Vector(points[tmp], points[i]).Length()) {
//            next = i;
//          }
//        }
//      }
//    }
//    if (next == 0) {
//      break;
//    }
//    tmp = next;
//  }
//}
//int main() {
//  int64_t n;
//  std::cin >> n;
//  std::vector<Point> points(n);
//  std::vector<Point> shell;
//  for (int64_t i = 0; i < n; ++i) {
//    std::cin >> points[i];
//  }
//  JarvisShell(n, points, shell);
//  std::cout << shell.size() << std::endl;
//  for (uint64_t i = 0; i < shell.size(); ++i) {
//    std::cout << shell[i].x_ << ' ' << shell[i].y_ << std::endl;
//  }
//  PolygomSquare(shell);
//}