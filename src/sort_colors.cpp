#include "sort_colors.h"

using namespace std;

sort_colors::sort_colors() {}

sort_colors::~sort_colors() {}

void sort_colors::sortColors(vector<int>& nums) {
    int len = nums.size();
    int ptr0 = 0, ptr1 = 0;
    for (int i = 0; i < len; i++) {
        if (nums[i] == 1) {
            swap(nums[i], nums[ptr1]);
            ptr1++;
        } else if (nums[i] == 0) {
            swap(nums[i], nums[ptr0]);
            if (ptr0 < ptr1) {
                // swapped out number 1 might be after number 2.
                swap(nums[i], nums[ptr1]);
            }
            ptr0++;
            ptr1++;
        } else {
            // let number 2 go.
        }
    }
}