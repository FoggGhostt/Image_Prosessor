#include "is_leap.h"

bool IsLeap(int year) {
    bool ans = true;
    const int first_cond = 4;
    const int second_cond = 100;
    const int third_cond = 400;
    if (((year % first_cond == 0) && (year % second_cond != 0)) || (year % third_cond == 0)) {
        ans = true;
    } else {
        ans = false;
    }
    return ans;
}
