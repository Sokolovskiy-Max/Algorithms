//#include "rational.h"
//
//Rational::Rational() {
//  numerator_ = 0;
//  denominator_ = 1;
//}
//
//Rational::Rational(int first_num) {
//  numerator_ = first_num;
//  denominator_ = 1;
//}
//
//Rational::Rational(int first_num, int second_num) {
//  if (second_num == 0) {
//    throw RationalDivisionByZero{};
//  }
//
//  numerator_ = first_num;
//  denominator_ = second_num;
//  Reduction();
//}
//
//int Rational::GetNumerator() const {
//  return numerator_;
//}
//
//int Rational::GetDenominator() const {
//  return denominator_;
//}
//
//void Rational::SetNumerator(int first_num) {
//  numerator_ = first_num;
//  Reduction();
//}
//
//void Rational::SetDenominator(int first_num) {
//  if (first_num == 0) {
//    throw RationalDivisionByZero{};
//  }
//  denominator_ = first_num;
//  Reduction();
//}
//
//Rational operator+(const Rational& first_num, const Rational& second_num) {
//  Rational rational;
//  rational.numerator_ = second_num.numerator_ * first_num.denominator_ + first_num.numerator_ * second_num.denominator_;
//  rational.denominator_ = first_num.denominator_ * second_num.denominator_;
//  rational.Reduction();
//  return rational;
//}
//
//Rational& Rational::operator+=(const Rational& rational) {
//  *this = *this + rational;
//  return *this;
//}
//
//Rational operator-(const Rational& first_num, const Rational& second_num) {
//  Rational rational;
//  rational.numerator_ = -second_num.numerator_ * first_num.denominator_ + first_num.numerator_ * second_num.denominator_;
//  rational.denominator_ = first_num.denominator_ * second_num.denominator_;
//  rational.Reduction();
//  return rational;
//}
//
//Rational& Rational::operator-=(const Rational& rational) {
//  *this = *this - rational;
//  return *this;
//}
//
//Rational operator*(const Rational& first_num, const Rational& second_num) {
//  if (first_num.numerator_ == 0 || second_num.numerator_ == 0) {
//    throw RationalDivisionByZero{};
//  }
//  Rational rational;
//  rational.numerator_ = first_num.numerator_ * second_num.numerator_;
//  rational.denominator_ = first_num.denominator_ * second_num.denominator_;
//  rational.Reduction();
//  return rational;
//}
//
//Rational& Rational::operator*=(const Rational& rational) {
//  *this = *this / rational;
//  return *this;
//}
//
//Rational operator/(const Rational& first_num, const Rational& second_num) {
//  if (first_num.numerator_ == 0 || second_num.numerator_ == 0) {
//    throw RationalDivisionByZero{};
//  }
//  Rational rational;
//  rational.numerator_ = first_num.numerator_ * second_num.denominator_;
//  rational.denominator_ = first_num.denominator_ * second_num.numerator_;
//  rational.Reduction();
//  return rational;
//}
//
//Rational& Rational::operator/=(const Rational& rational) {
//  *this = *this / rational;
//  return *this;
//}
//
//Rational operator+(const Rational& rational) {
//  return rational;
//}
//
//Rational operator-(const Rational& rational) {
//  Rational a;
//  a.numerator_ = -rational.numerator_;
//  return rational;
//}
//
//Rational& Rational::operator++() {
//  numerator_ += denominator_;
//  Reduction();
//  return *this;
//}
//
//Rational& Rational::operator--() {
//  numerator_ -= denominator_;
//  Reduction();
//  return *this;
//}
//
//
//Rational operator++(Rational& rational, int) {
//  Rational rat = rational;
//  rational.SetNumerator(rational.GetNumerator() + rational.GetDenominator());
//  return rat;
//}
//
//Rational operator--(Rational& rational, int) {
//  Rational rat = rational;
//  rational.SetNumerator(rational.GetNumerator() - rational.GetDenominator());
//  return rat;
//}
//
//bool operator<(const Rational& first_num, const Rational& second_num) {
//  return first_num.numerator_ * second_num.denominator_ < first_num.denominator_ * second_num.numerator_;
//}
//bool operator>(const Rational& first_num, const Rational& second_num) {
//  return first_num.numerator_ * second_num.denominator_ > first_num.denominator_* second_num.numerator_;
//}
//
//bool operator==(const Rational& first_num, const Rational& second_num) {
//  bool equal = !(second_num < first_num || first_num < second_num);
//  return equal;
//}
//
//bool operator!=(const Rational& first_num, const Rational& second_num) {
//  bool not_equal = (second_num < first_num || first_num < second_num);
//  return not_equal;
//}
//
//bool operator<=(const Rational& first_num, const Rational& second_num) {
//  return first_num < second_num || first_num == second_num;
//}
//
//bool operator>=(const Rational& first_num, const Rational& second_num) {
//  return first_num > second_num || first_num == second_num;
//}
//
//std::istream& operator>>(std::istream& stream, Rational& rational) {
//  stream >> rational.numerator_;
//  if (stream.peek() == '/') {
//    auto i = int('/');
//    stream >> i >> rational.denominator_;
//    if (rational.denominator_ == 0) {
//      throw RationalDivisionByZero{};
//    }
//  } else {
//    rational.denominator_ = 1;
//  }
//  rational.Reduction();
//  return stream;
//}
//
//std::ostream& operator<<(std::ostream& stream, const Rational& rational) {
//  if (rational.denominator_ == 1) {
//    stream << rational.numerator_;
//  } else {
//    stream << rational.numerator_ << '/' << rational.denominator_;
//  }
//  return stream;
//}