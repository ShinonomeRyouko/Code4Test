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
    static ListNode* const gen_from_source(const vector<int>& source, vector<ListNode*>& elements) {
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        ListNode* prev = nullptr;
        for (auto it : source) {
            cur = new ListNode(it);
            // track it to prevent mem leak.
            elements.push_back(cur);
            if (head == nullptr) {
                head = cur;
                prev = head;
                continue;
            }
            prev->next = cur;
            prev = cur;
        }
        return head;
    }
};

bool IsTwoListValueEQ(ListNode* l, ListNode* r);

// Assume not broken.
void ReleaseListMem(ListNode* l);

#endif