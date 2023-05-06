#include "house_robber_iii.h"

using namespace std;

house_robber_iii::house_robber_iii() {}

house_robber_iii::~house_robber_iii() {}

struct SubTreeStatus {
    int selected;
    int not_selected;
};

SubTreeStatus dfs(TreeNode* root) {
    if (root == nullptr) {
        return {0, 0};
    }
    SubTreeStatus left = dfs(root->left);
    SubTreeStatus right = dfs(root->right);
    SubTreeStatus s;
    s.selected = root->val + left.not_selected + right.not_selected;
    s.not_selected = max(left.selected, left.not_selected) + max(right.selected, right.not_selected);
    return s;
}

int house_robber_iii::rob(TreeNode* root) {
    SubTreeStatus s = dfs(root);
    return max(s.selected, s.not_selected);
}