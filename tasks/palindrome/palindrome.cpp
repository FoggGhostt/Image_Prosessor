#include "palindrome.h"

size_t MoveLeftPointer(const std::string* str, size_t i) {
    while (i < str->size() && (*str)[i] == ' ') {
        ++i;
    }
    return i;
}

size_t Moverightpointer(const std::string* str, size_t j) {
    while (j > 0 && (*str)[j] == ' ') {
        --j;
    }
    return j;
}

bool IsPalindrome(const std::string& str) {
    size_t length = str.size();
    if (length < 2) {
        return true;
    }
    size_t i = 0;           // left pointer
    size_t j = length - 1;  // right pointer
    const std::string* ptr = &str;
    while (i < j) {
        i = MoveLeftPointer(ptr, i);
        j = Moverightpointer(ptr, j);
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}
