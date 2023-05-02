#include "jump_game_ii.h"

#include "gtest/gtest.h"

TEST(jump_game_iiTest, SimpleTest) {
    jump_game_ii* obj = new jump_game_ii();
    vector<int> vec{2, 3, 1, 1, 4};
    ASSERT_EQ(obj->jump(vec), 2);
    delete obj;
}