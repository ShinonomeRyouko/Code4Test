#ifndef __find_unsorted_subarray_h__
#define __find_unsorted_subarray_h__

#include <vector>
using std::vector;

class find_unsorted_subarray {
private:
public:
    find_unsorted_subarray();
    ~find_unsorted_subarray();
    int findUnsortedSubarray(vector<int>& nums);
};

#endif