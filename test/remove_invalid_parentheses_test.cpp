#include "remove_invalid_parentheses.h"

#include <algorithm>

#include "gtest/gtest.h"

inline bool IsStringVectorEQ(vector<string>& l, vector<string>& r) {
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    return l == r;
}

inline void CaseTest(string str, vector<string> ans, remove_invalid_parentheses& obj) {
    vector<string> res = obj.removeInvalidParentheses(str);
    EXPECT_TRUE(IsStringVectorEQ(res, ans));
}

TEST(remove_invalid_parenthesesTest, SimpleTest) {
    remove_invalid_parentheses* obj = new remove_invalid_parentheses();
    CaseTest("()())()", {"(())()", "()()()"}, *obj);
    CaseTest("(a)())()", {"(a())()", "(a)()()"}, *obj);
    CaseTest(")(", {""}, *obj);
    delete obj;
}