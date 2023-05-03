#ifndef __combination_sum_h__
#define __combination_sum_h__

#include <vector>
using std::vector;

class combination_sum {
private:
public:
    combination_sum();
    ~combination_sum();
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
};

#endif