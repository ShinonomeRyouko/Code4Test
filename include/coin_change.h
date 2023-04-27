#ifndef __coin_change_h__
#define __coin_change_h__

#include <vector>
using namespace std;
class coin_change {
private:

public:
    coin_change();
    ~coin_change();
    int coinChange(vector<int>& coins, int amount);
};

#endif