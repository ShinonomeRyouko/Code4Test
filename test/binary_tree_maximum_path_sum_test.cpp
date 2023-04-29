#include "binary_tree_maximum_path_sum.h"

#include "gtest/gtest.h"
#include "wrapper.h"

TEST(binary_tree_maximum_path_sumTest, SimpleTest) {
    binary_tree_maximum_path_sum* obj = new binary_tree_maximum_path_sum();
    wrapper<TreeNode> node_pool;
    TreeNode* root = node_pool.gen_from_source(vector<int>{-10, 9, 20, NAINT, NAINT, 15, 7});
    ASSERT_EQ(obj->maxPathSum(root), 42);
    delete obj;
}