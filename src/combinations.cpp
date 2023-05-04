#include "combinations.h"

using namespace std;

combinations::combinations() {}

combinations::~combinations() {}

void sub_combine(vector<vector<int>>& ans, int n, int k, vector<int> cur) {
    if (k == 0) {
        ans.emplace_back(cur);
        return;
    }
    if (k == n) {
        for (int i = 1; i <= n; i++) {
            cur.emplace_back(i);
        }
        ans.emplace_back(cur);
    } else if (k < n) {
        sub_combine(ans, n - 1, k, cur);
        cur.emplace_back(n);
        sub_combine(ans, n - 1, k - 1, cur);
    }
}

vector<vector<int>> combinations::combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> vec;
    sub_combine(ans, n, k, vec);
    return ans;
}