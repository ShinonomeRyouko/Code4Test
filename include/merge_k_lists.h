#ifndef __merge_k_lists_h__
#define __merge_k_lists_h__

#include "list_node.h"
using namespace std;

class merge_k_lists {
private:
public:
    merge_k_lists();
    ListNode* mergeKLists(vector<ListNode*>& lists);
    ~merge_k_lists();
};

#endif