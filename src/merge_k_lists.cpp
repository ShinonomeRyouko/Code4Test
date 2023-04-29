#include "merge_k_lists.h"

#include <queue>

using namespace std;

merge_k_lists::merge_k_lists() {}

merge_k_lists::~merge_k_lists() {}

ListNode* merge_k_lists::mergeKLists(vector<ListNode*>& lists) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode* tmp = nullptr;
    auto cmp = [](ListNode* l, ListNode* r) { return l->val > r->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    for (auto list : lists) {
        if (list != nullptr) {
            pq.push(list);
        }
    }
    while (!pq.empty()) {
        tmp = pq.top();
        pq.pop();
        if (tmp->next != nullptr) {
            pq.push(tmp->next);
        }
        if (head == nullptr) {
            head = tmp;
            tail = tmp;
            continue;
        }
        tail->next = tmp;
        tail = tmp;
    }
    return head;
}