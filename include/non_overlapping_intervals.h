#ifndef __non_overlapping_intervals_h__
#define __non_overlapping_intervals_h__

#include <vector>
using std::vector;

class non_overlapping_intervals {
private:
public:
    non_overlapping_intervals();
    ~non_overlapping_intervals();
    int eraseOverlapIntervals(vector<vector<int>>& intervals);
};

#endif