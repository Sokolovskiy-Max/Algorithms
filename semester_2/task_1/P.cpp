////#include "cmath"
//#include "iostream"
////#include "vector"
////#include "algorithm"
////class Point {
////private:
////  int64_t x_;
////  int64_t y_;
////
////public:
////  Point();
////  Point(int64_t, int64_t);
////  int64_t GetX() const;
////  int64_t GetY() const;
////  void SetX(int64_t);
////  void SetY(int64_t);
////  void SetXY(int64_t, int64_t);
////  friend std::istream& operator>>(std::istream& in, Point& vector);
////};
////Point::Point() {
////  x_ = 0;
////  y_ = 0;
////}
////Point::Point(int64_t x, int64_t y) {
////  x_ = x;
////  y_ = y;
////}
////int64_t Point::GetX() const {
////  return x_;
////}
////int64_t Point::GetY() const {
////  return y_;
////}
////void Point::SetX(int64_t x) {
////  x_ = x;
////}
////void Point::SetY(int64_t y) {
////  y_ = y;
////}
////void Point::SetXY(int64_t x, int64_t y) {
////  x_ = x;
////  y_ = y;
////}
////std::istream& operator>>(std::istream& in, Point& vector) {
////  int64_t x, y;
////  in >> x >> y;
////  vector.SetXY(x, y);
////  return in;
////}
////class Vector {
////private:
////  int64_t x_;
////  int64_t y_;
////
////public:
////  Vector();
////  Vector(int64_t, int64_t);
////  Vector(Point, Point);
////  int64_t GetX() const;
////  int64_t GetY() const;
////  void SetX(int64_t);
////  void SetY(int64_t);
////  void SetXY(int64_t, int64_t);
////  void operator+=(const Vector&);
////  void operator-=(const Vector&);
////  Vector operator+(const Vector&);
////  Vector operator-(const Vector&);
////  int64_t operator*(const Vector& vector);
////  int64_t operator/(const Vector& vector);
////  double Length();
////  friend std::istream& operator>>(std::istream& in, Vector& vector);
////};
////Vector::Vector() {
////  x_ = 0;
////  y_ = 0;
////}
////Vector::Vector(int64_t x, int64_t y) {
////  x_ = x;
////  y_ = y;
////}
////Vector::Vector(Point a, Point b) {
////  x_ = b.GetX() - a.GetX();
////  y_ = b.GetY() - a.GetY();
////}
////int64_t Vector::GetX() const {
////  return x_;
////}
////int64_t Vector::GetY() const {
////  return y_;
////}
////void Vector::SetX(int64_t x) {
////  x_ = x;
////}
////void Vector::SetY(int64_t y) {
////  y_ = y;
////}
////void Vector::SetXY(int64_t x, int64_t y) {
////  x_ = x;
////  y_ = y;
////}
////void Vector::operator+=(const Vector& vector) {
////  SetX(x_ + vector.GetX());
////  SetY(y_ + vector.GetY());
////}
////void Vector::operator-=(const Vector& vector) {
////  SetX(x_ + vector.GetX());
////  SetY(y_ + vector.GetY());
////}
////Vector Vector::operator+(const Vector& vector) {
////  auto new_vector = Vector();
////  new_vector.SetX(x_ + vector.GetX());
////  new_vector.SetY(y_ + vector.GetY());
////  return new_vector;
////}
////Vector Vector::operator-(const Vector& vector) {
////  auto new_vector = Vector();
////  new_vector.SetX(x_ + vector.GetX());
////  new_vector.SetY(y_ + vector.GetY());
////  return new_vector;
////}
////int64_t Vector::operator*(const Vector& vector) {
////  return (vector.GetX() * x_ + vector.GetY() * y_);
////}
////double Vector::Length() {
////  double len = sqrt(x_ * x_ + y_ * y_);
////  return len;
////}
////int64_t Vector::operator/(const Vector& vector) {
////  return (vector.GetY() * x_ - vector.GetX() * y_);
////}
////std::istream& operator>>(std::istream& in, Vector& vector) {
////  int64_t x, y;
////  in >> x >> y;
////  vector.SetXY(x, y);
////  return in;
////}
////
////void PolygomSquare(std::vector<Point>& points) {
////  int64_t n = points.size();
////  int64_t square = -points[0].GetX() * points[n - 1].GetY();
////  for (int i = 0; i < n - 1; ++i) {
////    square += (points[i].GetX() * points[i + 1].GetY());
////    square -= (points[i].GetY() * points[i + 1].GetX());
////  }
////  square += points[n - 1].GetX() * points[0].GetY();
////  if (std::abs(square) % 2 == 0) {
////    std::cout << std::abs(square) / 2 << ".0";
////  } else {
////    std::cout << (std::abs(square) - 1) / 2 << ".5";
////  }
////}
////
////bool Comp(Point a, Point b) {
////  if (a.GetX() * b.GetY() == a.GetY() * b.GetX()) {
////    return (a.GetX() * a.GetX() + a.GetY() * a.GetY() < b.GetX() * b.GetX() + b.GetY() * b.GetY());
////  }
////  return (a.GetX() * b.GetY() < a.GetY() * b.GetX());
////}
////
////int main() {
////  int64_t n;
////  std::cin >> n;
////  std::vector<Point> points(n);
////  std::vector<Point> ans;
////  for (int64_t i = 0; i < n; ++i) {
////    std::cin >> points[i];
////  }
////  for (int64_t i = 1; i < n; ++i) {
////    if (points[i].GetX() < points[0].GetX() ||
////      (points[i].GetX() == points[0].GetX() && points[i].GetY() < points[0].GetY())) {
////      std::swap(points[i], points[0]);
////    }
////  }
////  uint64_t tmp = 0;
////  while (true) {
////    ans.push_back(points[tmp]);
////    uint64_t next = 1000000;
////    for (uint64_t i = 0; i < points.size(); ++i) {
////      if (i != tmp && (next == 1000000 || (Vector(points[tmp], points[i]) / Vector(points[tmp], points[next])) <= 0)) {
////        if (next == 1000000 || (Vector(points[tmp], points[i]) / Vector(points[tmp], points[next])) != 0) {
////          next = i;
////        } else {
////          if (Vector(points[tmp], points[next]).Length() < Vector(points[tmp], points[i]).Length()) {
////            next = i;
////          }
////        }
////      }
////    }
////    if (next == 0) {
////      break;
////    }
////    tmp = next;
////  }
////  std::cout << ans.size() << std::endl;
////  for (uint64_t i = 0; i < ans.size(); ++i) {
////    std::cout << ans[i].GetX() << ' ' << ans[i].GetY() << std::endl;
////  }
////  PolygomSquare(ans);
////}
//int main() {
//  std::cout << __cplusplus << std::endl;
//}