#include "tests_checking.h"

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
        queue_of_all_students.emplace_back(all_students[num - 1]);
    }
    return queue_of_all_students;
}
