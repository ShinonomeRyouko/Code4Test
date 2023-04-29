#include "largest_rectangle_in_histogram.h"

#include <cassert>
#include <stack>

using namespace std;

largest_rectangle_in_histogram::largest_rectangle_in_histogram() {}

largest_rectangle_in_histogram::~largest_rectangle_in_histogram() {}

int largest_rectangle_in_histogram::largestRectangleArea(vector<int>& heights) {
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