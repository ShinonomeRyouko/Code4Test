#include "maximum_binary_tree.h"

#include "gtest/gtest.h"

TEST(maximum_binary_treeTest, SimpleTest) {
    maximum_binary_tree* obj = new maximum_binary_tree();
    vector<int> vec{3, 2, 1, 6, 0, 5};
    TreeNode* tree = obj->constructMaximumBinaryTree(vec);
    vector<int> res;
    InorderTraversal(tree, res);
    vector<int> ans{3, 2, 1, 6, 0, 5};
    ASSERT_EQ(res, ans);
    delete obj;
}