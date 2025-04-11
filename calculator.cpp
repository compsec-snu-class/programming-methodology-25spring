#include "calculator.h"
#include <stdexcept>
#include <limits>
#include <iostream>

int Calculator::add(int a, int b) {
    // TODO 
    if (b < 0 && a < std::numeric_limits<int>::min() - b) {
        throw std::overflow_error("Underflow!");
    }
    if (b > 0 && a > std::numeric_limits<int>::max() - b) {
        throw std::overflow_error("Overflow!");
    }
    return a+b;
    
}

int Calculator::sub(int a, int b) {
    // TODO
    if ((b < 0 && a > std::numeric_limits<int>::max() + b) ||
        (b > 0 && a < std::numeric_limits<int>::min() + b)) {
        throw std::overflow_error("Subtraction overflow/underflow");
    }
    return a-b;
}

int Calculator::mul(int a, int b) {
    // TODO
    if (a > 0 && b > 0 && a > std::numeric_limits<int>::max() / b)
        throw std::overflow_error("Multiplication overflow");
    if (a > 0 && b < 0 && b < std::numeric_limits<int>::min() / a)
        throw std::overflow_error("Multiplication overflow");
    if (a < 0 && b > 0 && a < std::numeric_limits<int>::min() / b)
        throw std::overflow_error("Multiplication overflow");
    if (a < 0 && b < 0 && a < std::numeric_limits<int>::max() / b)
        throw std::overflow_error("Multiplication overflow");
    return a*b;
}

int Calculator::div(int a, int b) {
    // TODO
    if (a == std::numeric_limits<int>::min() && b == -1) {
        throw std::overflow_error("Overflow in division");
    }
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a/b;
}