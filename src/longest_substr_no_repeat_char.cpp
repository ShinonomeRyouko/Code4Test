#include "longest_substr_no_repeat_char.h"

#include <unordered_set>
using namespace std;

longest_substr_no_repeat_char::longest_substr_no_repeat_char() {}

longest_substr_no_repeat_char::~longest_substr_no_repeat_char() {}

int longest_substr_no_repeat_char::lengthOfLongestSubstring(string s) {
    unordered_set<char> filter;
    int left = 0;
    int cur = 0;
    int max_len = 0;
    for (auto ch : s) {
        while (filter.find(ch) != filter.end()) {
            filter.erase(s[left]);
            left++;
        }
        filter.insert(ch);
        max_len = max(cur - left + 1, max_len);
        cur++;
    }
    return max_len;
}