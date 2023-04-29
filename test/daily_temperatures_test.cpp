#include "gtest/gtest.h"
#include "daily_temperatures.h"


TEST(daily_temperaturesTest, SimpleTest) {
    daily_temperatures* obj = new daily_temperatures();
    vector<int> vec{73,74,75,71,69,72,76,73};
    vector<int> res = obj->dailyTemperatures(vec);
    vector<int> ans{1,1,4,2,1,1,0,0};
    EXPECT_TRUE(res == ans);
    delete obj;
}