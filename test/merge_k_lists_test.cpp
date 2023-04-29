#include "merge_k_lists.h"

#include <algorithm>

#include "gtest/gtest.h"
#include "list_node.h"
#include "wrapper.h"

TEST(merge_k_listsTest, SimpleTest) {
    merge_k_lists* obj = new merge_k_lists();
    wrapper<ListNode> node_pool;
    ListNode* list_1 = node_pool.gen_from_source(vector<int>{1, 4, 5});
    ListNode* list_2 = node_pool.gen_from_source(vector<int>{1, 3, 4});
    ListNode* list_3 = node_pool.gen_from_source(vector<int>{2, 6});
    vector<ListNode*> lists = {list_1, list_2, list_3};
    ListNode* head = obj->mergeKLists(lists);
    vector<int> res;
    while (head != nullptr) {
        res.push_back(head->val);
        head = head->next;
    }
    EXPECT_TRUE(std::is_sorted(res.begin(), res.end()));
    delete obj;
}