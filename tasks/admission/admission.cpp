#include "admission.h"
#include <string>
#include <string_view>
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
#include <iostream>

bool StudentComparatop(const Applicant& applicant_1, const Applicant& applicant_2) {
    const int stud_year1 = applicant_1.student.birth_date.year;
    const int stud_year2 = applicant_2.student.birth_date.year;
    const int stud_month1 = applicant_1.student.birth_date.month;
    const int stud_month2 = applicant_2.student.birth_date.month;
    const int stud_day1 = applicant_1.student.birth_date.day;
    const int stud_day2 = applicant_2.student.birth_date.day;
    const std::string std_name1 = applicant_1.student.name;
    const std::string std_name2 = applicant_2.student.name;
    int neg_stud_points_1 = -applicant_1.points;
    int neg_stud_points_2 = -applicant_2.points;
    auto comparable_applicant1 = std::tie(neg_stud_points_1, stud_year1, stud_month1, stud_day1, std_name1);
    auto comparable_applicant2 = std::tie(neg_stud_points_2, stud_year2, stud_month2, stud_day2, std_name2);
    return comparable_applicant1 < comparable_applicant2;
}

std::string ChoseUviversity(std::unordered_map<std::string, size_t>& universities, const Applicant& applicant) {
    for (const std::string& university : applicant.wish_list) {
        if (applicant.points >= universities[university]) {
            return university;
        }
    }
    return "admission failed";
}

AdmissionTable FillUniversities(const std::vector<University>& universities, const std::vector<Applicant>& applicants) {
    std::vector<Applicant> sortedbly_applicants = {};
    for (const Applicant& applicant : applicants) {
        sortedbly_applicants.push_back(applicant);
    }
    std::sort(sortedbly_applicants.begin(), sortedbly_applicants.end(), StudentComparatop);
    std::unordered_map<std::string, size_t> university_scores = {};
    for (const University& university : universities) {
        university_scores[university.name] = university.max_students;
    }
    // Создание пустой AdmissionTable
    std::unordered_map<std::string, std::vector<const Student*>> answer = {};
    for (const Applicant& applicant : applicants) {
        std::string chosen_university = ChoseUviversity(university_scores, applicant);
        
        if (chosen_university != "admission failed") {
            answer[chosen_university].push_back(&applicant.student);
        }
    }
    for (const auto& pair : answer) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    return answer;
}
