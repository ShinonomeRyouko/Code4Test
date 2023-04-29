#include "longest_valid_parentheses.h"

#include <stack>

using namespace std;

longest_valid_parentheses::longest_valid_parentheses() {}

longest_valid_parentheses::~longest_valid_parentheses() {}

int longest_valid_parentheses::longestValidParentheses(string s) {
    int max_len = 0;
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                max_len = max(i - st.top(), max_len);
            }
        }
    }
    return max_len;
}