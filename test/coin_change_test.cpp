#include "coin_change.h"

#include "gtest/gtest.h"

TEST(coin_changeTest, SimpleTest) {
    coin_change* obj = new coin_change();
    vector<int> v{1, 2, 5};
    ASSERT_EQ(obj->coinChange(v, 11), 3);
    delete obj;
}