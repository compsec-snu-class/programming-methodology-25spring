#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    // TODO
    if (a + b >= std::numeric_limits<int>::max()) {
        throw std::overflow_error("Overflow Error");
    }
    else if (a + b <= std::numeric_limits<int>::min()){
        throw std::overflow_error("Underflow Error");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    // TODO
    if (a - b >= std::numeric_limits<int>::max()) {
        throw std::overflow_error("Overflow Error");
    }
    else if (a - b <= std::numeric_limits<int>::min()){
        throw std::overflow_error("Underflow Error");
    }
    return a - b;
}

#include <limits>
#include <stdexcept>

int Calculator::mul(int a, int b) {
    if (a > 0) {
        if (b > 0) {
            if (a > std::numeric_limits<int>::max() / b)
                throw std::overflow_error("Overflow Error");
        } 
        else {
            if (b < std::numeric_limits<int>::min() / a)
                throw std::overflow_error("Underflow Error");
        }
    } 
    else {
        if (b > 0) {
            if (a < std::numeric_limits<int>::min() / b)
                throw std::overflow_error("Underflow Error");
        } 
        else {
            if (a != 0 && b < std::numeric_limits<int>::max() / a)
                throw std::overflow_error("Overflow Error");
        }
    }
    return a * b;
}


int Calculator::div(int a, int b) {
    // TODO
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    else if (abs(a / b) <= std::numeric_limits<int>::min()){
        throw std::overflow_error("Overflow Error");
    }
    return a / b;
}