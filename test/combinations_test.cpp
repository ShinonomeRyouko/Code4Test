#include "combinations.h"

#include <algorithm>

#include "gtest/gtest.h"

TEST(combinationsTest, SimpleTest) {
    combinations* obj = new combinations();
    vector<vector<int>> res = obj->combine(4, 2);
    vector<vector<int>> ans{{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
    for (vector<int>& it : res) {
        sort(it.begin(), it.end());
    }
    sort(res.begin(), res.end());
    ASSERT_EQ(res, ans);
    delete obj;
}