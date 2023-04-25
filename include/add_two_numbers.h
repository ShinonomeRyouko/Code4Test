#ifndef __add_two_numbers_h__
#define __add_two_numbers_h__

#include "list_node.h"
using namespace std;
class add_two_numbers {
private:

public:
    add_two_numbers();
    ~add_two_numbers();

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

#endif