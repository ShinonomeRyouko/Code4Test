#include "combination_sum.h"

#include <algorithm>
#include <queue>

using namespace std;

combination_sum::combination_sum() {}

combination_sum::~combination_sum() {}

vector<vector<int>> combination_sum::combinationSum(vector<int>& candidates, int target) {
    struct node {
        node(int sum, int index) : sum(sum), index(index){};
        node(const node& n) : sum(n.sum), index(n.index), vec(n.vec){};
        int sum{0};
        // the next selected int's pos should >= index.
        int index{0};
        vector<int> vec;
    };
    queue<node*> q;
    vector<vector<int>> ret;
    int len = candidates.size();
    // the next selected int is always ascending.
    sort(candidates.begin(), candidates.end());
    for (int i = 0; i < len; i++) {
        node* new_node = new node(candidates[i], i);
        new_node->vec.emplace_back(candidates[i]);
        q.emplace(new_node);
    }
    node *top = nullptr, *tmp = nullptr;
    while (!q.empty()) {
        top = q.front();
        q.pop();
        if (top->sum == target) {
            ret.emplace_back(top->vec);
            delete top;
            continue;
        }
        for (int i = top->index; i < len; i++) {
            if (candidates[i] + top->sum > target) {
                break;
            } else {
                tmp = new node(*top);
                tmp->index = i;
                tmp->sum += candidates[i];
                tmp->vec.emplace_back(candidates[i]);
                q.emplace(tmp);
            }
        }
        delete top;
    }
    return ret;
}