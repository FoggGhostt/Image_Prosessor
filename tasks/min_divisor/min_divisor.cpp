#include "min_divisor.h"

int64_t MinDivisor(int64_t number) {
    if ((number == 1) || (number == 2)) {
        return number;
    }
    for (int64_t i = 2; i * i < number + 1; ++i) {
        if (number % i == 0) {
            return i;
        }
    }
    return number;
}
