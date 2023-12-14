//#include "cmath"
//#include "iostream"
//#include "vector"
//#include "algorithm"
//class Point {
//public:
//  int64_t x_;
//  int64_t y_;
//  Point();
//  Point(int64_t, int64_t);
//  void SetXY(int64_t, int64_t);
//  bool operator==(const Point& point);
//  friend std::istream& operator>>(std::istream& in, Point& vector);
//};
//Point::Point() {
//  x_ = 0;
//  y_ = 0;
//}
//Point::Point(int64_t x, int64_t y) {
//  x_ = x;
//  y_ = y;
//}
//void Point::SetXY(int64_t x, int64_t y) {
//  x_ = x;
//  y_ = y;
//}
//bool Point::operator==(const Point& point) {
//  return (x_ == point.x_ && y_ == point.y_);
//}
//std::istream& operator>>(std::istream& in, Point& vector) {
//  int64_t x, y;
//  in >> x >> y;
//  vector.SetXY(x, y);
//  return in;
//}
//class Vector {
//public:
//  int64_t x_;
//  int64_t y_;
//  Vector();
//  Vector(int64_t, int64_t);
//  Vector(Point, Point);
//  void SetXY(int64_t, int64_t);
//  int64_t operator*(const Vector& vector);
//  int64_t operator^(const Vector& vector);
//  double Length();
//  friend std::istream& operator>>(std::istream& in, Vector& vector);
//};
//Vector::Vector() {
//  x_ = 0;
//  y_ = 0;
//}
//Vector::Vector(int64_t x, int64_t y) {
//  x_ = x;
//  y_ = y;
//}
//Vector::Vector(Point a, Point b) {
//  x_ = b.x_ - a.x_;
//  y_ = b.y_ - a.y_;
//}
//void Vector::SetXY(int64_t x, int64_t y) {
//  x_ = x;
//  y_ = y;
//}
//int64_t Vector::operator*(const Vector& vector) {
//  return (vector.x_ * x_ + vector.y_ * y_);
//}
//double Vector::Length() {
//  double len = sqrt(x_ * x_ + y_ * y_);
//  return len;
//}
//int64_t Vector::operator^(const Vector& vector) {
//  return (vector.y_ * x_ - vector.x_ * y_);
//}
//std::istream& operator>>(std::istream& in, Vector& vector) {
//  int64_t x, y;
//  in >> x >> y;
//  vector.SetXY(x, y);
//  return in;
//}
//class Line {
//
//public:
//  int64_t a_, b_, c_;
//  Line();
//  Line(int64_t, int64_t, int64_t);
//  Line(int64_t, int64_t, int64_t, int64_t);
//  Vector Direction() const;
//  double Distance(const Line& line) const;
//  bool IsCrossing(const Line& line) const;
//  void Point(const Line& line) const;
//  void SetABC(int64_t, int64_t, int64_t);
//  friend std::istream& operator>>(std::istream& in, Line& line);
//  bool IsOnLine(int64_t, int64_t);
//  double PointDistance(int64_t, int64_t) const;
//};
//Line::Line() {
//  a_ = 0;
//  b_ = 0;
//  c_ = 0;
//}
//Line::Line(int64_t a, int64_t b, int64_t c) {
//  a_ = a;
//  b_ = b;
//  c_ = c;
//}
//Line::Line(int64_t x1, int64_t y1, int64_t x2, int64_t y2) {
//  a_ = y2 - y1;
//  b_ = x1 - x2;
//  c_ = y1 * (x2 - x1) - x1 * (y2 - y1);
//}
//void Line::SetABC(int64_t a, int64_t b, int64_t c) {
//  a_ = a;
//  b_ = b;
//  c_ = c;
//}
//std::istream& operator>>(std::istream& in, Line& line) {
//  int64_t a, b, c;
//  in >> a >> b >> c;
//  line.SetABC(a, b, c);
//  return in;
//}
//Vector Line::Direction() const {
//  Vector a(b_, -a_);
//  return a;
//}
//bool Line::IsCrossing(const Line& line) const {
//  Vector a = (this->Direction());
//  Vector b = line.Direction();
//  return ((a ^ b) == 0);
//}
//double Line::Distance(const Line& line) const {
//  return (c_ - line.c_) / sqrt(a_ * a_ + line.b_ * line.b_);
//}
//void Line::Point(const Line& line) const {
//  double x = -double(c_ * line.b_ - line.c_ * b_) / double(a_ * line.b_ - line.a_ * b_);
//  double y = -double(a_ * line.c_ - line.a_ * c_) / double(a_ * line.b_ - line.a_ * b_);
//  std::cout << x << ' ' << y;
//}
//bool Line::IsOnLine(int64_t x, int64_t y) {
//  return (a_ * x + b_ * y + c_ == 0);
//}
//double Line::PointDistance(int64_t x, int64_t y) const {
//  return double(double(a_ * x + b_ * y + c_) / sqrt(a_ * a_ + b_ * b_));
//}
//
//class Segment {
//public:
//  int64_t x1_, x2_, y1_, y2_;
//  Segment();
//  Segment(int64_t, int64_t, int64_t, int64_t);
//  Vector GetDirection() const;
//  void SetAll(int64_t, int64_t, int64_t, int64_t);
//  friend std::istream& operator>>(std::istream& in, Segment& segment);
//  bool IsOnSegment(int64_t, int64_t);
//  double PointDistance(int64_t, int64_t) const;
//  bool LineSegmentCrossing(const Line& line) const;
//  bool SegmentSegmentCrossing(const Segment& segment) const;
//};
//
//void Segment::SetAll(int64_t x1, int64_t y1, int64_t x2, int64_t y2) {
//  x1_ = x1;
//  y1_ = y1;
//  x2_ = x2;
//  y2_ = y2;
//}
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
//  segment.SetAll(x1, y1, x2, y2);
//  return in;
//}
//bool Segment::IsOnSegment(int64_t x, int64_t y) {
//  return (((Vector(x - x1_, y - y1_) ^ Vector(x2_ - x, y2_ - y)) == 0 &&
//    Vector(x - x1_, y - y1_) * Vector(x2_ - x, y2_ - y) >= 0));
//}
//double Segment::PointDistance(int64_t x, int64_t y) const {
//  if (Vector(x - x1_, y - y1_) * Vector(x2_ - x1_, y2_ - y1_) <= 0) {
//    return Vector(x - x1_, y - y1_).Length();
//  }
//  if (Vector(x - x2_, y - y2_) * Vector(x1_ - x2_, y1_ - y2_) <= 0) {
//    return Vector(x - x2_, y - y2_).Length();
//  }
//  return Line(x1_, y1_, x2_, y2_).PointDistance(x, y);
//}
//bool Segment::LineSegmentCrossing(const Line& line) const {
//  int64_t a = (line.a_ * x2_ + line.b_ * y2_ + line.c_);
//  int64_t b = (line.a_ * x1_ + line.b_ * y1_ + line.c_);
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
//bool Comp(Point a, Point b) {
//  if (a.x_ * b.y_ == a.y_ * b.x_) {
//    return (a.x_ * a.x_ + a.y_ * a.y_ < b.x_* b.x_ + b.y_ * b.y_);
//  }
//  return (a.x_ * b.y_ < a.y_* b.x_);
//}
//
//bool InShell(std::vector<Point>& shell, int64_t x, int64_t y) {
//  int64_t n = shell.size();
//  Segment segment(x, y, 100003, 1);
//
//  for (int64_t i = 0; i < n - 1; ++i) {
//    if (Segment(shell[i].x_, shell[i].y_, shell[i + 1].x_, shell[i + 1].y_).IsOnSegment(x, y)) {
//      return true;
//    }
//  }
//  if (Segment(shell[0].x_, shell[0].y_, shell[n - 1].x_, shell[n - 1].y_).IsOnSegment(x, y)) {
//    return true;
//  }
//  int64_t count = 0;
//  for (int64_t i = 1; i < n; ++i) {
//    if (segment.SegmentSegmentCrossing(Segment(shell[i - 1].x_, shell[i - 1].y_, shell[i].x_, shell[i].y_))) {
//      ++count;
//    }
//  }
//  if (segment.SegmentSegmentCrossing(Segment(shell[0].x_, shell[0].y_, shell[n - 1].x_, shell[n - 1].y_))) {
//    ++count;
//  }
//  return (count % 2 != 0);
//}
//
//std::vector<Point> MVO(std::vector<Point>& points) {
//  std::vector<Point> ans;
//  int64_t n = points.size();
//  for (int64_t i = 1; i < n; ++i) {
//    if (points[i].x_ < points[0].x_ || (points[i].x_ == points[0].x_ && points[i].y_ < points[0].y_)) {
//      std::swap(points[i], points[0]);
//    }
//  }
//  int64_t startx = points[0].x_;
//  int64_t starty = points[0].y_;
//  for (int64_t i = 0; i < n; ++i) {
//    points[i].SetXY(points[i].x_ - startx, points[i].y_ - starty);
//  }
//  std::sort(points.begin() + 1, points.end(), Comp);
//  for (int64_t i = 0; i < n; ++i) {
//    points[i].SetXY(points[i].x_ + startx, points[i].y_ + starty);
//  }
//  ans.push_back(points[0]);
//  ans.push_back(points[1]);
//  for (int64_t i = 2; i < n; ++i) {
//    while (ans.size() >= 2 &&
//      (((Vector(ans[ans.size() - 2], ans[ans.size() - 1]) ^ Vector(ans[ans.size() - 1], points[i]))) > 0)) {
//      ans.pop_back();
//    }
//    ans.push_back(points[i]);
//  }
//  return ans;
//}
//void Solution(std::vector<Point>& area_points, std::vector<Point>& which_area) {
//  std::vector<std::vector<Point>> shells;
//  uint64_t k = which_area.size();
//  std::vector<int> ans(k);
//  for (int j = 0; area_points.size() > 2; ++j) {
//    Line line = Line(area_points[0].x_, area_points[0].y_, area_points[1].x_, area_points[1].y_);
//    bool line_check = true;
//    for (uint64_t i = 2; i < area_points.size(); ++i) {
//      if (!line.IsOnLine(area_points[i].x_, area_points[i].y_)) {
//        line_check = false;
//        break;
//      }
//    }
//    if (line_check) {
//      break;
//    }
//    std::vector<Point> shell = MVO(area_points);
//    uint64_t shell_size = shell.size();
//    for (uint64_t i = 0; i < shell_size; ++i) {
//      auto i_begin = std::remove(area_points.begin(), area_points.end(), shell[i]);
//      area_points.erase(i_begin, area_points.end());
//    }
//    for (uint64_t i = 0; i < k; ++i) {
//      if (j == 0) {
//        ans[i] = 0;
//      }
//      if (j != 0 && InShell(shell, which_area[i].x_, which_area[i].y_)) {
//        ans[i] = j;
//      }
//    }
//  }
//  for (uint64_t i = 0; i < k; ++i) {
//    std::cout << ans[i] << std::endl;
//  }
//}
//
//int main() {
//  int64_t n, k;
//  std::cin >> n;
//  std::vector<Point> area_points(n);
//  for (int i = 0; i < n; ++i) {
//    std::cin >> area_points[i];
//  }
//  std::cin >> k;
//  std::vector<Point> which_area(k);
//  for (int i = 0; i < k; ++i) {
//    std::cin >> which_area[i];
//  }
//  Solution(area_points, which_area);
//}