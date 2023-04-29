#include "longest_valid_parentheses.h"

#include "gtest/gtest.h"

TEST(longest_valid_parenthesesTest, SimpleTest) {
    longest_valid_parentheses* obj = new longest_valid_parentheses();
    ASSERT_EQ(obj->longestValidParentheses(")()())"), 4);
    ASSERT_EQ(obj->longestValidParentheses("(()"), 2);
    ASSERT_EQ(obj->longestValidParentheses(""), 0);
    delete obj;
}