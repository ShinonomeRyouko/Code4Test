#include "sort_characters_by_frequency.h"

#include "gtest/gtest.h"

TEST(sort_characters_by_frequencyTest, SimpleTest) {
    sort_characters_by_frequency* obj = new sort_characters_by_frequency();
    EXPECT_TRUE(obj->frequencySort("tree") == "eert");
    EXPECT_TRUE(obj->frequencySort("bbbaaa") == "aaabbb");
    delete obj;
}