#include "longest_consecutive_sequence.h"

#include <unordered_set>

using namespace std;

longest_consecutive_sequence::longest_consecutive_sequence() {}

longest_consecutive_sequence::~longest_consecutive_sequence() {}

int longest_consecutive_sequence::longestConsecutive(vector<int>& nums) {
    unordered_set<int> filter;
    for (const int& n : nums) {
        filter.insert(n);
    }
    int longest = 0;
    int seq_len = 0;
    int cur = 0;
    for (const int& n : nums) {
        // always cnt from the leftmost of a consecutive sequence.
        if (filter.find(n - 1) != filter.end()) {
            continue;
        }
        cur = n + 1;
        seq_len = 1;
        // now cnt to the rightmost.
        while (filter.find(cur) != filter.end()) {
            cur++;
            seq_len++;
        }
        longest = max(longest, seq_len);
    }
    return longest;
}