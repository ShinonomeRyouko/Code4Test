#ifndef __sliding_window_maximum_h__
#define __sliding_window_maximum_h__

#include <vector>
using namespace std;
class sliding_window_maximum {
private:
public:
    sliding_window_maximum();
    ~sliding_window_maximum();

    vector<int> maxSlidingWindow(vector<int>& nums, int k);
};

#endif