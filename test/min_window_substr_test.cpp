#include "min_window_substr.h"

#include "gtest/gtest.h"

TEST(min_window_substrTest, SimpleTest) {
    min_window_substr* obj = new min_window_substr();
    ASSERT_EQ(obj->minWindow("ADOBECODEBANC", "ABC"), "BANC");
    ASSERT_EQ(obj->minWindow("abc", "b"), "b");
    delete obj;
}