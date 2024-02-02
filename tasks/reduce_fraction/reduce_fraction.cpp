#include "reduce_fraction.h"
#include <algorithm>

int64_t ReduceFraction(int64_t numerator, int64_t denominator) {
    int64_t num = numerator;
    int64_t den = denominator;
    while (std::min(num, den) > 0) {  // gcd algorithm
        if (num > den) {
            num = num - den;
        } else {
            den = den - num;
        }
    }
    return numerator / std::max(num, den) + denominator / std::max(num, den);
}
