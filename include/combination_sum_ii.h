#ifndef __combination_sum_ii_h__
#define __combination_sum_ii_h__

#include <vector>
using std::pair;
using std::vector;

class combination_sum_ii {
private:
    vector<vector<int>> ans;
    vector<int> path;
    vector<pair<int, int>> freq;
    void DFS(int index, int rest);

public:
    combination_sum_ii();
    ~combination_sum_ii();
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
};

#endif