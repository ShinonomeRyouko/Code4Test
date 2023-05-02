#include "non_overlapping_intervals.h"

#include <algorithm>

using namespace std;

non_overlapping_intervals::non_overlapping_intervals() {}

non_overlapping_intervals::~non_overlapping_intervals() {}

int non_overlapping_intervals::eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // sort intervals by their ending in ascending order.
    sort(intervals.begin(), intervals.end(), [](const vector<int>& l, const vector<int>& r) { return l[1] < r[1]; });
    int num = 1;
    int right = intervals[0][1];
    for (const vector<int>& it : intervals) {
        // if no overlapping, add it.
        if (it[0] >= right) {
            right = it[1];
            num++;
        }
    }
    // return the number of intervals should be moved.
    return intervals.size() - num;
}