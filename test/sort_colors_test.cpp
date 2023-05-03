#include "sort_colors.h"

#include <algorithm>

#include "gtest/gtest.h"

TEST(sort_colorsTest, SimpleTest) {
    sort_colors* obj = new sort_colors();
    vector<int> vec{2, 0, 2, 1, 1, 0};
    obj->sortColors(vec);
    EXPECT_TRUE(is_sorted(vec.begin(), vec.end()));
    delete obj;
}