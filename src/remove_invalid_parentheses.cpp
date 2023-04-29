#include "remove_invalid_parentheses.h"
#include <unordered_set>

using namespace std;

remove_invalid_parentheses::remove_invalid_parentheses() {}

remove_invalid_parentheses::~remove_invalid_parentheses() {}

bool is_valid(string str) {
    int cnt = 0;
    for (char ch : str) {
        if (ch == '(') {
            cnt++;
        } else if (ch == ')') {
            cnt--;
        }
        if (cnt < 0) {
            break;
        }
    }
    return cnt == 0;
}

vector<string> remove_invalid_parentheses::removeInvalidParentheses(string s) {
    vector<string> res;
    unordered_set<string> cur_set;
    cur_set.insert(s);

    while (true) {
        for (auto str : cur_set) {
            if (is_valid(str)) {
                res.emplace_back(str);
            }
        }
        if (res.size() > 0) {
            break;
        }
        unordered_set<string> next_set;
        for (auto str : cur_set) {
            for (int i = 0; i < str.size(); i++) {
                if (i > 0 && str[i] == str[i - 1]) {
                    continue;
                }
                if (str[i] == '(' || str[i] == ')') {
                    next_set.insert(str.substr(0, i) + str.substr(i + 1));
                }
            }
        }
        cur_set = next_set;
    }
    return res;
}