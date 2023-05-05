#include "search_a_2d_matrix_ii.h"

#include <cassert>

using namespace std;

search_a_2d_matrix_ii::search_a_2d_matrix_ii() {}

search_a_2d_matrix_ii::~search_a_2d_matrix_ii() {}

struct State {
    int start_row{0};
    int end_row{0};
    int start_col{0};
    int end_col{0};
    State(int sr, int er, int sc, int ec) : start_row(sr), end_row(er), start_col(sc), end_col(ec) {}
};

bool search_matrix(const vector<vector<int>>& matrix, const int& target) {
    vector<State> vec;
    vec.emplace_back(0, matrix.size() - 1, 0, matrix[0].size() - 1);
    int row{0}, col{0}, diagonal{0}, lower{0}, upper{0}, mid{0};
    bool row_inc{false}, col_inc{false};
    int tmp{0};
    int start_row{0}, end_row{0}, start_col{0}, end_col{0};
    while (!vec.empty()) {
        start_row = vec.back().start_row;
        end_row = vec.back().end_row;
        start_col = vec.back().start_col;
        end_col = vec.back().end_col;
        vec.pop_back();
        if (target < matrix[start_row][start_col] || target > matrix[end_row][end_col]) {
            continue;
        }
        row = end_row - start_row;
        col = end_col - start_col;
        diagonal = min(row, col);
        lower = 0, upper = (diagonal != 0) ? diagonal + 1 : max(row, col) + 1;
        row_inc = (row != 0), col_inc = (col != 0);
        // binary search on diagonal or cow or col.
        while (lower < upper) {
            mid = (lower + upper) / 2;
            tmp = matrix[start_row + ((row_inc) ? mid : 0)][start_col + ((col_inc) ? mid : 0)];
            if (tmp < target) {
                lower = mid + 1;
            } else if (tmp > target) {
                upper = mid;
            } else {
                return true;
            }
        }
        // no result in this row or col.
        if (diagonal == 0) {
            continue;
        }
        assert(upper <= diagonal + 1);
        if (upper != diagonal + 1) {
            vec.emplace_back(start_row, start_row + upper - 1, start_col + upper, end_col);
            vec.emplace_back(start_row + upper, end_row, start_col, start_col + upper - 1);
        } else {
            // case that upper == diagonal + 1 && row != col.
            assert(row != col);
            if (row > col) {
                vec.emplace_back(start_row + upper, end_row, start_col, end_col);
            } else {
                vec.emplace_back(start_row, end_row, start_col + upper, end_col);
            }
        }
    }
    return false;
}

bool search_a_2d_matrix_ii::searchMatrix(vector<vector<int>>& matrix, int target) { return search_matrix(matrix, target); }