#include "trap_rain_water.h"

#include "gtest/gtest.h"

TEST(TrapRainWaterTest, SimpleTest) {
    Solution* obj = new Solution();
    vector<vector<int>> input = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    ASSERT_EQ(obj->trapRainWater(input), 4);
    delete obj;
}
