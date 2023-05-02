#include "subarray_sum_equals_k.h"

#include "gtest/gtest.h"

TEST(subarray_sum_equals_kTest, SimpleTest) {
    subarray_sum_equals_k* obj = new subarray_sum_equals_k();
    vector<int> vec{1, 2, 3};
    EXPECT_TRUE(obj->subarraySum(vec, 3) == 2);
    vec = {1, 1, 1};
    EXPECT_TRUE(obj->subarraySum(vec, 2) == 2);
    delete obj;
}