#include "daily_temperatures.h"
#include <stack>
daily_temperatures::daily_temperatures() {
    
}

daily_temperatures::~daily_temperatures() {
    
}

vector<int> daily_temperatures::dailyTemperatures(vector<int>& temperatures) {
    stack<int> mono_stk;
    vector<int> res(temperatures.size());
    for (int i = 0; i < temperatures.size(); i++) {
        if (mono_stk.empty()) {
            mono_stk.push(i);
            continue;
        }
        while (!mono_stk.empty() && temperatures[mono_stk.top()] < temperatures[i]) {
            res[mono_stk.top()] = i - mono_stk.top();
            mono_stk.pop();
        }
        mono_stk.push(i);
    }
    return res;
}