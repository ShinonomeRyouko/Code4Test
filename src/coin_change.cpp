#include "coin_change.h"

coin_change::coin_change() {}

coin_change::~coin_change() {}

int coin_change::coinChange(vector<int>& coins, int amount) {
    vector<int> dp(1 + amount, 1 + amount);
    dp[0] = 0;
    // dp[i] = min{dp[i-coins[each]]} + 1
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    // if no solution, dp[amount] will be amount + 1.
    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}