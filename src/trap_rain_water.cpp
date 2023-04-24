#include "trap_rain_water.h"
#include <queue>

typedef pair<int, int> pii;
int Solution::trapRainWater(vector<vector<int>>& heightMap) {
        int row = heightMap.size();
        int col = heightMap[0].size();
        if (row <= 2 || col <= 2) {
            return 0;
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                    pq.push(make_pair(heightMap[i][j], i * col + j));
                    visited[i][j] = true;
                }
            }
        }
        vector<int> directions = {-1, 0, 1, 0, -1};
        int res = 0;
        pii tmp;
        int nx, ny;
        while (!pq.empty()) {
            tmp = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++) {
                nx = tmp.second / col + directions[i];
                ny = tmp.second % col + directions[i + 1];
                if (nx > 0 && nx < row && ny > 0 && ny < col && !visited[nx][ny]) {
                    if (tmp.first > heightMap[nx][ny]) {
                        res += (tmp.first - heightMap[nx][ny]);
                    }
                    visited[nx][ny] = true;
                    pq.push(make_pair(max(heightMap[nx][ny], tmp.first), nx * col + ny));
                }
            }
        }
        return res;
};