#include "maximum_binary_tree.h"

#include <stack>

using namespace std;

maximum_binary_tree::maximum_binary_tree() {}

maximum_binary_tree::~maximum_binary_tree() {
    for (TreeNode* const it : tree) {
        delete it;
    }
}

TreeNode* maximum_binary_tree::constructMaximumBinaryTree(vector<int>& nums) {
    int n = nums.size();
    // mono stack
    vector<int> stk;
    tree.reserve(n);
    for (int i = 0; i < n; i++) {
        tree.emplace_back(new TreeNode(nums[i]));
        while (!stk.empty() && tree[stk.back()]->val < tree[i]->val) {
            tree[i]->left = tree[stk.back()];
            stk.pop_back();
        }
        if (!stk.empty()) {
            tree[stk.back()]->right = tree[i];
        }
        stk.emplace_back(i);
    }
    return tree[stk[0]];
}