#include "wiggle_subsequence.h"

using namespace std;

wiggle_subsequence::wiggle_subsequence() {}

wiggle_subsequence::~wiggle_subsequence() {}

int wiggle_subsequence::wiggleMaxLength(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) {
        return len;
    }
    int diff = nums[1] - nums[0];
    int ret = (diff == 0) ? 1 : 2;
    // ascending or descending to the highest or lowest.
    for (int i = 2; i < len; i++) {
        if (diff == 0 && nums[i] - nums[i - 1] != 0) {
            ret++;
            diff = nums[i] - nums[i - 1];
            continue;
        }
        if ((nums[i] - nums[i - 1]) * diff < 0) {
            diff = nums[i] - nums[i - 1];
            ret++;
        }
    }
    return ret;
}