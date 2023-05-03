#ifndef __wiggle_subsequence_h__
#define __wiggle_subsequence_h__

#include <vector>
using std::vector;

class wiggle_subsequence {
private:
public:
    wiggle_subsequence();
    ~wiggle_subsequence();
    int wiggleMaxLength(vector<int>& nums);
};

#endif