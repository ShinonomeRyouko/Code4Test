#include "largest_number.h"

#include "gtest/gtest.h"

TEST(largest_numberTest, SimpleTest) {
    largest_number* obj = new largest_number();
    vector<int> vec{10, 2};
    EXPECT_TRUE(obj->largestNumber(vec) == "210");
    vec = {3, 30, 34, 5, 9};
    EXPECT_TRUE(obj->largestNumber(vec) == "9534330");
    vec = {0, 0};
    EXPECT_TRUE(obj->largestNumber(vec) == "0");
    delete obj;
}