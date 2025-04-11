#include "calculator.h"
#include <stdexcept>

int Calculator::add(int a, int b) {
    // TODO
    long long result = (long long) a + (long long) b;
    if (result > INT_MAX || result < INT_MIN) {
        throw std::overflow_error("overflow/underflow");
    }
    return static_cast<int>(result);
}

int Calculator::sub(int a, int b) {
    // TODO
    long long result = (long long) a - (long long) b;
    if (result > INT_MAX || result < INT_MIN) {
        throw std::overflow_error("overflow/underflow");
    }
    return static_cast<int>(result);
}

int Calculator::mul(int a, int b) {
    // TODO
    long long result = (long long) a * (long long) b;
    if (result > INT_MAX || result < INT_MIN) {
        throw std::overflow_error("overflow/underflow");
    }
    return static_cast<int>(result);
}

int Calculator::div(int a, int b) {
    // TODO
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }

    if (a == INT_MIN && b == -1) {
        throw std::overflow_error("Division overflow");
    }

    return a / b;

}