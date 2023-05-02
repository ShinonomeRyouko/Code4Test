#include "subarray_sum_equals_k.h"

#include <unordered_map>

using namespace std;

subarray_sum_equals_k::subarray_sum_equals_k() {}

subarray_sum_equals_k::~subarray_sum_equals_k() {}

int subarray_sum_equals_k::subarraySum(vector<int>& nums, int k) {
    // record how many times sum of prefix i(0 <= i < len) appears.
    unordered_map<int, int> u_map;
    int cnt = 0;
    int prefix = 0;
    // 0 appears once.
    u_map[prefix] = 1;
    for (const int& num : nums) {
        prefix += num;
        if (u_map.find(prefix - k) != u_map.end()) {
            // the prefix whose sum equal to prefix - k counts u_map[prefix - k] times.
            cnt += u_map[prefix - k];
        }
        // record it.
        u_map[prefix]++;
    }
    return cnt;
}