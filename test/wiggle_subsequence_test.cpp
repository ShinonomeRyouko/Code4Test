#include "wiggle_subsequence.h"

#include "gtest/gtest.h"

TEST(wiggle_subsequenceTest, SimpleTest) {
    wiggle_subsequence* obj = new wiggle_subsequence();
    vector<int> nums{1, 7, 4, 9, 2, 5};
    EXPECT_TRUE(obj->wiggleMaxLength(nums) == 6);
    nums = {0};
    EXPECT_TRUE(obj->wiggleMaxLength(nums) == 1);
    nums = {0, 0, 1};
    EXPECT_TRUE(obj->wiggleMaxLength(nums) == 2);
    delete obj;
}