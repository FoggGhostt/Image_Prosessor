#include "tests_checking.h"

#include <iostream>
#include <array>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <string>

std::vector<std::string> StudentsOrder(const std::vector<StudentAction>& student_actions,
                                       const std::vector<size_t>& queries) {
    std::vector<std::string> top_side_students = {};
    std::vector<std::string> bottom_side_students = {};
    for (size_t i = 0; i < student_actions.size(); ++i) {
        if (student_actions[i].side == Side::Bottom) {
            bottom_side_students.push_back(student_actions[i].name);
        } else if (student_actions[i].side == Side::Top) {
            top_side_students.push_back(student_actions[i].name);
        }
    }
    std::vector<std::string> all_students = {};
    for (size_t j = top_side_students.size() - 1; ~j; --j) {
        all_students.push_back(top_side_students[j]);
    }
    for (size_t k = 0; k < bottom_side_students.size(); ++k) {
        all_students.push_back(bottom_side_students[k]);
    }
    std::vector<std::string> queue_of_all_students = {};
    for (size_t num : queries) {
        queue_of_all_students.push_back(all_students[num - 1]);
    }
    return queue_of_all_students;
}
