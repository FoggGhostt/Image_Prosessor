#include "is_leap.h"

namespace is_leap {
const int TRUE_SMALL_CYCLE = 4;
const int TRUE_LARGE_CYCLE = 100;
const int FALSE_CYCLE = 400;
}  // namespace is_leap

bool IsLeap(int year) {
    return (year % is_leap::TRUE_SMALL_CYCLE == 0 && year % is_leap::TRUE_LARGE_CYCLE != 0) ||
           year % is_leap::FALSE_CYCLE == 0;
}
