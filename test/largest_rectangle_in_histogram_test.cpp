#include "largest_rectangle_in_histogram.h"

#include "gtest/gtest.h"

TEST(largest_rectangle_in_histogramTest, SimpleTest) {
    largest_rectangle_in_histogram* obj = new largest_rectangle_in_histogram();
    vector<int> vec1{2, 1, 5, 6, 2, 3};
    ASSERT_EQ(obj->largestRectangleArea(vec1), 10);
    vector<int> vec2{0};
    ASSERT_EQ(obj->largestRectangleArea(vec2), 0);
    delete obj;
}