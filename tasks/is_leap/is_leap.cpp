#include "is_leap.h"

bool IsLeap(int year) {
    bool ans = true;
    const int a = 4;
    const int b = 100;
    const int c = 400;
    ans = (year >= 0) && (year % a == 0) && (year % b != 0) && (year % c == 0);
    return ans;
}
