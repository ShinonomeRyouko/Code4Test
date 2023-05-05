#include "search_a_2d_matrix_ii.h"

#include "gtest/gtest.h"

TEST(search_a_2d_matrix_iiTest, SimpleTest) {
    search_a_2d_matrix_ii* obj = new search_a_2d_matrix_ii();
    vector<vector<int>> vec{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    EXPECT_TRUE(obj->searchMatrix(vec, 5));

    vec = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    EXPECT_FALSE(obj->searchMatrix(vec, 20));

    vec = {{-5}};
    EXPECT_TRUE(obj->searchMatrix(vec, -5));

    vec = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    EXPECT_TRUE(obj->searchMatrix(vec, 15));

    vec = {{4, 6, 9, 10, 15}, {9, 12, 13, 15, 16}};
    EXPECT_FALSE(obj->searchMatrix(vec, 14));
    delete obj;
}