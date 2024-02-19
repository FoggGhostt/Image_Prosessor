#include "admission.h"

#include <algorithm>

namespace not_admissioned {
const std::string FAIL = "admission failed";
}  // namespace not_admissioned

bool ApplicantComparatopPointPriority(const Applicant& applicant1, const Applicant& applicant2) {
    int neg_point1 = -applicant1.points;
    int neg_point2 = -applicant2.points;
    return std::tie(neg_point1, applicant1.student.birth_date, applicant1.student.name) <
           std::tie(neg_point2, applicant2.student.birth_date, applicant2.student.name);
}

bool StudentComparatorNamePriority(const Student* stud1, const Student* stud2) {
    return (*stud1) < (*stud2);
}

std::string ChooseUviversity(std::unordered_map<std::string, size_t>& universities, const Applicant& applicant,
                             AdmissionTable& answer) {
    for (const std::string& university : applicant.wish_list) {
        if (answer[university].size() - universities[university] > 0) {
            return university;
        }
    }
    return not_admissioned::FAIL;
}

AdmissionTable FillUniversities(const std::vector<University>& universities, const std::vector<Applicant>& applicants) {
    std::vector<Applicant> sortedbly_applicants = {};
    for (const Applicant& applicant : applicants) {
        sortedbly_applicants.push_back(applicant);
    }
    std::sort(sortedbly_applicants.begin(), sortedbly_applicants.end(), ApplicantComparatopPointPriority);
    std::unordered_map<std::string, size_t> university_scores = {};
    for (const University& university : universities) {
        university_scores[university.name] = university.max_students;
    }
    // Создание пустой AdmissionTable
    std::unordered_map<std::string, std::vector<const Student*>> admission_table_answer = {};
    for (const Applicant& applicant : applicants) {
        std::string chosen_university = ChooseUviversity(university_scores, applicant, admission_table_answer);
        if (chosen_university != not_admissioned::FAIL) {
            admission_table_answer[chosen_university].push_back(&applicant.student);
        }
    }
    for (auto& [_, university_students_list] : admission_table_answer) {
        std::sort(university_students_list.rbegin(), university_students_list.rend(), StudentComparatorNamePriority);
    }
    return admission_table_answer;
}
