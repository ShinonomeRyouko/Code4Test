#include "gas_station.h"

#include <climits>

using namespace std;

gas_station::gas_station() {}

gas_station::~gas_station() {}

int gas_station::canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();
    int index = 0;
    int min_spare = INT_MAX;
    // the total spare should be greater than 0 if there is an answer.
    int spare = 0;
    for (int i = 0; i < len; i++) {
        spare += gas[i] - cost[i];
        if (min_spare > spare) {
            index = i;
            min_spare = spare;
        }
    }
    return (spare >= 0) ? (index + 1) % len : -1;
}