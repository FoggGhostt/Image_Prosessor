#include "fibonacci.h"

int64_t CalculateNthFibonacci(int64_t n) {
    int64_t first_fib = 1;
    int64_t second_fib = 1;
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    for (int64_t i = 2; i < n; ++i) {
        int64_t cur_fib = first_fib + second_fib; // считаю очередное число фибоначи
        first_fib = second_fib;
        second_fib = cur_fib;
    }
    return second_fib;
}
