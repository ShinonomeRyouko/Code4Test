#include "largest_number.h"

#include <algorithm>

using namespace std;

largest_number::largest_number() {}

largest_number::~largest_number() {}

string largest_number::largestNumber(vector<int>& nums) {
    vector<string> vec;
    for (const int& n : nums) {
        vec.emplace_back(to_string(n));
    }
    sort(vec.begin(), vec.end(), [](const string& l, const string& r) { return l + r > r + l; });
    string ret;
    for (const string& str : vec) {
        ret += str;
    }
    if (ret[0] == '0') {
        ret = "0";
    }
    return ret;
}