#ifndef __subsets_ii_h__
#define __subsets_ii_h__

#include <vector>
using std::vector;

class subsets_ii {
private:
    vector<int> tmp;
    vector<vector<int>> res;
    void subsets(const vector<int>& nums, const int& start);

public:
    subsets_ii();
    ~subsets_ii();
    vector<vector<int>> subsetsWithDup(vector<int>& nums);
};

#endif