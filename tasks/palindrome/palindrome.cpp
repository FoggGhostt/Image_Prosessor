#include "palindrome.h"

size_t MoveLeftPointer(const std::string& str, size_t i) {
    while (i < str.size() - 1 && str[i] == ' ') {
        ++i;
    }
    return i;
}

size_t MoveRightPointer(const std::string& str, size_t j) {
    while (j > 0 && str[j] == ' ') {
        --j;
    }
    return j;
}

bool IsPalindrome(const std::string& str) {
    size_t str_length = str.size();
    if (str_length < 2) {
        return true;
    }
    size_t left_ptr_to_str = 0;
    size_t right_ptr_to_str = str_length - 1;
    while (left_ptr_to_str < right_ptr_to_str) {
        left_ptr_to_str = MoveLeftPointer(str, left_ptr_to_str);
        right_ptr_to_str = MoveRightPointer(str, right_ptr_to_str);
        if (str[left_ptr_to_str] != str[right_ptr_to_str]) {
            return false;
        } else if (left_ptr_to_str < str.size() - 1 && right_ptr_to_str > 0) {
            ++left_ptr_to_str;
            --right_ptr_to_str;
        }
    }
    return true;
}
