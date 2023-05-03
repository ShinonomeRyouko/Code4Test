#include "queue_reconstruction_by_height.h"

#include <algorithm>

using namespace std;

queue_reconstruction_by_height::queue_reconstruction_by_height() {}

queue_reconstruction_by_height::~queue_reconstruction_by_height() {}

vector<vector<int>> queue_reconstruction_by_height::reconstructQueue(vector<vector<int>>& people) {
    // sort in height descending and pos ascending order.
    sort(people.begin(), people.end(), [](const vector<int>& l, const vector<int>& r) { return (l[0] == r[0]) ? (l[1] <= r[1]) : (l[0] > r[0]); });
    vector<vector<int>> ans;
    for (const vector<int>& it : people) {
        ans.insert(ans.begin() + it[1], it);
    }
    return ans;
}