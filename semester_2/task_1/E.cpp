//#include <cmath>
//#include <iostream>
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
//  bool IsOnLine(int, int);
//  double PointDistance(int, int) const;
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
//bool Line::IsOnLine(int x, int y) {
//  return (a_ * x + b_ * y + c_ == 0);
//}
//double Line::PointDistance(int x, int y) const {
//  return double(double(a_ * x + b_ * y + c_) / sqrt(a_ * a_ + b_ * b_));
//}
//
//class Segment {
//public:
//  int64_t x1_;
//  int64_t x2_;
//  int64_t y1_;
//  int64_t y2_;
//  Segment();
//  Segment(int64_t, int64_t, int64_t, int64_t);
//  friend std::istream& operator>>(std::istream& in, Segment& segment);
//  bool IsOnSegment(int64_t, int64_t);
//  double PointDistance(int64_t, int64_t) const;
//  bool LineSegmentCrossing(const Line& line) const;
//  bool SegmentSegmentCrossing(const Segment& segment) const;
//};
//
//Segment::Segment() : x1_(0), x2_(0), y1_(0), y2_(0) {
//}
//
//Segment::Segment(int64_t x1, int64_t y1, int64_t x2, int64_t y2) : x1_(x1), x2_(x2), y1_(y1), y2_(y2) {
//}
//
//std::istream& operator>>(std::istream& in, Segment& segment) {
//  int64_t x1, y1, x2, y2;
//  in >> x1 >> y1 >> x2 >> y2;
//  segment.x1_ = x1;
//  segment.x2_ = x2;
//  segment.y1_ = y1;
//  segment.y2_ = y2;
//  return in;
//}
//
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
//  return Line(x1_, y1_, x2_, y2_).PointDistance(x, y);
//}
//bool Segment::LineSegmentCrossing(const Line& line) const {
//  if ((line.a_ * x1_ + line.b_ * y1_ + line.c_) == 0 || (line.a_ * x2_ + line.b_ * y2_ + line.c_) == 0) {
//    return true;
//  }
//  int64_t a = (line.a_ * x2_ + line.b_ * y2_ + line.c_) / std::abs(line.a_ * x2_ + line.b_ * y2_ + line.c_);
//  int64_t b = (line.a_ * x1_ + line.b_ * y1_ + line.c_) / std::abs(line.a_ * x1_ + line.b_ * y1_ + line.c_);
//  return (a * b <= 0);
//}
//
//bool Segment::SegmentSegmentCrossing(const Segment& segment) const {
//  if (!(this->LineSegmentCrossing(Line(segment.x1_, segment.y1_, segment.x2_, segment.y2_)) &&
//    segment.LineSegmentCrossing(Line(x1_, y1_, x2_, y2_)))) {
//    return false;
//  }
//  bool check_collision_begin_begin = x1_ == segment.x1_ && y1_ == segment.y1_;
//  bool check_collision_begin_end = x1_ == segment.x2_ && y1_ == segment.y2_;
//  bool check_collision_end_begin = x2_ == segment.x2_ && y2_ == segment.y2_;
//  bool check_collision_end_end = x2_ == segment.x1_ && y2_ == segment.y1_;
//  if (check_collision_begin_begin || check_collision_begin_end || check_collision_end_begin ||
//    check_collision_end_end) {
//    return true;
//  }
//  Vector begin_begin = Vector(x1_ - segment.x1_, y1_ - segment.y1_);
//  Vector begin_end = Vector(x1_ - segment.x2_, y1_ - segment.y2_);
//  Vector end_begin = Vector(x2_ - segment.x1_, y2_ - segment.y1_);
//  Vector end_end = Vector(x2_ - segment.x2_, y2_ - segment.y2_);
//  return (ScalarProduct(begin_begin, begin_end) <= 0 || ScalarProduct(end_begin, end_end) <= 0 ||
//    ScalarProduct(begin_begin, end_begin) <= 0 || ScalarProduct(begin_end, end_end) <= 0);
//}
//
//int main() {
//  Segment a;
//  Segment b;
//  std::cin >> a >> b;
//  std::cout << (a.SegmentSegmentCrossing(b) ? "YES" : "NO");
//}