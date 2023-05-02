#include "product_of_array_except_self.h"

#include "gtest/gtest.h"

TEST(product_of_array_except_selfTest, SimpleTest) {
    product_of_array_except_self* obj = new product_of_array_except_self();
    vector<int> vec{1, 2, 3, 4};
    vector<int> ans{24, 12, 8, 6};
    EXPECT_TRUE(obj->productExceptSelf(vec) == ans);
    delete obj;
}