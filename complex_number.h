//
// Created by justagod on 2/29/20.
//

#ifndef PROG2_COMPLEX_NUMBER_H
#define PROG2_COMPLEX_NUMBER_H

class ComplexNumber {
private:
    float real, imaginary;
public:
    ComplexNumber();
    ComplexNumber(float real, float imaginary);
    explicit ComplexNumber(float real);
    ComplexNumber(ComplexNumber &real);

    void mul(float value);
    void mul(ComplexNumber &value);
    void add(ComplexNumber &value);
    float len();
    void print();
};

#endif //PROG2_COMPLEX_NUMBER_H
