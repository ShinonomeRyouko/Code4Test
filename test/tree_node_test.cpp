#include <gtest/gtest.h>
#include "wrapper.h"
#include "tree_node.h"

/*
 *      1
 *    /   \
 *   2     3
 *  / \   / \
 * 4   5 6   7
 */
TEST(tree_nodeTest, SimpleTest) {
    wrapper<TreeNode> node_pool;
    vector<int> vec{1,2,3,4,5,6,7};
    TreeNode* root = node_pool.gen_from_source(vec);

    vector<int> res_1;
    PreorderTraversal(root, res_1);
    vector<int> ans_1{1,2,4,5,3,6,7};
    EXPECT_TRUE(res_1 == ans_1);

    vector<int> res_2;
    InorderTraversal(root, res_2);
    vector<int> ans_2{4,2,5,1,6,3,7};
    EXPECT_TRUE(res_2 == ans_2);

    vector<int> res_3;
    PostorderTraversal(root, res_3);
    vector<int> ans_3{4,5,2,6,7,3,1};
    EXPECT_TRUE(res_3 == ans_3);
}