//#include <cmath>
//#include <iostream>
//#include <iomanip>
//
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
//  int x_;
//  int y_;
//  Vector();
//  Vector(int, int);
//  double Length();
//  friend std::istream& operator>>(std::istream& in, Vector& vector);
//};
//Vector::Vector() : x_(0), y_(0) {
//}
//Vector::Vector(int x, int y) : x_(x), y_(y) {
//}
//double Vector::Length() {
//  double length = sqrt(x_ * x_ + y_ * y_);
//  return length;
//}
//std::istream& operator>>(std::istream& in, Vector& vector) {
//  int x, y;
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
//int ScalarProduct(const Vector& first, const Vector& second) {
//  int product = first.x_ * second.x_ + first.y_ * second.y_;
//  return product;
//}
//int VectorProduct(const Vector& first, const Vector& second) {
//  int product = first.x_ * second.y_ - first.y_ * second.x_;
//  return product;
//}
//
//class Line {
//public:
//  int64_t a_;
//  int64_t b_;
//  int64_t c_;
//  Line();
//  Line(int64_t, int64_t, int64_t);
//  Vector Direction() const;
//  double Distance(const Line& line) const;
//  bool IsCrossing(const Line& line) const;
//  Point CrossingPoint(const Line& line) const;
//  friend std::istream& operator>>(std::istream& in, Line& line);
//};
//Line::Line() : a_(0), b_(0), c_(0) {
//}
//Line::Line(int64_t a, int64_t b, int64_t c) : a_(a), b_(b), c_(c) {
//}
//std::istream& operator>>(std::istream& in, Line& line) {
//  int64_t a, b, c;
//  in >> a >> b >> c;
//  line.a_ = a;
//  line.b_ = b;
//  line.c_ = c;
//  return in;
//}
//Vector Line::Direction() const {
//  Vector a(b_, -a_);
//  return a;
//}
//bool Line::IsCrossing(const Line& line) const {
//  Vector a = (this->Direction());
//  Vector b = line.Direction();
//  return (VectorProduct(a, b) != 0);
//}
//double Line::Distance(const Line& line) const {
//  return (c_ * line.a_ - line.c_ * a_) / sqrt(a_ * line.a_ * a_ * line.a_ + b_ * line.a_ * b_ * line.a_);
//}
//Point Line::CrossingPoint(const Line& line) const {
//  double x = -double(c_ * line.b_ - line.c_ * b_) / double(a_ * line.b_ - line.a_ * b_);
//  double y = -double(a_ * line.c_ - line.a_ * c_) / double(a_ * line.b_ - line.a_ * b_);
//  return (Point(x, y));
//}
//
//std::pair<double, double> FindCrossing(const Line& a, const Line& b) {
//  double x = -double(a.c_ * b.b_ - b.c_ * a.b_) / double(a.a_ * b.b_ - b.a_ * a.b_);
//  double y = -double(a.a_ * b.c_ - b.a_ * a.c_) / double(a.a_ * b.b_ - b.a_ * a.b_);
//  return (std::make_pair(x, y));
//}
//int main() {
//  auto a = Line();
//  auto b = Line();
//  std::cin >> a;
//  std::cin >> b;
//  Vector dir_a = a.Direction();
//  Vector dir_b = b.Direction();
//  std::cout << std::fixed << std::setprecision(6) << double(dir_a.x_) << ' ' << double(dir_a.y_) << std::endl;
//  std::cout << std::fixed << std::setprecision(6) << double(dir_b.x_) << ' ' << double(dir_b.y_) << std::endl;
//  if (!a.IsCrossing(b)) {
//    if (a.c_ * b.a_ == b.c_ * b.a_) {
//      std::cout << "0.000000";
//    } else {
//      if (a.a_ == 0 || b.b_ == 0) {
//        std::cout << std::fixed << std::setprecision(6) << std::abs(a.c_ - b.c_);
//      } else {
//        std::cout << std::fixed << std::setprecision(6) << std::abs(a.Distance(b));
//      }
//    }
//  } else {
//    std::pair<double, double> cross = FindCrossing(a, b);
//    std::cout << std::fixed << std::setprecision(6) << cross.first << ' ';
//    std::cout << std::fixed << std::setprecision(6) << cross.second;
//  }
//  return 0;
//}