#include "fibonacci.h"

int64_t CalculateNthFibonacci(int64_t n) {
    int64_t first_fib = 0;
    int64_t second_fib = 1;
    if (n == 1) {
        return first_fib;
    }
    for (int i = 2; i < n; ++i) {
        int64_t cur_fib = first_fib + second_fib; // считаю очередное число фибоначи
        first_fib = second_fib;
        second_fib = cur_fib;
    }
    return second_fib;
}
