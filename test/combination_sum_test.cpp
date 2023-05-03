#include "combination_sum.h"

#include <algorithm>

#include "gtest/gtest.h"

TEST(combination_sumTest, SimpleTest) {
    combination_sum* obj = new combination_sum();
    vector<int> vec{2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans{{{2, 2, 3}, {7}}};
    vector<vector<int>> res = obj->combinationSum(vec, target);
    sort(ans.begin(), ans.end());
    sort(res.begin(), res.end());
    EXPECT_TRUE(res == ans);
    delete obj;
}