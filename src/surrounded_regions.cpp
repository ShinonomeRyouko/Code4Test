#include "surrounded_regions.h"
#include <queue>
surrounded_regions::surrounded_regions() {
    
}

surrounded_regions::~surrounded_regions() {
    
}
#include <cassert>
void surrounded_regions::BFS(vector<vector<char>>& board, int row, int col, int x, int y) {
    queue<pair<int, int>> q;
    board[x][y] = 'A';
    q.emplace(x, y);
    int nx, ny;
    while (!q.empty()) {
        for (int i = 0; i < 4; i++) {
            nx = q.front().first + direction[i];
            ny = q.front().second + direction[i + 1];
            if (nx >= 0 && nx < row && ny >= 0 && ny < col && board[nx][ny] == 'O') {
                board[nx][ny] = 'A';
                q.emplace(nx, ny);
            }
        }
        q.pop();
    }
}

void surrounded_regions::solve(vector<vector<char>>& board) {
    int row = board.size();
    int col = board[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                if (board[i][j] == 'O') {
                    BFS(board, row, col, i, j);
                }
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
            if (board[i][j] == 'A') {
                board[i][j] = 'O';
            }
        }
    }
}