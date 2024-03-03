#include "provinces.h"

#include <algorithm>
#include <deque>

int64_t CountPassports(const std::vector<int>& provinces) {
    if (provinces.size() == 1) {
        return provinces[0];
    }
    if (provinces.size() == 2) {
        return provinces[0] + provinces[1];
    }
    std::vector<int> sortable_provinces = {};
    for (int i : provinces) {
        sortable_provinces.push_back(i);
    }
    std::sort(sortable_provinces.begin(), sortable_provinces.end());
    std::vector<int64_t> combined_province = {};
    combined_province.push_back(sortable_provinces[0] + sortable_provinces[1]);
    int64_t answer = sortable_provinces[0] + sortable_provinces[1];
    size_t i = 2;
    size_t j = 0;
    while (i < sortable_provinces.size() || j < combined_province.size() - 1) {
        if (i == sortable_provinces.size() - 1 && j == combined_province.size() - 1) {
            answer += sortable_provinces[i] + combined_province[j];
            return answer;
        } else if (i == sortable_provinces.size() - 1 && j != combined_province.size() - 1) {
            if (sortable_provinces[i] + combined_province[j] < combined_province[j] + combined_province[j + 1]) {
                i += 1;
                j += 1;
                answer += sortable_provinces[i] + combined_province[j];
                combined_province.push_back(sortable_provinces[i] + combined_province[j]);
            } else {
                j += 2;
                answer += combined_province[j] + combined_province[j + 1];
                combined_province.push_back(combined_province[j] + combined_province[j + 1]);
            }
        } else if (i != sortable_provinces.size() - 1 && j == combined_province.size() - 1) {
            if (sortable_provinces[i] + combined_province[j] < sortable_provinces[i] + sortable_provinces[i + 1]) {
                i += 1;
                j += 1;
                answer += sortable_provinces[i] + combined_province[j];
                combined_province.push_back(sortable_provinces[i] + combined_province[j]);
            } else {
                i += 2;
                answer += sortable_provinces[i] + sortable_provinces[i + 1];
                combined_province.push_back(sortable_provinces[i] + sortable_provinces[i + 1]);
            }
        } else {
            if (sortable_provinces[i] + combined_province[j] < combined_province[j] + combined_province[j + 1] &&
                sortable_provinces[i] + combined_province[j] < sortable_provinces[i] + sortable_provinces[i + 1]) {
                i += 1;
                j += 1;
                answer += sortable_provinces[i] + combined_province[j];
                combined_province.push_back(sortable_provinces[i] + combined_province[j]);
            } else if (combined_province[j] + combined_province[j + 1] < sortable_provinces[i] + combined_province[j] &&
                       combined_province[j] + combined_province[j + 1] <
                           sortable_provinces[i] + sortable_provinces[i + 1]) {
                j += 2;
                answer += combined_province[j] + combined_province[j + 1];
                combined_province.push_back(combined_province[j] + combined_province[j + 1]);
            } else {
                i += 2;
                answer += sortable_provinces[i] + sortable_provinces[i + 1];
                combined_province.push_back(sortable_provinces[i] + sortable_provinces[i + 1]);
            }
        }
    }
    return answer;
}
