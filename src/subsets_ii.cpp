#include "subsets_ii.h"

#include <algorithm>

using namespace std;

subsets_ii::subsets_ii() {}

subsets_ii::~subsets_ii() {}

void subsets_ii::subsets(const vector<int>& nums, const int& start) {
    res.emplace_back(tmp);
    if (start >= nums.size()) {
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i - 1]) {
            continue;
        }
        tmp.emplace_back(nums[i]);
        subsets(nums, i + 1);
        tmp.pop_back();
    }
}

vector<vector<int>> subsets_ii::subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    subsets(nums, 0);
    return res;
}