#ifndef __word_break_h__
#define __word_break_h__

#include <string>
#include <vector>
using std::string;
using std::vector;

class word_break {
private:
public:
    word_break();
    ~word_break();
    bool wordBreak(string s, vector<string>& wordDict);
};

#endif