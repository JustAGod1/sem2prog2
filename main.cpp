#include <iostream>
#include "complex_number.h"

#pragma clang diagnostic ignored "-Wmissing-noreturn"
using namespace std;
// Okay i don't know what it is supposed to be
// but assume it's just some kind of state machine
class MeNu {
private:
    ComplexNumber *current_value;

    ComplexNumber *make_number();
    ComplexNumber *make_number_rvi();
    ComplexNumber *make_number_r();

    float obtain_real();
    void print_value();

    void print_help();

public:
    void run();

};

ComplexNumber *MeNu::make_number() {
    cout << "You have to provide data for complex number constructor" << endl;
    cout << "Choose one:" << endl;
    cout << "  1 - real with imaginary" << endl;
    cout << "  2 - real only" << endl;
    cout << "  3 - make just zero" << endl;
    int number;
    while (true) {
        cout << "Constructor number(1-3): ";
        cin >> number;
        switch (number) {
            case 1:
                return make_number_rvi();
            case 2:
                return make_number_r();
            case 3:
                return new ComplexNumber();
            default:
                break;
        }
    }
}

ComplexNumber *MeNu::make_number_rvi() {
    cout << "real: ";
    float real;
    cin >> real;
    cout << "imaginary: ";
    float imaginary;
    cin >> imaginary;

    return new ComplexNumber(real, imaginary);
}

ComplexNumber *MeNu::make_number_r() {
    cout << "real: ";
    float real;
    cin >> real;

    return new ComplexNumber(real);
}

float MeNu::obtain_real() {
    cout << "real: ";
    float real;
    cin >> real;

    return real;
}

void MeNu::print_value() {
    current_value->print();
}

void MeNu::run() {
    current_value = make_number();

    while (true) {
        cout << "Type a command(h for help): ";
        string cmd;
        cin >> cmd;
        if (cmd == "h") {
            print_help();
        } else if (cmd == "add") {
            current_value->add(*make_number());
        } else if (cmd == "mul") {
            current_value->mul(*make_number());
        } else if (cmd == "mul_real") {
            current_value->mul(obtain_real());
        } else if (cmd == "len") {
            cout << current_value->len() << endl;
        } else if (cmd == "print") {
            current_value->print();
        }
    }
}

void MeNu::print_help() {
    cout << "  add - adds complex number" << endl;
    cout << "  mul - multiply by complex number" << endl;
    cout << "  mul_real - multiply by real number" << endl;
    cout << "  len - prints length of current complex number" << endl;
    cout << "  print - prints current number" << endl;
    cout << "  h - prints this message" << endl;
}

int main() {
    MeNu menu{};

    menu.run();
    return 0;
}
