#include "Rational.h"
#include <iostream>

/**
 * @brief Construct a new Rational object that assigns values
 * 
 */
Rational::Rational() {
    this->intNumerator   = 0;
    this->intDenominator = 1;
    result = 0.0f;
}

Rational::Rational(float num, float den) : intNumerator(num), intDenominator(den) {}

Rational::Rational(const Rational& ratio) {
    this->intNumerator   = ratio.intNumerator;
    this->intDenominator = ratio.intDenominator;
}

/**
 * @brief A method that prints that rational number in the form of x/y
 * 
 */
void Rational::write() {
    intDenominator /= intNumerator;
    intNumerator /= intNumerator;
    std::cout << intNumerator << "/" << intDenominator << '\n';
}

/**
 * @brief A method that reads two rational numbers and an operator
 * x/y
 * '+' or '-' or '*' or '/'
 * a/b
 * 
 * then it combines them all and gets the actual result
 * E.g:
 * 1/3
 * +
 * 1/6
 * it prints out: 1/3 + 1/6 = 1/2
 * 
 * @return true 
 * @return false 
 */
bool Rational::read() {
    // reads first string
    std::cin >> firstNumberString;

    //gets where '/' is
    int fIndex = firstNumberString.find('/');

    // assigns the first part which is 'x' in the numerator until it finds '/'
    for(int i = 0; firstNumberString[i] != '\0'; i++) {
        if(i == fIndex) break;
        if(i == 0 && firstNumberString[i] == '-') continue;
        else if(firstNumberString[i] == '.') break;
        if(firstNumberString[i] > '9' || firstNumberString[i] < '0') break;
        firstNumberNumRead = firstNumberNumRead * 10 + firstNumberString[i] - '0';
    }

    fIndex++;
    // assigns the second part which is 'y' in the denominator until the end
    for(; firstNumberString[fIndex] != '\0'; fIndex++) {
        if(firstNumberString[fIndex] == '.') break;
        if(firstNumberString[fIndex] > '9' || firstNumberString[fIndex] < '0') break;
        firstNumberDemRead = firstNumberDemRead * 10 + firstNumberString[fIndex] - '0';
    }

    // result = numerator / denominator
    firstNumber = firstNumberNumRead / firstNumberDemRead;

    // reads operator
    std::cin >> arOperator;
    if(arOperator == '+' || arOperator == '-' ||
        arOperator == '*' || arOperator == '/') {
        std::cin >> secondNumberString;
        //gets where '/' is
        int sIndex = secondNumberString.find('/');

        // assigns the first part which is 'x' in the numerator until it finds '/'
        for(int i = 0; secondNumberString[i] != '\0'; i++) {
            if(i == sIndex) break;
            if(i == 0 && secondNumberString[i] == '-') continue;
            else if(secondNumberString[i] == '.') break;
            if(secondNumberString[i] > '9' || secondNumberString[i] < '0') break;
            secondNumberNumRead = secondNumberNumRead * 10 + secondNumberString[i] - '0';
        }

        sIndex++;

        // assigns the second part which is 'y' in the denominator until the end
        for(; secondNumberString[sIndex] != '\0'; sIndex++) {
            if(secondNumberString[sIndex] == '.') break;
            if(secondNumberString[sIndex] > '9' || secondNumberString[sIndex] < '0') break;
            secondNumberDemRead = secondNumberDemRead * 10 + secondNumberString[sIndex] - '0';
        }

        // result = numerator / denominator
        secondNumber = secondNumberNumRead / secondNumberDemRead;
        
        //checks what the operator is and does what the operator needs to do.
        switch(arOperator) {
        case '+':
            firstNumberDemRead /= firstNumberNumRead;
            firstNumberNumRead /= firstNumberNumRead;
            secondNumberDemRead /= secondNumberNumRead;
            secondNumberNumRead /= secondNumberNumRead;
            std::cout << firstNumberString << " + " << secondNumberString << " = " <<
                ((firstNumberNumRead * secondNumberDemRead) +
                 (firstNumberDemRead * secondNumberNumRead)) / ((firstNumberDemRead)) << '/' <<
                 (firstNumberDemRead * secondNumberDemRead) / ((firstNumberDemRead));
        
        break;
        case '-':
            firstNumberDemRead /= firstNumberNumRead;
            firstNumberNumRead /= firstNumberNumRead;
            secondNumberDemRead /= secondNumberNumRead;
            secondNumberNumRead /= secondNumberNumRead;
            std::cout << firstNumberString << " - " << secondNumberString << " = " <<
                ((firstNumberNumRead * secondNumberDemRead) -
                 (firstNumberDemRead * secondNumberNumRead)) / (firstNumberDemRead) << '/' <<
                 (firstNumberDemRead * secondNumberDemRead) / (firstNumberDemRead);
            break;
        case '*':
            firstNumberDemRead /= firstNumberNumRead;
            firstNumberNumRead /= firstNumberNumRead;
            secondNumberDemRead /= secondNumberNumRead;
            secondNumberNumRead /= secondNumberNumRead;
            std::cout << firstNumberString << " * " << secondNumberString << " = " <<
            (firstNumberNumRead * secondNumberNumRead) << '/' <<
            (firstNumberDemRead * secondNumberDemRead);
            break;
        case '/':
            firstNumberDemRead /= firstNumberNumRead;
            firstNumberNumRead /= firstNumberNumRead;
            secondNumberDemRead /= secondNumberNumRead;
            secondNumberNumRead /= secondNumberNumRead;
            std::cout << firstNumberString << " * " << secondNumberString << " = " <<
            (firstNumberNumRead * secondNumberDemRead) << '/' <<
            (firstNumberDemRead * secondNumberNumRead);
            break;
        default:
            return false;
        }
        return true;
    }
    
    return false;
}

