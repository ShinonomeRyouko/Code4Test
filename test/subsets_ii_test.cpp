#include "subsets_ii.h"

#include <algorithm>

#include "gtest/gtest.h"

TEST(subsets_iiTest, SimpleTest) {
    subsets_ii* obj = new subsets_ii();
    vector<int> vec{1, 2, 2};
    vector<vector<int>> ans{{}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}};
    vector<vector<int>> res = obj->subsetsWithDup(vec);
    sort(res.begin(), res.end());
    ASSERT_EQ(ans, res);
    delete obj;
}