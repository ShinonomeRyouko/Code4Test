#include "gtest/gtest.h"
#include "top_k_frequent_elements.h"


TEST(top_k_frequent_elementsTest, SimpleTest) {
    top_k_frequent_elements* obj = new top_k_frequent_elements();
    vector<int> vec{3,0,1,0};
    vector<int> ans{0};
    EXPECT_TRUE(obj->topKFrequent(vec, 1) == ans);
    delete obj;
}