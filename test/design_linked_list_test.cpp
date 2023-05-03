#include "design_linked_list.h"

#include "gtest/gtest.h"

TEST(design_linked_listTest, SimpleTest) {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtIndex(1, 100);
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    EXPECT_TRUE(obj->get(1) == 2);
    obj->deleteAtIndex(1);
    EXPECT_TRUE(obj->get(1) == 3);
    delete obj;
}