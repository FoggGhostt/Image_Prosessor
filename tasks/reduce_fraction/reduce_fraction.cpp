#include "reduce_fraction.h"


int64_t ReduceFraction(int64_t numerator, int64_t denominator) {
    int64_t num = numerator;
    int64_t den = denominator;
    for (;;) {
        for (int64_t i = 2; i * i < numerator + 1; ++numerator) {
            if ((num % i == 0) && (den % i == 0)) {
                num = num / i;
                den = den / i;
                break;
            }
            return (num + den);
        }
        return num + den;
    }
}
