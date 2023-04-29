#include "list_node.h"

#include "gtest/gtest.h"
#include "wrapper.h"

TEST(list_nodeTest, SimpleTest) {
    vector<int> vec{4, 1, 2, 3, 7, 6, 0};
    wrapper<ListNode> node_pool;
    ListNode* head = node_pool.gen_from_source(vec);
    ListNode* cur = head;
    for (auto it : vec) {
        ASSERT_NE(cur, nullptr);
        ASSERT_EQ(it, cur->val);
        cur = cur->next;
    }
    EXPECT_TRUE(cur == nullptr);
}