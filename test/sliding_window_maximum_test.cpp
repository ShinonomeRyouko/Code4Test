#include <gtest/gtest.h>
#include "sliding_window_maximum.h"


TEST(sliding_window_maximumTest, SimpleTest) {
    sliding_window_maximum* obj = new sliding_window_maximum();
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    vector<int> ans{3,3,5,5,6,7};
    EXPECT_TRUE(obj->maxSlidingWindow(nums, 3) == ans);
    vector<int> nums_1{1,-1};
    vector<int> ans_1{1,-1};
    EXPECT_TRUE(obj->maxSlidingWindow(nums_1, 1) == ans_1);
    delete obj;
}