#include "binary_tree_maximum_path_sum.h"

binary_tree_maximum_path_sum::binary_tree_maximum_path_sum() {
    
}

binary_tree_maximum_path_sum::~binary_tree_maximum_path_sum() {
    
}

int binary_tree_maximum_path_sum::getMax(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int left = getMax(root->left);
    int right = getMax(root->right);
    if (left < 0) {
        left = 0;
    }
    if (right < 0) {
        right = 0;
    }
    int sum = left + right + root->val;
    max_sum = max(sum, max_sum);
    return max(left, right) + root->val;
}

int binary_tree_maximum_path_sum::maxPathSum(TreeNode* root) {
    max_sum = 0;
    getMax(root);
    return max_sum;
}