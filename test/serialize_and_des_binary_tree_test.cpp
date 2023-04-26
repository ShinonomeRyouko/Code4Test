#include <gtest/gtest.h>
#include "serialize_and_des_binary_tree.h"
#include "wrapper.h"

TEST(serialize_and_des_binary_treeTest, SimpleTest) {
    void split(const string& txt, queue<string>& res, char ch);
    string to_split = "1,2,x,x,3,4,x,x,5,x,x";
    vector<string> true_res{"1", "2", "x", "x", "3", "4", "x", "x", "5", "x", "x"};
    queue<string> result;
    split(to_split, result, ',');
    EXPECT_TRUE(result.size() == true_res.size());
    for (auto str : true_res) {
        EXPECT_TRUE(result.front() == str);
        result.pop();
    }

    wrapper<TreeNode> node_pool;
    TreeNode* root = node_pool.gen_from_source(vector<int>{1,2,3,NAINT,NAINT,4,5});
    serialize_and_des_binary_tree* obj = new serialize_and_des_binary_tree();
    string serialzied_str = "1,2,x,x,3,4,x,x,5,x,x";
    ASSERT_EQ(obj->serialize(root), serialzied_str);
    TreeNode* deserialized_tree = obj->deserialize(serialzied_str);

    vector<int> res;
    PreorderTraversal(deserialized_tree, res);
    vector<int> ans{1,2,3,4,5};
    EXPECT_TRUE(res == ans);

    delete obj;
}