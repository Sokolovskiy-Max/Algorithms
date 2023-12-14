//#include <cmath>
//#include <iostream>
//#include <iomanip>
//class Point {
//public:
//  int x_;
//  int y_;
//  Point();
//  Point(int, int);
//  friend std::istream& operator>>(std::istream& in, Point&);
//};
//Point::Point() : x_(0), y_(0) {
//}
//Point::Point(int x, int y) : x_(x), y_(y) {
//}
//bool operator==(const Point& first, const Point& second) {
//  return (first.x_ == second.x_ && first.y_ == second.y_);
//}
//std::istream& operator>>(std::istream& in, Point& point) {
//  int x, y;
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
//  double Length() const;
//  friend std::istream& operator>>(std::istream& in, Vector& vector);
//};
//Vector::Vector() : x_(0), y_(0) {
//}
//Vector::Vector(int x, int y) : x_(x), y_(y) {
//}
//double Vector::Length() const {
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
//  int a_;
//  int b_;
//  int c_;
//  Line();
//  Line(int, int, int);
//  Line(int, int, int, int);
//  Vector Direction() const;
//  double Distance(const Line& line) const;
//  bool IsCrossing(const Line& line) const;
//  Point CrossingPoint(const Line& line) const;
//  bool IsOnLine(const Point&);
//  double PointDistance(const Point&) const;
//  friend std::istream& operator>>(std::istream& in, Line& line);
//};
//Line::Line() : a_(0), b_(0), c_(0) {
//}
//Line::Line(int a, int b, int c) : a_(a), b_(b), c_(c) {
//}
//Line::Line(int x1, int y1, int x2, int y2) {
//  a_ = y2 - y1;
//  b_ = x1 - x2;
//  c_ = y1 * (x2 - x1) - x1 * (y2 - y1);
//}
//std::istream& operator>>(std::istream& in, Line& line) {
//  int a, b, c;
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
//bool Line::IsOnLine(const Point& point) {
//  return (a_ * point.x_ + b_ * point.y_ + c_ == 0);
//}
//Point Line::CrossingPoint(const Line& line) const {
//  double x = -double(c_ * line.b_ - line.c_ * b_) / double(a_ * line.b_ - line.a_ * b_);
//  double y = -double(a_ * line.c_ - line.a_ * c_) / double(a_ * line.b_ - line.a_ * b_);
//  return (Point(x, y));
//}
//double Line::PointDistance(const Point& point) const {
//  return double(double(a_ * point.x_ + b_ * point.y_ + c_) / sqrt(a_ * a_ + b_ * b_));
//}
//
//class Ray {
//public:
//  int x_;
//  int y_;
//
//  Vector direction_;
//  Ray();
//  Ray(int, int, const Vector&);
//  Ray(int, int, int, int);
//  friend std::istream& operator>>(std::istream& in, Ray& ray);
//  bool IsOnRay(const Point&);
//  double PointDistance(const Point&) const;
//};
//
//Ray::Ray() : x_(0), y_(0), direction_(Vector(0, 0)) {
//}
//Ray::Ray(int x, int y, const Vector& direction) : x_(x), y_(y), direction_(direction) {
//}
//Ray::Ray(int x, int y, int a, int b) : x_(x), y_(y), direction_(Vector(a - x, b - y)) {
//}
//
//std::istream& operator>>(std::istream& in, Ray& ray) {
//  int x, y;
//  Vector direction;
//  in >> x >> y >> direction;
//  ray.x_ = x;
//  ray.y_ = y;
//  ray.direction_ = direction;
//  return in;
//}
//bool Ray::IsOnRay(const Point& point) {
//  return (ScalarProduct(direction_, Vector(point.x_ - x_, point.y_ - y_)) >= 0 &&
//    (VectorProduct(direction_, Vector(point.x_ - x_, point.y_ - y_))) == 0);
//}
//double Ray::PointDistance(const Point& point) const {
//  if (ScalarProduct(Vector(point.x_ - x_, point.y_ - y_), direction_) > 0) {
//    return (std::fabs(double(VectorProduct(Vector(point.x_ - x_, point.y_ - y_), direction_)) / direction_.Length()));
//  }
//  return Vector(point.x_ - x_, point.y_ - y_).Length();
//}
//
//class Segment {
//public:
//  int x1_;
//  int x2_;
//  int y1_;
//  int y2_;
//  Segment();
//  Segment(int, int, int, int);
//  Segment(const Point&, const Point&);
//  friend std::istream& operator>>(std::istream& in, Segment& segment);
//  bool IsOnSegment(const Point& point);
//  double PointDistance(const Point&) const;
//};
//Segment::Segment() : x1_(0), x2_(0), y1_(0), y2_(0) {
//}
//Segment::Segment(int x1, int y1, int x2, int y2) : x1_(x1), x2_(x2), y1_(y1), y2_(y2) {
//}
//Segment::Segment(const Point& first, const Point& second)
//  : x1_(first.x_), x2_(second.x_), y1_(first.y_), y2_(second.y_) {
//}
//std::istream& operator>>(std::istream& in, Segment& segment) {
//  int x1, y1, x2, y2;
//  in >> x1 >> y1 >> x2 >> y2;
//  segment.x1_ = x1;
//  segment.x2_ = x1;
//  segment.y1_ = y1;
//  segment.y2_ = y2;
//  return in;
//}
//bool Segment::IsOnSegment(const Point& point) {
//  return (VectorProduct(Vector(point.x_ - x1_, point.y_ - y1_), Vector(x2_ - point.x_, y2_ - point.y_)) == 0 &&
//    ScalarProduct(Vector(point.x_ - x1_, point.y_ - y1_), Vector(x2_ - point.x_, y2_ - point.y_)) >= 0);
//}
//
//double Segment::PointDistance(const Point& point) const {
//  if (ScalarProduct(Vector(point.x_ - x1_, point.y_ - y1_), Vector(x2_ - x1_, y2_ - y1_)) <= 0) {
//    return Vector(point.x_ - x1_, point.y_ - y1_).Length();
//  }
//  if (ScalarProduct(Vector(point.x_ - x2_, point.y_ - y2_), Vector(x1_ - x2_, y1_ - y2_)) <= 0) {
//    return Vector(point.x_ - x2_, point.y_ - y2_).Length();
//  }
//  return Line(x1_, y1_, x2_, y2_).PointDistance(point);
//}
//
//int main() {
//  int x1, y1, x2, y2, x3, y3;
//  std::cin >> x3 >> y3 >> x1 >> y1 >> x2 >> y2;
//  Point point = Point(x3, y3);
//  Line line = Line(x1, y1, x2, y2);
//  Ray ray = Ray(x1, y1, x2, y2);
//  Segment segment = Segment(Point(x1, y1), Point(x2, y2));
//  if (line.IsOnLine(point)) {
//    std::cout << "0.000000" << std::endl;
//  } else {
//    std::cout << std::fixed << std::setprecision(6) << fabs(line.PointDistance(point)) << std::endl;
//  }
//  if (ray.IsOnRay(point)) {
//    std::cout << "0.000000" << std::endl;
//  } else {
//    std::cout << std::fixed << std::setprecision(6) << fabs(ray.PointDistance(point)) << std::endl;
//  }
//  if (segment.IsOnSegment(point)) {
//    std::cout << "0.000000";
//  } else {
//    std::cout << std::fixed << std::setprecision(6) << fabs(segment.PointDistance(point));
//  }
//}