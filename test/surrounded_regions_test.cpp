#include <gtest/gtest.h>
#include "surrounded_regions.h"


TEST(surrounded_regionsTest, SimpleTest) {
    surrounded_regions* obj = new surrounded_regions();
    vector<vector<char>> board;
    vector<char> v1{'X','X','X','X'};
    vector<char> v2{'X','O','O','X'};
    vector<char> v3{'X','X','O','X'};
    vector<char> v4{'X','O','X','X'};
    board.emplace_back(v1);
    board.emplace_back(v2);
    board.emplace_back(v3);
    board.emplace_back(v4);
    obj->solve(board);
    EXPECT_TRUE(board[0] == v1);
    EXPECT_TRUE(board[1] == v1);
    EXPECT_TRUE(board[2] == v1);
    EXPECT_TRUE(board[3] == v4);
    delete obj;
}