#include "tests_checking.h"

#include <iostream>
#include <array>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <string>
#include <deque>

std::vector<std::string> StudentsOrder(const std::vector<StudentAction>& student_actions,
                                       const std::vector<size_t>& queries) {
    std::deque<std::string> all_students; 
    for (const StudentAction& student : student_actions) {
        if (student.side == Side::Bottom) {
            all_students.push_back(student.name);
        } else if (student.side == Side::Top){
            all_students.push_front(student.name);
        }
    }
    std::vector<std::string> queue_of_all_students = {};
    for (size_t num : queries) {
        queue_of_all_students.push_back(all_students[num - 1]);
    }
    return queue_of_all_students;
}
