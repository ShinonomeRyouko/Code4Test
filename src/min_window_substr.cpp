#include "min_window_substr.h"

#include <vector>
min_window_substr::min_window_substr() {}

min_window_substr::~min_window_substr() {}

string min_window_substr::minWindow(string s, string t) {
    if (s.length() < t.length() || s.length() == 0 || t.length() == 0) {
        return "";
    }
    int min_len = INT32_MAX;
    int left = 0, right = 0, head = 0;
    int found = t.length();
    vector<int> ch_cnt(256);
    for (auto ch : t) {
        ch_cnt[ch]++;
    }
    while (right < s.length()) {
        // -- op effects both relative and irrelative ch.
        if (ch_cnt[s[right++]]-- > 0) {
            found--;
        }
        while (found == 0) {
            if (right - left < min_len) {
                min_len = right - (head = left);
            }
            // only relative ch cnt meets this condition, because ch_cnt[ch]++ before.
            if (ch_cnt[s[left++]]++ == 0) {
                found++;
            }
        }
    }
    return min_len == INT32_MAX ? "" : s.substr(head, min_len);
}