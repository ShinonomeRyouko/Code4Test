#include "combination_sum_ii.h"

#include <algorithm>

#include "gtest/gtest.h"

TEST(combination_sum_iiTest, SimpleTest) {
    combination_sum_ii* obj = new combination_sum_ii();
    vector<int> vec{10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> ans{{{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}}};
    vector<vector<int>> res = obj->combinationSum2(vec, 8);
    for (vector<int>& it : res) {
        sort(it.begin(), it.end());
    }
    sort(res.begin(), res.end());
    EXPECT_EQ(res, ans);
    delete obj;
}