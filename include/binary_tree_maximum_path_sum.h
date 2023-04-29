#ifndef __binary_tree_maximum_path_sum_h__
#define __binary_tree_maximum_path_sum_h__

#include "tree_node.h"
class binary_tree_maximum_path_sum {
private:
    int max_sum;
    int getMax(TreeNode* root);

public:
    binary_tree_maximum_path_sum();
    ~binary_tree_maximum_path_sum();
    int maxPathSum(TreeNode* root);
};

#endif