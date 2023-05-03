#include "find_unsorted_subarray.h"

#include <climits>

using namespace std;

find_unsorted_subarray::find_unsorted_subarray() {}

find_unsorted_subarray::~find_unsorted_subarray() {}

int find_unsorted_subarray::findUnsortedSubarray(vector<int>& nums) {
    // [0, left] and [right, len - 1] is ordered.
    // find left pos where values before it is less than min_num,
    // find right pos where values after it is greater than max_num.
    int len = nums.size();
    int left = -1, right = -1;
    int min_num = INT_MAX;
    int max_num = INT_MIN;
    for (int i = 0; i < len; i++) {
        if (nums[i] >= max_num) {
            max_num = nums[i];
        } else {
            right = i;
        }
        if (nums[len - i - 1] <= min_num) {
            min_num = nums[len - i - 1];
        } else {
            left = len - i - 1;
        }
    }
    return (left == -1) ? 0 : right - left + 1;
}