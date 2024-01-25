#include "fibonacci.h"

int64_t CalculateNthFibonacci(int64_t n) {
    int first_fib = 0;
    int second_fib = 1;
    if (n == 0) {
        return first_fib;
    }
    for (int i = 1; i < n; ++i) {
        int cur_fib = first_fib + second_fib; // считаю очередное число фибоначи
        first_fib = second_fib;
        second_fib = cur_fib;
    }
    return second_fib;
}
