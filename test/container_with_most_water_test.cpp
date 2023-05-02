#include "container_with_most_water.h"

#include "gtest/gtest.h"

TEST(container_with_most_waterTest, SimpleTest) {
    container_with_most_water* obj = new container_with_most_water();
    vector<int> vec{1, 8, 6, 2, 5, 4, 8, 3, 7};
    EXPECT_TRUE(obj->maxArea(vec) == 49);
    delete obj;
}