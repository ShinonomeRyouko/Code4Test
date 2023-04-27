#include "tree_node.h"
#include <stack>
#include <queue>
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

void LevelorderTraversal(TreeNode* root, vector<int>& results) {
    queue<TreeNode*> pq;
    pq.emplace(root);
    while (!pq.empty()) {
        if (pq.front() == nullptr) {
            pq.pop();
            continue;
        }
        results.emplace_back(pq.front()->val);
        pq.emplace(pq.front()->left);
        pq.emplace(pq.front()->right);
        pq.pop();
    }
    return;
}

/**
 *   Function emplace do in-place constructor for object, while
 * push need to construct a temporary obj and move it(move constructor)
 * to the container and destruct the temporary obj.
 *   So use emplace as often as you can.
 **/

// Same as LevelorderTraversal but return vector each layer.
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<pair<TreeNode*, int>> pq;
    pq.emplace(root, 0);
    while (!pq.empty()) {
        if (pq.front().first == nullptr) {
            pq.pop();
            continue;
        }
        if (pq.front().second >= res.size()) {
            res.emplace_back();
        }
        res[pq.front().second].emplace_back(pq.front().first->val);
        pq.emplace(pq.front().first->left, pq.front().second + 1);
        pq.emplace(pq.front().first->right, pq.front().second + 1);
        pq.pop();
    }
    return res;
}

// binary tree right side view.
vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    stack<pair<TreeNode*, int>> stk;
    stk.emplace(root, 0);
    pair<TreeNode*, int> top_node;
    while (!stk.empty()) {
        top_node = stk.top();
        stk.pop();
        // A rightmost node in a new layer.
        if (res.size() <= top_node.second) {
            res.emplace_back(top_node.first->val);
        }
        // push left child first, so then you will visit right child first.
        if (top_node.first->left != nullptr) {
            stk.emplace(top_node.first->left, top_node.second + 1);
        }
        if (top_node.first->right != nullptr) {
            stk.emplace(top_node.first->right, top_node.second + 1);
        }
    }
    return res;
}