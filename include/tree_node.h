#ifndef __tree_node_h__
#define __tree_node_h__

#include <climits>
#include <vector>
using std::vector;
// Not A INT.
#define NAINT INT_MIN
#define INVALID_INT(a) (a == NAINT)
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    // build a binary tree in layer order.
    static TreeNode* gen_from_source(const vector<int>& source, vector<TreeNode*>& elements) {
        int start = elements.size();
        for (auto it : source) {
            // track it to prevent mem leak.
            if (INVALID_INT(it)) {
                elements.push_back(nullptr);
            } else {
                elements.emplace_back(new TreeNode(it));
            }
        }
        int end = elements.size();
        if (start == end) {
            return nullptr;
        }
        for (int i = start; 2 * (i - start) + 2 + start < end; i++) {
            if (elements[i] == nullptr) {
                continue;
            }
            elements[i]->left = elements[2 * (i - start) + 1 + start];
            elements[i]->right = elements[2 * (i - start) + 2 + start];
        }
        return elements[start];
    }
};

void PreorderTraversal(TreeNode* root, vector<int>& results);

void InorderTraversal(TreeNode* root, vector<int>& results);

void PostorderTraversal(TreeNode* root, vector<int>& results);

void LevelorderTraversal(TreeNode* root, vector<int>& results);

vector<vector<int>> levelOrder(TreeNode* root);

vector<int> rightSideView(TreeNode* root);

#endif