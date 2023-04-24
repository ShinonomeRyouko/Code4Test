#ifndef __list_node_h__
#define __list_node_h__

#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* const gen_list_from_vector(const vector<int>& vec);
void release_list(ListNode* const head);
#endif