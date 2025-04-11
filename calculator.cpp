#include "calculator.h"
#include <iostream>
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    // TODO
    if ((b > 0) && (a > std::numeric_limits<int>::max() - b)) {
        throw std::overflow_error("Addition overflow");
    }
    if ((b < 0) && (a < std::numeric_limits<int>::min() - b)) {
        throw std::overflow_error("Addition underflow");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    // TODO
    if ((b < 0) && (a > std::numeric_limits<int>::max() + b)) {
        throw std::overflow_error("Subtraction overflow");
    }
    if ((b > 0) && (a < std::numeric_limits<int>::min() + b)) {
        throw std::overflow_error("Subtraction underflow");
    }
    return a - b;
}

int Calculator::mul(int a, int b) {
    // TODO
    if (a == 0 || b == 0) return 0;

    // Check for overflow
    if (a > 0) {
        if (b > 0) {
            if (a > std::numeric_limits<int>::max() / b)
                throw std::overflow_error("Multiplication overflow");
        } else {
            if (b < std::numeric_limits<int>::min() / a)
                throw std::overflow_error("Multiplication underflow");
        }
    } else {
        if (b > 0) {
            if (a < std::numeric_limits<int>::min() / b)
                throw std::overflow_error("Multiplication underflow");
        } else {
            if (a != 0 && b < std::numeric_limits<int>::max() / a)
                throw std::overflow_error("Multiplication overflow");
        }
    }

    return a * b;
}

int Calculator::div(int a, int b) {
    // TODO
    if (b == 0) {
        throw std::overflow_error("Division by zero");
    }

    // Special overflow case: INT_MIN / -1 overflows
    if (a == std::numeric_limits<int>::min() && b == -1) {
        throw std::overflow_error("Division overflow: INT_MIN / -1");
    }

    return a / b;
}