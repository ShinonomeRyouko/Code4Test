#include "tree_node.h"
#include <stack>
void PreorderTraversal(TreeNode* root, vector<int>& results) {
    if (root == nullptr) {
        return;
    }
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* cur = nullptr;
    while (!st.empty()) {
        cur = st.top();
        st.pop();
        results.push_back(cur->val);
        // right child pushed first, leave the left on top to be processed first.
        if (cur->right != nullptr) {
            st.push(cur->right);
        }
        if (cur->left != nullptr) {
            st.push(cur->left);
        }
    }
}

void InorderTraversal(TreeNode* root, vector<int>& results) {
    stack<TreeNode*> stk;
    while (root != nullptr || !stk.empty()) {
        while (root != nullptr) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        results.push_back(root->val);
        root = root->right;
    }
}

void PostorderTraversal(TreeNode* root, vector<int>& results) {
    if (root == nullptr) {
        return;
    }
    stack<TreeNode*> stk;
    TreeNode* last_visited = nullptr;
    while (!stk.empty() || root != nullptr) {
        while (root != nullptr) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        // if right child exists, move right instead of visit current node.
        if (root->right != nullptr && last_visited != root->right) {
            root = root->right;
        } else {
            results.push_back(root->val);
            last_visited = root;
            root = nullptr;
            stk.pop();
        }
    }
}