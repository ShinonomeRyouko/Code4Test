#include "partition_labels.h"

#include "gtest/gtest.h"

TEST(partition_labelsTest, SimpleTest) {
    partition_labels* obj = new partition_labels();
    vector<int> ans{9, 7, 8};
    EXPECT_TRUE(obj->partitionLabels("ababcbacadefegdehijhklij") == ans);
    delete obj;
}