/**
 * @brief An add method to add 2 rationals
 * 
 * @param fractionNumber 
 * @return Rational 
 */
Rational Rational::add(const Rational& fractionNumber) const {
    return Rational(((this->intNumerator * fractionNumber.intDenominator) + 
    (this->intDenominator * fractionNumber.intNumerator)), 
    this->intDenominator * fractionNumber.intDenominator);
}

/**
 * @brief An subtract method to subtract 2 rationals
 * 
 * @param fractionNumber 
 * @return Rational 
 */
Rational Rational::subtract(const Rational& fractionNumber) const {
    return Rational(((this->intNumerator * fractionNumber.intDenominator) -
    (this->intDenominator * fractionNumber.intNumerator)), 
    this->intDenominator * fractionNumber.intDenominator);
}

/**
 * @brief An multiply method to multiply 2 rationals
 * 
 * @param fractionNumber 
 * @return Rational 
 */
Rational Rational::multiply(const Rational& fractionNumber) const {
    return Rational(this->intNumerator * fractionNumber.intNumerator,
                    this->intDenominator * fractionNumber.intDenominator);
}

/**
 * @brief An devide method to devide 2 rationals
 * 
 * @param fractionNumber 
 * @return Rational 
 */
Rational Rational::devide(const Rational& fractionNumber) const {
    return Rational(this->intNumerator * fractionNumber.intDenominator,
                    this->intDenominator * fractionNumber.intNumerator);
}

/**
 * @brief A operator overloading of the '+' sign, it does what add() does
 * 
 * @param ratio 
 * @return Rational 
 */
Rational Rational::operator+(const Rational& ratio) const {
    return Rational(((this->intNumerator * ratio.intDenominator) + 
    (this->intDenominator * ratio.intNumerator)), 
    this->intDenominator * ratio.intDenominator);
}

/**
 * @brief A operator overloading of the '-' sign, it does what subtract() does
 * 
 * @param ratio 
 * @return Rational 
 */
Rational Rational::operator-(const Rational& ratio) const {
    return Rational(((this->intNumerator * ratio.intDenominator) - 
    (this->intDenominator * ratio.intNumerator)), 
    this->intDenominator * ratio.intDenominator);
}

/**
 * @brief A operator overloading of the '*' sign, it does what multiply() does
 * 
 * @param ratio 
 * @return Rational 
 */
Rational Rational::operator*(const Rational& ratio) const {
    return Rational(this->intNumerator * ratio.intNumerator,
                    this->intDenominator * ratio.intDenominator);
}

/**
 * @brief A operator overloading of the '/' sign, it does what devide() does
 * 
 * @param ratio 
 * @return Rational 
 */
Rational Rational::operator/(const Rational& ratio) const {
    return Rational(this->intNumerator * ratio.intDenominator,
                    this->intDenominator * ratio.intNumerator);
}
