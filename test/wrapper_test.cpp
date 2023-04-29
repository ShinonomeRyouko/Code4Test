#include "wrapper.h"

#include "gtest/gtest.h"
#include "list_node.h"

TEST(wrapperTest, SimpleTest) {
    wrapper<ListNode> test_obj;
    vector<int> vec{1, 2, 3};
    ListNode* head = test_obj.gen_from_source(vec);
    EXPECT_TRUE(head != nullptr);
}