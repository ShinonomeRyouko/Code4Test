#ifndef __daily_temperatures_h__
#define __daily_temperatures_h__

#include <vector>
using std::vector;
class daily_temperatures {
private:
public:
    daily_temperatures();
    ~daily_temperatures();
    vector<int> dailyTemperatures(vector<int>& temperatures);
};

#endif