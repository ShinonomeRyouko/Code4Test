#include "sliding_window_maximum.h"
#include <queue>

using namespace std;

sliding_window_maximum::sliding_window_maximum() {}

sliding_window_maximum::~sliding_window_maximum() {}

vector<int> sliding_window_maximum::maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    // first int is val, second is pos.
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++) {
        pq.push({nums[i], i});
    }
    ans.push_back(pq.top().first);
    for (int i = k; i < nums.size(); i++) {
        pq.push({nums[i], i});
        while (pq.top().second <= i - k) {
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    return ans;
}