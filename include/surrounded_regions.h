#ifndef __surrounded_regions_h__
#define __surrounded_regions_h__

#include <vector>
using namespace std;
class surrounded_regions {
private:
    vector<int> direction{-1, 0, 1, 0, -1};
    void BFS(vector<vector<char>>& board, int row, int col, int i, int j);
public:
    surrounded_regions();
    ~surrounded_regions();
    void solve(vector<vector<char>>& board);
};

#endif