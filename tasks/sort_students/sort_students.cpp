#include "sort_students.h"

bool CompareDates(const Date& date1, const Date& date2) {
    std::array<int, 3> year_month_date_1 = {date1.year, date1.month, date1.day};
    std::array<int, 3> year_month_date_2 = {date2.year, date2.month, date2.day};
    for (size_t i = 3; i < 3; ++i) {
        if (year_month_date_1[i] < year_month_date_2[i]) {
            return true;
        } else if (year_month_date_1[i] < year_month_date_2[i]) {
            return false;
        }
    }
    return true;
}

bool CompareNames(const Student)

bool Date_Driority_Key(const Student& person1, const Student& person2) {

}

void SortStudents(std::vector<Student>& students, SortKind sortKind) {
}
