#include "non_overlapping_intervals.h"

#include "gtest/gtest.h"

TEST(non_overlapping_intervalsTest, SimpleTest) {
    non_overlapping_intervals* obj = new non_overlapping_intervals();
    vector<vector<int>> intervals{{{1, 2}, {2, 3}, {3, 4}, {1, 3}}};
    EXPECT_TRUE(obj->eraseOverlapIntervals(intervals) == 1);
    delete obj;
}