#include "gtest/gtest.h"
#include "edit_distance.h"


TEST(edit_distanceTest, SimpleTest) {
    edit_distance* obj = new edit_distance();
    ASSERT_EQ(obj->minDistance("horse", "ros"), 3);
    ASSERT_EQ(obj->minDistance("intention", "execution"), 5);
    delete obj;
}