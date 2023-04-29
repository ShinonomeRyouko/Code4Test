#include "maximal_rectangle.h"

#include <stack>

using namespace std;

maximal_rectangle::maximal_rectangle() {}

maximal_rectangle::~maximal_rectangle() {}

int largestRectangleArea(vector<int>& heights) {
    int pos = 0;
    stack<int> mono_stack;
    int st_top = 0;
    mono_stack.push(-1);
    int max_area = 0;
    int cmp_val = 0;
    while (true) {
        cmp_val = (pos == heights.size()) ? -1 : heights[pos];
        while (mono_stack.top() != -1 && heights[mono_stack.top()] > cmp_val) {
            st_top = mono_stack.top();
            mono_stack.pop();
            max_area = max(max_area, (pos - mono_stack.top() - 1) * heights[st_top]);
        }
        if (pos < heights.size()) {
            mono_stack.push(pos);
            pos++;
        }
        if (pos == heights.size() && mono_stack.top() == -1) {
            break;
        }
    }
    return max_area;
}

int maximal_rectangle::maximalRectangle(vector<vector<char>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    // scan the matrix top-down, at each layer you will get different histogram.
    vector<int> histogram(col);
    int max_area = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == '0') {
                histogram[j] = 0;
            } else {
                histogram[j]++;
            }
        }
        max_area = max(max_area, largestRectangleArea(histogram));
    }
    return max_area;
}