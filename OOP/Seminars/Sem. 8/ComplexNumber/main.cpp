#include "ComplexNumber.h"
#include <iostream>

int main() {
    ComplexNumber c(3, 4);
    ComplexNumber c2(3, 4);

    std::cout << c * c2;
}