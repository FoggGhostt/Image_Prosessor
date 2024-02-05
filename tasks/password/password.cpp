#include "password.h"
#include <cctype>

bool IsCorrectASCI(const std::string& password) {
    const int left_border = 33;
    const int right_border = 126;
    for (size_t i = 0; i < password.size(); ++i) {
        if (password[i] < left_border || password[i] > right_border) {
            return false;
        }
    }
    return true;
}

bool CheckLength(const std::string& password) {
    const int min_length = 8;
    const int max_length = 14;
    return password.size() >= min_length && password.size() <= max_length;
}

int CheckUppercase(const std::string& password) {
    for (size_t i = 0; i < password.size(); ++i) {
        if (std::isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

int CheckLowercase(const std::string& password) {
    for (size_t i = 0; i < password.size(); ++i) {
        if (std::islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

int CheckDigits(const std::string& password) {
    for (size_t i = 0; i < password.size(); ++i) {
        if (std::isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

int CheckAnother(const std::string& password) {
    for (size_t i = 0; i < password.size(); ++i) {
        if (!std::isupper(password[i]) && !std::islower(password[i]) && !std::isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

bool ValidatePassword(const std::string& password) {
    const int up_letter = CheckUppercase(password);
    const int low_letter = CheckLowercase(password);
    const int digits_letter = CheckDigits(password);
    const int another_letter = CheckAnother(password);
    const int count_of_diff_letters_type = up_letter + low_letter + digits_letter + another_letter;
    return (IsCorrectASCI(password) && CheckLength(password) && count_of_diff_letters_type >= 3);
}
