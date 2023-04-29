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
