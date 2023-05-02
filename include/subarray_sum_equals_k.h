#ifndef __subarray_sum_equals_k_h__
#define __subarray_sum_equals_k_h__

#include <vector>
using std::vector;

class subarray_sum_equals_k {
private:
public:
    subarray_sum_equals_k();
    ~subarray_sum_equals_k();
    int subarraySum(vector<int>& nums, int k);
};

#endif