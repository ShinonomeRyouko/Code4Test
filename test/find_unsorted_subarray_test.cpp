#include "find_unsorted_subarray.h"

#include "gtest/gtest.h"

TEST(find_unsorted_subarrayTest, SimpleTest) {
    find_unsorted_subarray* obj = new find_unsorted_subarray();
    vector<int> vec{2, 6, 4, 8, 10, 9, 15};
    EXPECT_TRUE(obj->findUnsortedSubarray(vec) == 5);
    delete obj;
}