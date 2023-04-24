#include <gtest/gtest.h>
#include "list_node.h"


TEST(list_nodeTest, SimpleTest) {
    vector<int> vec{4,1,2,3};
    ListNode* head = gen_list_from_vector(vec);
    ListNode* cur = head;
    for (auto it : vec) {
        ASSERT_NE(cur, nullptr);
        ASSERT_EQ(it, cur->val);
        cur = cur->next;
    }
    EXPECT_TRUE(cur == nullptr);
    release_list(head);
}