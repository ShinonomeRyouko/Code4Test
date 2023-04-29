#include "gtest/gtest.h"
#include "longest_substr_no_repeat_char.h"


TEST(longest_substr_no_repeat_charTest, SimpleTest) {
    longest_substr_no_repeat_char* obj = new longest_substr_no_repeat_char();
    ASSERT_EQ(obj->lengthOfLongestSubstring("abcabcbb"), 3);
    ASSERT_EQ(obj->lengthOfLongestSubstring("bbbbb"), 1);
    ASSERT_EQ(obj->lengthOfLongestSubstring("pwwkew"), 3);
    delete obj;
}