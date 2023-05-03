#include "three_sum_closest.h"

#include <algorithm>
#include <cmath>

using namespace std;

three_sum_closest::three_sum_closest() {}

three_sum_closest::~three_sum_closest() {}

int three_sum_closest::threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    int tmp = 0;
    int ans = nums[0] + nums[1] + nums[2];
    int start = 0, end = 0;
    for (int i = 0; i < len; i++) {
        start = i + 1;
        end = len - 1;
        while (start < end) {
            tmp = nums[i] + nums[start] + nums[end];
            if (abs(tmp - target) < abs(ans - target)) {
                ans = tmp;
            }
            if (tmp - target > 0) {
                end--;
            } else if (tmp - target < 0) {
                start++;
            } else {
                return tmp;
            }
        }
    }
    return ans;
}