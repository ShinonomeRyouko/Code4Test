#include "house_robber_iii.h"

#include "gtest/gtest.h"
#include "wrapper.h"

TEST(house_robber_iiiTest, SimpleTest) {
    wrapper<TreeNode> node_pool;
    TreeNode* root = node_pool.gen_from_source(vector<int>{3, 2, 3, NAINT, 3, NAINT, 1});
    house_robber_iii* obj = new house_robber_iii();
    EXPECT_TRUE(obj->rob(root) == 7);
    delete obj;
}