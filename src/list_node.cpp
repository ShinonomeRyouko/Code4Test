#include "list_node.h"

bool IsTwoListValueEQ(ListNode* l, ListNode* r) {
    while (l != nullptr && r != nullptr) {
        if (l->val != r->val) {
            return false;
        }
        l = l->next;
        r = r->next;
    }
    return l == nullptr && r == nullptr;
}

void ReleaseListMem(ListNode* l) {
    ListNode* next = nullptr;
    while (l != nullptr) {
        next = l->next;
        delete l;
        l = next;
    }
}