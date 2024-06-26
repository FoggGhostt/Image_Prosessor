#include "fibonacci.h"

int64_t CalculateNthFibonacci(int64_t n) {
    int64_t zero_fib = 0;
    int64_t first_fib = 1;
    if (n == 0) {
        return zero_fib;
    }
    for (int64_t i = 2; i <= n; ++i) {
        int64_t intermediate_fib = first_fib;
        first_fib = first_fib + zero_fib;
        zero_fib = intermediate_fib;
    }
    return first_fib;
}
