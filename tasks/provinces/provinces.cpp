#include "provinces.h"

#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <queue>

int64_t CountPassports(const std::vector<int>& provinces) {
    int64_t answer = 0;
    std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> province_que = {};
    for (int kindom : provinces) {
        province_que.push(kindom);
    }
    while (province_que.size() > 1) {
        int64_t first = province_que.top();
        province_que.pop();
        int64_t second = province_que.top();
        province_que.pop();
        answer += first + second;
        province_que.push(first + second);
    }
    return answer;
}
