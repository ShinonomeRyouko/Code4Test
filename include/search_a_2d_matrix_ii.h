#ifndef __search_a_2d_matrix_ii_h__
#define __search_a_2d_matrix_ii_h__

#include <vector>
using std::pair;
using std::vector;

class search_a_2d_matrix_ii {
private:
public:
    search_a_2d_matrix_ii();
    ~search_a_2d_matrix_ii();
    bool searchMatrix(vector<vector<int>>& matrix, int target);
};

#endif