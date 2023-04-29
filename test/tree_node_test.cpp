#include "tree_node.h"

#include "gtest/gtest.h"
#include "wrapper.h"

inline void CheckTraversal(TreeNode* root, vector<int> ans, void (*TraversalFunc)(TreeNode* root, vector<int>& results)) {
    vector<int> res;
    TraversalFunc(root, res);
    EXPECT_TRUE(res == ans);
}

/*
 *      1
 *    /   \
 *   2     3
 *  / \   / \
 * 4   5 6   7
 */
TEST(tree_nodeTest, SimpleTest) {
    wrapper<TreeNode> node_pool;
    vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = node_pool.gen_from_source(vec);

    CheckTraversal(root, {1, 2, 4, 5, 3, 6, 7}, PreorderTraversal);

    CheckTraversal(root, {4, 2, 5, 1, 6, 3, 7}, InorderTraversal);

    CheckTraversal(root, {4, 5, 2, 6, 7, 3, 1}, PostorderTraversal);

    CheckTraversal(root, {1, 2, 3, 4, 5, 6, 7}, LevelorderTraversal);

    vector<vector<int>> res = move(levelOrder(root));
    vector<vector<int>> ans{{1},{2,3},{4,5,6,7}};
    EXPECT_TRUE(res == ans);

    vector<int> res1 = rightSideView(root);
    vector<int> ans1 = {1,3,7};
    EXPECT_TRUE(res == ans);
}

/*
 *      1
 *    /   \
 *   2     3
 *   \     /
 *    4   5
 *         \
 *          6
 */
TEST(tree_nodeTest, NullNodeTest) {
    wrapper<TreeNode> node_pool;
    vector<int> vec{1, 2, 3, NAINT, 4, 5, NAINT, NAINT, NAINT, NAINT, NAINT, NAINT, 6};
    TreeNode* root = node_pool.gen_from_source(vec);

    CheckTraversal(root, {1, 2, 4, 3, 5, 6}, PreorderTraversal);

    CheckTraversal(root, {2, 4, 1, 5, 6, 3}, InorderTraversal);

    CheckTraversal(root, {4, 2, 6, 5, 3, 1}, PostorderTraversal);

    CheckTraversal(root, {1, 2, 3, 4, 5, 6}, LevelorderTraversal);

    vector<vector<int>> res = move(levelOrder(root));
    vector<vector<int>> ans{{1},{2,3},{4,5},{6}};
    EXPECT_TRUE(res == ans);

    vector<int> res1 = rightSideView(root);
    vector<int> ans1 = {1,3,5,6};
    EXPECT_TRUE(res == ans);
}