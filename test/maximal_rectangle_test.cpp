#include "gtest/gtest.h"
#include "maximal_rectangle.h"


TEST(maximal_rectangleTest, SimpleTest) {
    maximal_rectangle* obj = new maximal_rectangle();
    vector<vector<char>> vec{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    ASSERT_EQ(obj->maximalRectangle(vec), 6);
    delete obj;
}