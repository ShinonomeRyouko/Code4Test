#include "sort_characters_by_frequency.h"

#include <unordered_map>

using namespace std;

sort_characters_by_frequency::sort_characters_by_frequency() {}

sort_characters_by_frequency::~sort_characters_by_frequency() {}

string sort_characters_by_frequency::frequencySort(string s) {
    int max_cnt = 0;
    unordered_map<char, int> cnt_map;
    for (const char& ch : s) {
        cnt_map[ch]++;
        max_cnt = max(max_cnt, cnt_map[ch]);
    }
    // strings with same cnt pushed into same string bucket.
    vector<string> buckets(max_cnt + 1);
    for (auto& it : cnt_map) {
        buckets[it.second].push_back(it.first);
    }
    string ret;
    for (int i = max_cnt; i >= 0; i--) {
        if (buckets[i].empty()) {
            continue;
        }
        // Don't forget frequency.
        for (const char& ch : buckets[i]) {
            for (int j = i; j >= 1; j--) {
                ret += ch;
            }
        }
    }
    return ret;
}