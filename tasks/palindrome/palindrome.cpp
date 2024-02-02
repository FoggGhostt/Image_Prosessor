#include "palindrome.h"

int64_t MoveLeftPointer(const std::string* str, int64_t i) {
    do {
        ++i;
    } while ((*str)[i] == ' ');
    return i;
}

int64_t Moverightpointer(const std::string* str, int64_t j) {
    do {
        --j;
    } while ((*str)[j] == ' ');
    return j;
}

bool IsPalindrome(const std::string& str) {
    int64_t length = std::size(str);
    int64_t i = 0;           // left pointer
    int64_t j = length - 1;  // right pointer
    const std::string* ptr = &str;
    while (i <= j) {
        i = MoveLeftPointer(ptr, i);
        j = Moverightpointer(ptr, j);
        if (i >= length || j <= -1 || str[i] != str[j]) {
            return false;
        }
    }
    return true;
}
