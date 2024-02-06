#include "password.h"

#include <cctype>

bool IsCorrectASCI(const std::string& password) {
    const char left_border_asci_symb = 33;
    const char right_border_asci_symb = 126;
    for (char letter : password) {
        if (letter < left_border_asci_symb || letter > right_border_asci_symb) {
            return false;
        }
    }
    return true;
}

bool CheckLength(const std::string& password) {
    const size_t min_length = 8;
    const size_t max_length = 14;
    return password.size() >= min_length && password.size() <= max_length;
}

bool CheckUppercase(const std::string& password) {
    for (char letter : password) {
        if (std::isupper(letter)) {
            return true;
        }
    }
    return false;
}

bool CheckLowercase(const std::string& password) {
    for (char letter : password) {
        if (std::islower(letter)) {
            return true;
        }
    }
    return false;
}

bool CheckDigits(const std::string& password) {
    for (char letter : password) {
        if (std::isdigit(letter)) {
            return true;
        }
    }
    return false;
}

bool CheckAnother(const std::string& password) {
    for (char letter : password) {
        if (!std::isupper(letter) && !std::islower(letter) && !std::isdigit(letter)) {
            return true;
        }
    }
    return false;
}

bool ValidatePassword(const std::string& password) {
    if (!IsCorrectASCI(password) || !CheckLength(password)) {
        return false;
    }
    const bool up_letter_flag = CheckUppercase(password);
    const bool low_letter_flag = CheckLowercase(password);
    const bool digits_letter_flag = CheckDigits(password);
    const bool another_letter_flag = CheckAnother(password);
    const int count_of_diff_letters_type = up_letter_flag + low_letter_flag + digits_letter_flag + another_letter_flag;
    return (count_of_diff_letters_type >= 3);
}
