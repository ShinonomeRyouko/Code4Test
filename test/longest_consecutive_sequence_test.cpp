#include "longest_consecutive_sequence.h"

#include "gtest/gtest.h"

TEST(longest_consecutive_sequenceTest, SimpleTest) {
    longest_consecutive_sequence* obj = new longest_consecutive_sequence();
    vector<int> nums{100, 4, 200, 1, 3, 2};
    ASSERT_EQ(obj->longestConsecutive(nums), 4);
    delete obj;
}