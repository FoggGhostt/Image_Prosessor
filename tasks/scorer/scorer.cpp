#include "scorer.h"
#include <algorithm>
#include <climits>
#include <string>
#include <utility>
#include <iostream>

bool EventsComparatop(const Event& event_1, const Event& event_2) {
    const std::string name1 = event_1.student_name;
    const std::string name2 = event_2.student_name;
    const std::string task_name1 = event_1.task_name;
    const std::string task_name2 = event_2.task_name;
    const int64_t time1 = event_1.time;
    const int64_t time2 = event_2.time;
    return std::tie(name1, task_name1, time1) < std::tie(name2, task_name2, time2);
}

struct CurentTask {
    std::string cur_student;
    std::string cur_task_name = "nothing";
    bool is_merge_request_open;
    bool is_checked;
    CurentTask() : cur_student("nothing"), cur_task_name("nothing"), is_merge_request_open(false), is_checked(false) {
    }
};

void AddTask(ScoreTable& table, const CurentTask& cur_task) {
    if (cur_task.cur_student != "nothing" && cur_task.is_checked == true && cur_task.is_merge_request_open == false) {
        auto iter = table.find(cur_task.cur_student);
        if (iter != table.end()) {
            iter->second.insert(cur_task.cur_task_name);
        } else {
            std::set<TaskName> task_set= {};
            task_set.insert(cur_task.cur_task_name);
            std::pair<std::string, std::set<TaskName>> pair(cur_task.cur_student, task_set);
            table.insert(pair);
        }
    }
}

void SetCheckMergeStatus(CurentTask& cur_task, Event& cur_event) {
    switch (cur_event.event_type) {
        case EventType::CheckFailed:
            cur_task.is_checked = false;
            break;
        case EventType::CheckSuccess:
            cur_task.is_checked = true;
            break;
        case EventType::MergeRequestOpen:
            cur_task.is_merge_request_open = true;
            break;
        case EventType::MergeRequestClosed:
            cur_task.is_merge_request_open = false;
            break;
    }
}

ScoreTable GetScoredStudents(const Events& events, time_t score_time) {
    ScoreTable answer_table = {};
    std::vector<Event> sortedbly_events = {};
    for (const Event& event : events) {
        sortedbly_events.push_back(event);
    }
    std::sort(sortedbly_events.begin(), sortedbly_events.end(), EventsComparatop);
    Event pseudo = {};
    pseudo.student_name = "new event for update last task of last student";
    sortedbly_events.push_back(pseudo);
    CurentTask cur_task = {};
    for (Event& event : sortedbly_events) {
        if (event.student_name != cur_task.cur_student || event.task_name != cur_task.cur_task_name) {
            AddTask(answer_table, cur_task);
            cur_task.cur_student = event.student_name;
            cur_task.cur_task_name = event.task_name;
        }
        SetCheckMergeStatus(cur_task, event);
    }
    return answer_table;
}
