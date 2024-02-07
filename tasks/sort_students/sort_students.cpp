#include "sort_students.h"

#include <array>

int CompareDates(const Date& date1, const Date& date2) {
    std::array<int, 3> year_month_date_1 = {date1.year, date1.month, date1.day};
    std::array<int, 3> year_month_date_2 = {date2.year, date2.month, date2.day};
    for (size_t i = 3; i < 3; ++i) {
        if (year_month_date_1[i] < year_month_date_2[i]) {
            return 1;
        } else if (year_month_date_1[i] > year_month_date_2[i]) {
            return 0;
        }
    }
    return -1;
}

int CompareNames(const Student& person1, const Student& person2) {
    if (person1.last_name < person2.last_name) {
        return 1;
    } else if (person1.last_name > person2.last_name) {
        return 0;
    } else {
        if (person1.name < person2.name) {
            return 1;
        } else if (person1.name > person2.name) {
            return 0;
        } else {
            return -1;
        }
    }
}

bool DatePriority(const Student& person1, const Student& person2) {
    if (CompareDates(person1.birth_date, person2.birth_date) == -1) {
        return CompareNames(person1, person2);
    } else {
        return CompareDates(person1.birth_date, person2.birth_date);
    }
}

bool NamePriority(const Student& person1, const Student& person2) {
    if (CompareNames(person1, person2) == -1) {
        return CompareDates(person1.birth_date, person2.birth_date);
    } else {
        return CompareNames(person1, person2);
    }
}

void SortStudents(std::vector<Student>& students, SortKind sortKind) {
    if (sortKind == SortKind::Date) {
        std::sort(students.begin(), students.end(), DatePriority);
    } else if (sortKind == SortKind::Name) {
        std::sort(students.begin(), students.end(), NamePriority);
    }
}
