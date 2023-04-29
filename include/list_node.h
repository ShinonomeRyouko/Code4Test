#ifndef __list_node_h__
#define __list_node_h__

#include <vector>
using std::vector;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    static ListNode* gen_from_source(const vector<int>& source, vector<ListNode*>& elements) {
        int start = elements.size();
        for (auto it : source) {
            // track it to prevent mem leak.
            elements.emplace_back(new ListNode(it));
        }
        int end = elements.size();
        if (start == end) {
            return nullptr;
        }
        for (int i = start; i < end - 1; i++) {
            elements[i]->next = elements[i + 1];
        }
        return elements[start];
    }
};

bool IsTwoListValueEQ(ListNode* l, ListNode* r);

// Assume not broken.
void ReleaseListMem(ListNode* l);

#endif