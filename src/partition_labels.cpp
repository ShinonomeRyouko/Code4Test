#include "partition_labels.h"

using namespace std;

partition_labels::partition_labels() {}

partition_labels::~partition_labels() {}

vector<int> partition_labels::partitionLabels(string s) {
    int len = s.length();
    vector<int> last(26);
    // record the last pos where ch appears.
    for (int i = 0; i < len; i++) {
        last[s[i] - 'a'] = i;
    }
    vector<int> res;
    int start = 0, end = 0;
    for (int i = 0; i < len; i++) {
        end = max(end, last[s[i] - 'a']);
        if (i == end) {
            res.emplace_back(end - start + 1);
            start = end + 1;
        }
    }
    return res;
}