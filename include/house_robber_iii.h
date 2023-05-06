#ifndef __house_robber_iii_h__
#define __house_robber_iii_h__

#include <vector>

#include "tree_node.h"
using std::vector;

class house_robber_iii {
private:
public:
    house_robber_iii();
    ~house_robber_iii();
    int rob(TreeNode* root);
};

#endif