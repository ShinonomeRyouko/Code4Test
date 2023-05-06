#include "unique_path_ii.h"

#include "gtest/gtest.h"

TEST(unique_path_iiTest, SimpleTest) {
    unique_path_ii* obj = new unique_path_ii();
    vector<vector<int>> vec{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    ASSERT_EQ(obj->uniquePathsWithObstacles(vec), 2);
    delete obj;
}