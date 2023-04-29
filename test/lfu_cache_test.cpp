#include "lfu_cache.h"

#include "gtest/gtest.h"

TEST(lfu_cacheTest, SimpleTest) {
    LFUCache* obj = new LFUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    obj->get(1);
    obj->put(3, 3);
    obj->get(2);
    obj->get(3);
    obj->put(4, 4);
    obj->get(1);
    obj->get(3);
    obj->get(4);
    delete obj;
}