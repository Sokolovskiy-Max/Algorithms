//#pragma once
//#include <stdexcept>
//#include <iostream>
//#include <numeric>
//
//class RationalDivisionByZero : public std::runtime_error {
// public:
//  RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
//  }
//};
//
//class Rational {
//  int numerator_;
//
//  int denominator_;
//
//  inline void Reduction() {
//    int a = std::gcd(numerator_, denominator_);
//    numerator_ /= a;
//    denominator_ /= a;
//    if (denominator_ < 0) {
//      numerator_ *= -1;
//      denominator_ *= -1;
//    }
//  }
//
// public:
//  Rational();
//
//  Rational(int first_num);  // NOLINT
//
//  Rational(int first_num, int second_num);
//
//  int GetNumerator() const;
//
//  int GetDenominator() const;
//
//  void SetNumerator(int first_num);
//
//  void SetDenominator(int first_num);
//
//  Rational& operator+=(const Rational& rational);
//
//  Rational& operator-=(const Rational& rational);
//
//  Rational& operator/=(const Rational& rational);
//
//  Rational& operator*=(const Rational& rational);
//
//  friend Rational operator+(const Rational& first_num, const Rational& second_num);
//                                            
//  friend Rational operator-(const Rational& first_num, const Rational& second_num);
//                                            
//  friend Rational operator/(const Rational& first_num, const Rational& second_num);
//                                            
//  friend Rational operator*(const Rational& first_num, const Rational& second_num);
//
//  friend Rational operator+(const Rational& rational);
//
//  friend Rational operator-(const Rational& rational);
//
//  Rational& operator++();
//
//  Rational operator++(int);
//
//  Rational& operator--();
//
//  Rational operator--(int);
//
//  friend bool operator<(const Rational& first_num, const Rational& second_num);
//
//  friend bool operator>(const Rational& first_num, const Rational& second_num);
//
//  friend bool operator==(const Rational& first_num, const Rational& second_num);
//
//  friend bool operator!=(const Rational& first_num, const Rational& second_num);
//
//  friend bool operator<=(const Rational& first_num, const Rational& second_num);
//
//  friend bool operator>=(const Rational& first_num, const Rational& second_num);
//
//  friend std::istream& operator>>(std::istream& stream, Rational& rational);
//
//  friend std::ostream& operator<<(std::ostream& stream, const Rational& rational);
//};