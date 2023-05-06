#ifndef __longest_common_subsequence_h__
#define __longest_common_subsequence_h__

#include <string>
#include <vector>
using std::string;
using std::vector;

class longest_common_subsequence {
private:
public:
    longest_common_subsequence();
    ~longest_common_subsequence();
    int longestCommonSubsequence(string text1, string text2);
};

#endif