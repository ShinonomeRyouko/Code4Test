#include "word_break.h"

#include <unordered_set>

using namespace std;

word_break::word_break() {}

word_break::~word_break() {}

bool word_break::wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> str_set;
    for (const string& it : wordDict) {
        str_set.insert(it);
    }
    int len = s.length();
    vector<bool> dp(len + 1);
    dp[0] = true;
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && str_set.find(s.substr(j, i - j)) != str_set.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[len];
}