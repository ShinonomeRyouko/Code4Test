#ifndef __gas_station_h__
#define __gas_station_h__

#include <vector>
using std::vector;

class gas_station {
private:
public:
    gas_station();
    ~gas_station();
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
};

#endif