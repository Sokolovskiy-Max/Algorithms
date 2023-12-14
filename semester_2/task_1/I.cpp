//#include <cmath>
//#include <iostream>
//#include <vector>
//class Point {
// public:
//  int64_t x_;
//  int64_t y_;
//  Point();
//  Point(int64_t, int64_t);
//  friend std::istream& operator>>(std::istream& in, Point&);
//};
//
//Point::Point() : x_(0), y_(0) {
//}
//Point::Point(int64_t x, int64_t y) : x_(x), y_(y) {
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
//  int64_t x_;
//  int64_t y_;
//  Vector();
//  Vector(int64_t, int64_t);
//  Vector(Point, Point);
//  double Length();
//  friend std::istream& operator>>(std::istream& in, Vector& vector);
//};
//
//Vector::Vector() : x_(0), y_(0) {
//}
//Vector::Vector(int64_t x, int64_t y) : x_(x), y_(y) {
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
//class Line {
// public:
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
//  friend std::istream& operator>>(std::istream& in, Line& line);
//  double PointDistance(const Point&) const;
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
//class Segment {
// public:
//  int64_t x1_, x2_, y1_, y2_;
//  Segment();
//  Segment(int64_t, int64_t, int64_t, int64_t);
//  Vector GetDirection() const;
//  friend std::istream& operator>>(std::istream& in, Segment& segment);
//  bool IsOnSegment(int64_t, int64_t);
//  double PointDistance(int64_t, int64_t) const;
//  bool LineSegmentCrossing(const Line& line) const;
//  bool SegmentSegmentCrossing(const Segment& segment) const;
//};
//
//Vector Segment::GetDirection() const {
//  return Vector(x2_ - x1_, y2_ - y1_);
//}
//Segment::Segment() {
//  x1_ = 0;
//  x2_ = 0;
//  y1_ = 0;
//  y2_ = 0;
//}
//Segment::Segment(int64_t x1, int64_t y1, int64_t x2, int64_t y2) {
//  x1_ = x1;
//  y1_ = y1;
//  x2_ = x2;
//  y2_ = y2;
//}
//std::istream& operator>>(std::istream& in, Segment& segment) {
//  int64_t x1, y1, x2, y2;
//  in >> x1 >> y1 >> x2 >> y2;
//  segment.x1_ = x1;
//  segment.y1_ = y1;
//  segment.x2_ = x2;
//  segment.y2_ = y2;
//  return in;
//}
//bool Segment::IsOnSegment(int64_t x, int64_t y) {
//  return (VectorProduct(Vector(x - x1_, y - y1_), Vector(x2_ - x, y2_ - y)) == 0 &&
//    ScalarProduct(Vector(x - x1_, y - y1_), Vector(x2_ - x, y2_ - y)) >= 0);
//}
//double Segment::PointDistance(int64_t x, int64_t y) const {
//  if (ScalarProduct(Vector(x - x1_, y - y1_), Vector(x2_ - x1_, y2_ - y1_)) <= 0) {
//    return Vector(x - x1_, y - y1_).Length();
//  }
//  if (ScalarProduct(Vector(x - x2_, y - y2_), Vector(x1_ - x2_, y1_ - y2_)) <= 0) {
//    return Vector(x - x2_, y - y2_).Length();
//  }
//  return Line(x1_, y1_, x2_, y2_).PointDistance(Point(x, y));
//}
//bool Segment::LineSegmentCrossing(const Line& line) const {
//  int a = (line.a_ * x2_ + line.b_ * y2_ + line.c_);
//  int b = (line.a_ * x1_ + line.b_ * y1_ + line.c_);
//  if (a == 0 || b == 0) {
//    return true;
//  }
//  a /= abs(a);
//  b /= abs(b);
//  return (a * b <= 0);
//}
//bool Segment::SegmentSegmentCrossing(const Segment& segment) const {
//  return (this->LineSegmentCrossing(Line(segment.x1_, segment.y1_, segment.x2_, segment.y2_)) &&
//    segment.LineSegmentCrossing(Line(x1_, y1_, x2_, y2_)));
//}
//
//void PolygomSquare(int n) {
//  std::vector<Point> points(n);
//  for (int64_t i = 0; i < n; ++i) {
//    std::cin >> points[i];
//  }
//  int64_t square = -points[0].x_ * points[n - 1].y_;
//  for (int i = 0; i < n - 1; ++i) {
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
//int main() {
//  int64_t n;
//  std::cin >> n;
//  PolygomSquare(n);
//}