#include "sort_an_array.h"

#include <algorithm>
#include <random>

#include "gtest/gtest.h"

TEST(sort_an_arrayTest, SimpleTest) {
    vector<int> arr{9, 8, 7, 7, 7, 6, 5, 5};
    QuickSort(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));

    // if too many equal val.
    vector<int> conner_case{2, 2, 2, 2, 2, 2, 2, 2, 2};
    QuickSort(arr);

    arr = {9, 8, 7, 7, 7, 6, 5, 5};
    HeapSort(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));

    arr = {9, 8, 7, 7, 7, 6, 5, 5};
    MergeSort(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}
