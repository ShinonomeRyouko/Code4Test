#include "top_k_frequent_elements.h"
#include <queue>
#include <unordered_map>

using namespace std;

top_k_frequent_elements::top_k_frequent_elements() {}

top_k_frequent_elements::~top_k_frequent_elements() {}

typedef pair<int, int> pii;
vector<int> top_k_frequent_elements::topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    unordered_map<int, int> cnt;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (auto n : nums) {
        if (cnt.find(n) == cnt.end()) {
            cnt.emplace(n, 1);
        } else {
            cnt[n]++;
        }
    }
    for (auto it : cnt) {
        // reverse the order, then in cnt descending order.
        pq.emplace(it.second, it.first);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    while (!pq.empty()) {
        res.emplace_back(pq.top().second);
        pq.pop();
    }
    return res;
}