#pragma once

#include <vector>
#include <string>
#include <unordered_map>

struct Date {
    int day = 0;
    int month = 0;
    int year = 0;

    bool operator<(const Date& other) const {
        return std::tie(year, month, day) < std::tie(other.year, other.month, other.day);
    }
};

struct Student {
    std::string name;
    Date birth_date;

    bool operator<(const Student& other) const {
        return std::tie(name, birth_date) < std::tie(other.name, other.birth_date);
    }
};

struct University {
    std::string name;
    size_t max_students = 0;
};

struct Applicant {
    Student student;
    int points;
    std::vector<std::string> wish_list;
};

using AdmissionTable = std::unordered_map<std::string, std::vector<const Student*>>;

AdmissionTable FillUniversities(const std::vector<University>& universities, const std::vector<Applicant>& applicants);
