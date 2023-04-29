#include "lfu_cache.h"

#include "gtest/gtest.h"

TEST(lfu_cacheTest, SimpleTest) {
    LFUCache* obj = new LFUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    ASSERT_EQ(obj->get(1), 1);
    obj->put(3, 3);
    ASSERT_EQ(obj->get(2), -1);
    ASSERT_EQ(obj->get(3), 3);
    obj->put(4, 4);
    ASSERT_EQ(obj->get(1), -1);
    ASSERT_EQ(obj->get(3), 3);
    ASSERT_EQ(obj->get(4), 4);
    obj->put(3, 30);
    obj->put(4, 40);
    obj->put(4, 80);
    delete obj;
}