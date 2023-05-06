#include "longest_common_subsequence.h"

#include "gtest/gtest.h"

TEST(longest_common_subsequenceTest, SimpleTest) {
    longest_common_subsequence* obj = new longest_common_subsequence();
    ASSERT_EQ(obj->longestCommonSubsequence("abcde", "ace"), 3);
    ASSERT_EQ(obj->longestCommonSubsequence("abc", "abc"), 3);
    ASSERT_EQ(obj->longestCommonSubsequence("abc", "def"), 0);
    delete obj;
}