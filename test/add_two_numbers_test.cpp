#include "gtest/gtest.h"
#include "add_two_numbers.h"
#include "wrapper.h"


TEST(add_two_numbersTest, SimpleTest) {
    add_two_numbers* obj = new add_two_numbers();
    wrapper<ListNode> node_pool;
    ListNode *l1 = node_pool.gen_from_source(vector<int>{2,4,3});
    ListNode *l2 = node_pool.gen_from_source(vector<int>{5,6,4});
    ListNode *l3 = node_pool.gen_from_source(vector<int>{7,0,8});
    ListNode* l4 = obj->addTwoNumbers(l1, l2);
    EXPECT_TRUE(IsTwoListValueEQ(l4, l3));
    ReleaseListMem(l4);
    delete obj;
}