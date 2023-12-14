//#include <cmath>
//#include <iostream>
//#include <iomanip>
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
//
//Vector::Vector() : x_(0), y_(0) {
//}
//Vector::Vector(int x, int y) : x_(x), y_(y) {
//}
//
//double Vector::Length() {
//  double length = sqrt(x_ * x_ + y_ * y_);
//  return length;
//}
//
//std::istream& operator>>(std::istream& in, Vector& vector) {
//  int x, y;
//  in >> x >> y;
//  vector.x_ = x;
//  vector.y_ = y;
//  return in;
//}
//double Area(Vector a, Vector b) {
//  return (0.5 * std::fabs(-a.y_ * (b.x_ - a.x_) + a.x_ * (b.y_ - a.y_)));
//}
//
//Vector operator+(const Vector& first, const Vector& second) {
//  auto new_vector = Vector();
//  new_vector.x_ = (first.x_ + second.x_);
//  new_vector.y_ = (first.y_ + second.y_);
//  return new_vector;
//}
//
//Vector operator-(const Vector& first, const Vector& second) {
//  auto new_vector = Vector();
//  new_vector.x_ = (first.x_ - second.x_);
//  new_vector.y_ = (first.y_ - second.y_);
//  return new_vector;
//}
//
//int ScalarProduct(const Vector& first, const Vector& second) {
//  int product = first.x_ * second.x_ + first.y_ * second.y_;
//  return product;
//}
//
//int VectorProduct(const Vector& first, const Vector& second) {
//  int product = first.x_ * second.y_ - first.y_ * second.x_;
//  return product;
//}
//
//int main() {
//  int x1, y1, x2, y2;
//  std::cin >> x1 >> y1 >> x2 >> y2;
//  Vector a(x2 - x1, y2 - y1);
//  std::cin >> x1 >> y1 >> x2 >> y2;
//  Vector b(x2 - x1, y2 - y1);
//  Vector c = a + b;
//  std::cout << std::fixed << std::setprecision(6) << a.Length() << ' ' << b.Length() << std::endl;
//  std::cout << std::fixed << std::setprecision(6) << double(c.x_) << ' ' << double(c.y_) << std::endl;
//  std::cout << std::fixed << std::setprecision(6) << double(ScalarProduct(a, b)) << ' ' << double(VectorProduct(a, b))
//    << std::endl;
//  std::cout << std::fixed << std::setprecision(6) << Area(a, b);
//}