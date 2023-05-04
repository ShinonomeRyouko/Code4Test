#ifndef __combinations_h__
#define __combinations_h__

#include <vector>
using std::vector;

class combinations {
private:
public:
    combinations();
    ~combinations();
    vector<vector<int>> combine(int n, int k);
};

#endif