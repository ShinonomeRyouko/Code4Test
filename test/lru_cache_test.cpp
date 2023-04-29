#include "lru_cache.h"

#include "gtest/gtest.h"

TEST(LRUCacheTest, SimpleTest) {
    LRUCache* obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    ASSERT_EQ(obj->get(1), 1);
    obj->put(3, 3);
    ASSERT_EQ(obj->get(2), -1);
    obj->put(4, 4);
    ASSERT_EQ(obj->get(1), -1);
    ASSERT_EQ(obj->get(3), 3);
    ASSERT_EQ(obj->get(4), 4);
    delete obj;
}
