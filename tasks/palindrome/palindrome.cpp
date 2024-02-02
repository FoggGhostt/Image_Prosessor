#include "palindrome.h"

size_t MoveLeftPointer(const std::string* str, size_t i) {
    do {
        ++i;
    } while ((*str)[i] == ' ');
    return i;
}

size_t Moverightpointer(const std::string* str, size_t j) {
    do {
        --j;
    } while ((*str)[j] == ' ');
    return j;
}

bool IsPalindrome(const std::string& str) {
    size_t length = std::size(str);
    size_t i = 0;           // left pointer
    size_t j = length - 1;  // right pointer
    const std::string* ptr = &str;
    while (i <= j) {
        if (str[i] != str[j]) {
            return false;
        }
        i = MoveLeftPointer(ptr, i);
        j = Moverightpointer(ptr, j);
    }
    return true;
}
