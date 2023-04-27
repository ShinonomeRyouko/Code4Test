#include "serialize_and_des_binary_tree.h"
#include <sstream>
serialize_and_des_binary_tree::serialize_and_des_binary_tree() {
    
}

serialize_and_des_binary_tree::~serialize_and_des_binary_tree() {
    for (auto it : gc) {
        delete it;
    }
}

// Encodes a tree to a single string.
string serialize_and_des_binary_tree::serialize(TreeNode* root) {
    if (root == nullptr) {
        return "x";
    }
    string left = serialize(root->left);
    string right = serialize(root->right);
    return to_string(root->val) + "," + left + "," + right;
}

void split(const string& txt, queue<string>& res, char ch) {
    if (txt.empty()) {
        return;
    }
    stringstream ss(txt);
    while (ss.good()) {
        string substr;
        getline(ss, substr, ch);
        res.push(substr);
    }
}

TreeNode* serialize_and_des_binary_tree::build(queue<string>& str_list) {
    string str = str_list.front();
    str_list.pop();
    if (str == "x") {
        return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(str));
    gc.emplace_back(root);
    root->left = build(str_list);
    root->right = build(str_list);
    return root;
}

// Decodes your encoded data to tree.
TreeNode* serialize_and_des_binary_tree::deserialize(string data) {
    queue<string> string_list;
    split(data, string_list, ',');
    return build(string_list);
}