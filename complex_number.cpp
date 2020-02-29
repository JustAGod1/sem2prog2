//
// Created by justagod on 2/29/20.
//

#include <cmath>
#include <iostream>
#include "complex_number.h"

using namespace std;
ComplexNumber::ComplexNumber(float real, float imaginary) : real(real), imaginary(imaginary) {}

ComplexNumber::ComplexNumber(float real) : real(real), imaginary(0) {}

ComplexNumber::ComplexNumber() : real(0), imaginary(0) {}

ComplexNumber::ComplexNumber(ComplexNumber &real) : real(real.real), imaginary(real.imaginary) {}

void ComplexNumber::mul(float value) {
    real *= value;
    imaginary *= value;
}

void ComplexNumber::mul(ComplexNumber &value) {
    real = real * value.real - imaginary * value.imaginary;
    imaginary = imaginary * value.real + value.imaginary * real;
}

void ComplexNumber::add(ComplexNumber &value) {
    real += value.real;
    imaginary += value.imaginary;
}

float ComplexNumber::len() {
    return std::sqrt(real * real + imaginary * imaginary);
}

void ComplexNumber::print() {
    if (real == 0 && imaginary == 0) {
        cout << 0 << endl;
    } else if (imaginary == 0) {
        cout << real << endl;
    } else if (imaginary >= 0) {
        cout << real << " + " << imaginary << "i" << endl;
    } else {
        cout << real << " - " << abs(imaginary) << "i" << endl;
    }
}


