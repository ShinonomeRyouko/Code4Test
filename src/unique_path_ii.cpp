#include "unique_path_ii.h"

using namespace std;

unique_path_ii::unique_path_ii() {}

unique_path_ii::~unique_path_ii() {}

int unique_path_ii::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size(), col = obstacleGrid[0].size();
    vector<int> dp(row);

    // When iterate row i, dp contains number of paths to row i - 1's cols.
    // Case 1: obstacleGrid[i][j] == 1, dp[j] in row i is same as dp[j] in row i - 1;
    // Case 2: obstacleGrid[i][j] == 0, dp[j] += dp[j - 1],
    //         the sum of paths to obstacleGrid[i][j-1] and paths to obstacleGrid[i-1][j].
    dp[0] = (obstacleGrid[0][0] == 0);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[j] = 0;
                continue;
            }
            if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                dp[j] += dp[j - 1];
            }
        }
    }
    return dp.back();
}