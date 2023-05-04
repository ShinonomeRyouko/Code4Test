#include "combination_sum_ii.h"

#include <algorithm>

using namespace std;

combination_sum_ii::combination_sum_ii() {}

combination_sum_ii::~combination_sum_ii() {}

void combination_sum_ii::DFS(int index, int rest) {
    if (rest == 0) {
        ans.emplace_back(path);
    }
    if (index > freq.size() - 1 || freq[index].first > rest) {
        return;
    }
    // skip index in freq.
    DFS(index + 1, rest);
    // most number of freq[index] can be added.
    int most = min(rest / freq[index].first, freq[index].second);
    for (int i = 1; i <= most; i++) {
        path.emplace_back(freq[index].first);
        DFS(index + 1, rest - i * freq[index].first);
    }
    for (int i = 1; i <= most; i++) {
        path.pop_back();
    }
}

vector<vector<int>> combination_sum_ii::combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    // compress it.
    for (const int& it : candidates) {
        if (freq.empty() || freq.back().first != it) {
            freq.emplace_back(it, 1);
        } else {
            freq.back().second++;
        }
    }
    DFS(0, target);
    return ans;
}