#include "add_two_numbers.h"

add_two_numbers::add_two_numbers() {}

add_two_numbers::~add_two_numbers() {}

ListNode* add_two_numbers::addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum = 0;
    int bubble = 0;
    int transfered = 0;
    ListNode* head = nullptr;
    ListNode* prev = nullptr;
    ListNode* cur = nullptr;
    while (l1 != nullptr || l2 != nullptr || bubble != 0) {
        sum = 0;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += bubble;
        bubble = sum / 10;
        sum %= 10;
        cur = new ListNode(sum);
        if (head == nullptr) {
            head = cur;
            prev = cur;
        } else {
            prev->next = cur;
            prev = cur;
        }
    }
    return head;
}