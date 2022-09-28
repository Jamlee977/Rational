#include "Rational.h"
#include <iostream>

int main() {
    Rational R1(1, 3);
    Rational R2(1, 6);
    Rational R3 = R1 + R2;
    R3.write(); // ! will print out 1/2
    Rational R4 = R1 - R2;
    R4.write(); // ! will print out 1/6
    Rational R5 = R1 * R2;
    R5.write(); // ! will print out 1/18
    Rational R6 = R1 / R2;
    R6.write(); // ! will print out 1/0.5 which is basically 2

    Rational RFinal;
    RFinal.read(); // ! Enter 1/3 + 1/6 (make sure there are spaces in between)



}