#include "sort_an_array.h"

#include <cassert>
#include <random>

using namespace std;

void quick_sort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int rand_index = rand() % (right - left + 1) + left;
    // pivot on the rightmost.
    swap(nums[rand_index], nums[right]);

    int pivot = nums[right];
    // val in [left, less) less than pivot
    // val in (more, right] more than pivot
    // val in [less, more] equal to pivot
    int less = left;
    int more = right - 1;
    for (int i = left; i <= more; i++) {
        if (nums[i] < pivot) {
            swap(nums[less], nums[i]);
            less++;
        } else if (nums[i] > pivot) {
            swap(nums[more], nums[i]);
            more--;
            // we have no idea whether nums[i] is less than pivot now.
            // check it in next round.
            i--;
        }
    }
    swap(nums[less], nums[right]);
    quick_sort(nums, left, less - 1);
    quick_sort(nums, more + 1, right);
}

void QuickSort(vector<int>& nums) {
    srand((unsigned)time(nullptr));
    quick_sort(nums, 0, nums.size() - 1);
}

void max_heapify(vector<int>& nums, int i, int len) {
    while (i * 2 + 1 <= len) {
        int large = i;
        if (i * 2 + 2 <= len && nums[i * 2 + 2] > nums[i]) {
            large = i * 2 + 2;
        }
        if (nums[i * 2 + 1] > nums[large]) {
            large = i * 2 + 1;
        }
        // Invariant condition satisfied before we reach end.
        if (large == i) {
            break;
        }
        swap(nums[large], nums[i]);
        i = large;
    }
}

void build_max_heap(vector<int>& nums, int len) {
    for (int i = len / 2; i >= 0; i--) {
        max_heapify(nums, i, len);
    }
}

void HeapSort(vector<int>& nums) {
    int len = nums.size() - 1;
    build_max_heap(nums, len);
    for (int i = len; i >= 1; i--) {
        // nums[0] is always the max.
        swap(nums[i], nums[0]);
        len--;
        max_heapify(nums, 0, len);
    }
}

void merge_sort(vector<int>& nums, vector<int>& tmp, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    merge_sort(nums, tmp, left, mid);
    merge_sort(nums, tmp, mid + 1, right);
    int cnt = 0;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            tmp[cnt++] = nums[i++];
        } else {
            tmp[cnt++] = nums[j++];
        }
    }
    while (i <= mid) {
        tmp[cnt++] = nums[i++];
    }
    while (j <= right) {
        tmp[cnt++] = nums[j++];
    }
    for (i = 0; i < right - left + 1; i++) {
        nums[i + left] = tmp[i];
    }
}

void MergeSort(vector<int>& nums) {
    vector<int> tmp(nums.size(), 0);
    merge_sort(nums, tmp, 0, nums.size() - 1);
}
