#ifndef RATIONAL_H
#define RATIONAL_H

#pragma once
#include <iostream>

class Rational {
private:
    std::string firstNumberString;
    std::string secondNumberString;
    float firstNumberNumRead = 0;
    float firstNumberDemRead = 0;
    float firstNumber = 0;
    float secondNumberNumRead = 0;
    float secondNumberDemRead = 0;
    float secondNumber = 0;
    float intNumerator = 0;
    float intDenominator = 1;
    float result;
    char arOperator;
public:

    Rational();
    Rational(float, float);
    Rational(const Rational&);

    void write();
    bool read();

    Rational operator+(const Rational&) const;
    Rational operator-(const Rational&) const;
    Rational operator*(const Rational&) const;
    Rational operator/(const Rational&) const;
    Rational add(const Rational&) const;
    Rational subtract(const Rational&) const;
    Rational multiply(const Rational&) const;
    Rational devide(const Rational&) const;
  
};

#endif