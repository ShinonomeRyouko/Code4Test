#ifndef __serialize_and_des_binary_tree_h__
#define __serialize_and_des_binary_tree_h__

#include <string>
#include <queue>
#include "tree_node.h"
using namespace std;
class serialize_and_des_binary_tree {
private:

public:
    serialize_and_des_binary_tree();
    ~serialize_and_des_binary_tree();

    // Encodes a tree to a single string.
    string serialize(TreeNode* root);

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data);
};

void split(const string& txt, queue<string>& res, char ch);

#endif