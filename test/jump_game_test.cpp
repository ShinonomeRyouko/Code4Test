#include "jump_game.h"

#include "gtest/gtest.h"

TEST(jump_gameTest, SimpleTest) {
    jump_game* obj = new jump_game();
    vector<int> vec{2, 3, 1, 1, 4};
    EXPECT_TRUE(obj->canJump(vec));
    vec = {3, 2, 1, 0, 4};
    EXPECT_FALSE(obj->canJump(vec));
    delete obj;
}