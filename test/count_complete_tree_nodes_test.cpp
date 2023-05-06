#include "count_complete_tree_nodes.h"

#include "gtest/gtest.h"
#include "wrapper.h"

TEST(count_complete_tree_nodesTest, SimpleTest) {
    wrapper<TreeNode> node_pool;
    TreeNode* root = node_pool.gen_from_source(vector<int>{1, 2, 3, 4, 5, 6, NAINT});
    count_complete_tree_nodes* obj = new count_complete_tree_nodes();
    EXPECT_TRUE(obj->countNodes(root) == 6);
    EXPECT_TRUE(obj->countNodes(nullptr) == 0);
    delete obj;
}