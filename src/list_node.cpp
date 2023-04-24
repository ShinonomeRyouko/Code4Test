#include "list_node.h"

// pin the head to avoid mem leak.
ListNode* const gen_list_from_vector(const vector<int>& vec) {
    ListNode* head = nullptr;
    ListNode* cur = nullptr;
    ListNode* prev = nullptr;
    for (auto it : vec) {
        if (head == nullptr) {
            head = new ListNode(it);
            prev = head;
            continue;
        }
        cur = new ListNode(it);
        prev->next = cur;
        prev = cur;
    }
    return head;
}

void release_list(ListNode* const head) {
    ListNode *cur = head;
    ListNode *next = nullptr;
    while (cur != nullptr) {
        next = cur->next;
        delete cur;
        cur = next;
    }
}
