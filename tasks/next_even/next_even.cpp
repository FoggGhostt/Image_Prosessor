#include "next_even.h"

int64_t NextEven(int64_t n) {
    return n + n % 2 + 2 * ((n + 1) % 2);
}
