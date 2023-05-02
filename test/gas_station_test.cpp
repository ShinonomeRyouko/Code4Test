#include "gas_station.h"

#include "gtest/gtest.h"

TEST(gas_stationTest, SimpleTest) {
    gas_station* obj = new gas_station();
    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};
    EXPECT_TRUE(obj->canCompleteCircuit(gas, cost) == 3);
    delete obj;
}