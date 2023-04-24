#include <gtest/gtest.h>
#include <algorithm>
#include "list_node.h"
#include "merge_k_lists.h"


TEST(merge_k_listsTest, SimpleTest) {
    merge_k_lists* obj = new merge_k_lists();
    ListNode* list_1 = gen_list_from_vector({1,4,5});
    ListNode* list_2 = gen_list_from_vector({1,3,4});
    ListNode* list_3 = gen_list_from_vector({2,6});
    vector<ListNode*> lists = {list_1, list_2, list_3};
    ListNode* head = obj->mergeKLists(lists);
    vector<int> res;
    while (head != nullptr) {
        res.push_back(head->val);
        head = head->next;
    }
    EXPECT_TRUE(std::is_sorted(res.begin(), res.end()));
    //release_list(head);
    delete obj;
}