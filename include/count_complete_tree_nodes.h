#ifndef __count_complete_tree_nodes_h__
#define __count_complete_tree_nodes_h__

#include <vector>

#include "tree_node.h"
using std::vector;

class count_complete_tree_nodes {
private:
    bool exists(TreeNode* root, int& level, int num);

public:
    count_complete_tree_nodes();
    ~count_complete_tree_nodes();
    int countNodes(TreeNode* root);
};

#endif