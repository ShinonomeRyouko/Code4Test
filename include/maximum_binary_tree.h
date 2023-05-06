#ifndef __maximum_binary_tree_h__
#define __maximum_binary_tree_h__

#include <vector>

#include "tree_node.h"
using std::vector;

class maximum_binary_tree {
private:
    vector<TreeNode*> tree;

public:
    maximum_binary_tree();
    ~maximum_binary_tree();
    TreeNode* constructMaximumBinaryTree(vector<int>& nums);
};

#endif