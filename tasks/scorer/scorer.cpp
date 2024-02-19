#include "scorer.h"

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

struct TaskCondition {
    std::string cur_student;
    std::string cur_task_name = "nothing";
    bool is_merge_request_open;
    bool is_checked;
    TaskCondition()
        : cur_student("nothing"), cur_task_name("nothing"), is_merge_request_open(false), is_checked(false) {
    }
};

using StudentTable = std::map<StudentName, std::map<TaskName, TaskCondition>>;

bool EventsTimeComparatop(const Event& event_1, const Event& event_2) {
    return event_1.time < event_2.time;
}

void SetTaskCondition(const Event& event, StudentTable& stud_table) {
    auto iter_stud = stud_table.find(event.student_name);
    if (iter_stud == stud_table.end()) {
        std::string name = event.student_name;
        std::map<TaskName, TaskCondition> tasks = {};
        std::pair<std::string, std::map<TaskName, TaskCondition>> new_stud(name, tasks);
        stud_table.insert(new_stud);
    }
    auto iter_task = stud_table[event.student_name].find(event.task_name);
    if (iter_task == stud_table[event.student_name].end()) {
        TaskName task = event.task_name;
        TaskCondition task_cond = {};
        std::pair<TaskName, TaskCondition> new_task(task, task_cond);
    }
    switch (event.event_type) {
        case EventType::CheckFailed:
            stud_table[event.student_name][event.task_name].is_checked = false;
            break;
        case EventType::CheckSuccess:
            stud_table[event.student_name][event.task_name].is_checked = true;
            break;
        break;
        case EventType::MergeRequestOpen:
            stud_table[event.student_name][event.task_name].is_merge_request_open = true;
            break;
        case EventType::MergeRequestClosed:
            stud_table[event.student_name][event.task_name].is_merge_request_open = false;
            break;
        }
}

ScoreTable GetScoredStudents(const Events& events, time_t score_time) {
    ScoreTable answer_table = {};
    StudentTable student_table = {};
    std::vector<Event> sortedbly_student = {};
    for (const Event& event : events) {
         sortedbly_student.emplace_back(event);
    }
    std::sort(sortedbly_student.begin(), sortedbly_student.end(), EventsTimeComparatop);
    for (const Event& event : sortedbly_student) {
        if (event.time <= score_time) {
            SetTaskCondition(event, student_table);
        }
    }
    for (auto& name : student_table) {
        for (auto& task : name.second) {
            if (task.second.is_checked == true && task.second.is_merge_request_open == false) {
                auto iter_stud_set = answer_table.find(name.first);
                if (iter_stud_set == answer_table.end()) {
                    auto empty_set_of_tasks = std::set<TaskName>();
                    std::pair<StudentName, std::set<TaskName>> new_stud(name.first, empty_set_of_tasks);
                    answer_table.insert(new_stud);
                }
                answer_table[name.first].insert(task.first);
            }
        }
    }
    return answer_table;
}
