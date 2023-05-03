#include "three_sum_closest.h"

#include "gtest/gtest.h"

TEST(three_sum_closestTest, SimpleTest) {
    three_sum_closest* obj = new three_sum_closest();
    vector<int> vec{-1, 2, 1, -4};
    EXPECT_TRUE(obj->threeSumClosest(vec, 1) == 2);
    delete obj;
}