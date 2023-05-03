#include "word_break.h"

#include "gtest/gtest.h"

TEST(word_breakTest, SimpleTest) {
    word_break* obj = new word_break();
    vector<string> vec{"leet", "code"};
    EXPECT_TRUE(obj->wordBreak("leetcode", vec));
    delete obj;
}