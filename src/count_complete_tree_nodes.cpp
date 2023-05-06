#include "count_complete_tree_nodes.h"

using namespace std;

count_complete_tree_nodes::count_complete_tree_nodes() {}

count_complete_tree_nodes::~count_complete_tree_nodes() {}

bool count_complete_tree_nodes::exists(TreeNode* root, int& level, int num) {
    int bits = 1 << (level - 1);
    TreeNode* tmp = root;
    while (tmp != nullptr && bits > 0) {
        if (!(bits & num)) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
        bits >>= 1;
    }
    return tmp != nullptr;
}

int count_complete_tree_nodes::countNodes(TreeNode* root) {
    int level = 0;
    TreeNode* tmp = root;
    if (root == nullptr) {
        return 0;
    }
    // the most left node in the deepest level.
    while (tmp->left != nullptr) {
        tmp = tmp->left;
        level++;
    }
    int low = 1 << level, high = (1 << (level + 1)) - 1, mid = 0;
    // binary search to check last node in the deepest level.
    while (low < high) {
        mid = (high - low + 1) / 2 + low;
        if (exists(root, level, mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}