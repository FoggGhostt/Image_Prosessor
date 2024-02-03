#include "password.h"

bool IsCorrectASCI(const std::string *password) {
    const int left_border = 33;
    const int right_border = 126;
    for (size_t i = 0; i < (*password).size(); ++i) {
        if ((*password)[i] < left_border || (*password)[i] > right_border) {
            return false;
        }
    }
    return true;
}

bool CheckLength(const std::string *password) {
    const int min_length = 8;
    const int max_length = 14;
    return (*password).size() >= min_length && (*password).size() <= max_length;
}

bool Check3Conditions(const std::string *password) {
    
}

bool ValidatePassword(const std::string &password) {
    const std::string *ptr = &password;
}
