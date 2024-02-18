#include "tests_checking.h"

#include <iostream>
#include <deque>
#include <string_view>

std::vector<std::string> StudentsOrder(const std::vector<StudentAction>& student_actions,
                                       const std::vector<size_t>& queries) {
    std::deque<std::string_view> all_students;
    for (const StudentAction& student : student_actions) {
        if (student.side == Side::Bottom) {
            all_students.emplace_back(student.name);
        } else if (student.side == Side::Top) {
            all_students.emplace_front(student.name);
        }
    }
    std::vector<std::string> queue_of_all_students = {};
    for (size_t num : queries) {
        std::string new_string(all_students[num - 1]);
        queue_of_all_students.push_back(new_string);
    }
    return queue_of_all_students;
}
