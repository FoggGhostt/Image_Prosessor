#include "password.h"

#include <cctype>

namespace password {
const char LEFT_ASCI_SYMB_BORDER = 33;
const char RIGHT_ASCI_SYMB_BORDER = 126;
const size_t MIN_LENGTH = 8;
const size_t MAX_LENGTH = 14;
}  // namespace password

bool IsCorrectASCI(const std::string& password) {
    for (char letter : password) {
        if (letter < password::LEFT_ASCI_SYMB_BORDER || letter > password::RIGHT_ASCI_SYMB_BORDER) {
            return false;
        }
    }
    return true;
}

bool CheckLength(const std::string& password) {
    return password.size() >= password::MIN_LENGTH && password.size() <= password::MAX_LENGTH;
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
