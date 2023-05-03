#include "queue_reconstruction_by_height.h"

#include "gtest/gtest.h"

TEST(queue_reconstruction_by_heightTest, SimpleTest) {
    queue_reconstruction_by_height* obj = new queue_reconstruction_by_height();
    vector<vector<int>> vec{{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}}};
    vector<vector<int>> ans{{{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}}};
    EXPECT_TRUE(obj->reconstructQueue(vec) == ans);
    delete obj;
}