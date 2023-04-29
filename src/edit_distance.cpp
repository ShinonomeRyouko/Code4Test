#include "edit_distance.h"
#include <vector>

using namespace std;

edit_distance::edit_distance() {}

edit_distance::~edit_distance() {}

int edit_distance::minDistance(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();
    if (len1 * len2 == 0) {
        return len1 + len2;
    }
    vector<vector<int>> vec(len1 + 1, vector<int>(len2 + 1));
    for (int i = 1; i <= len1; i++) {
        vec[i][0] = i;
    }
    for (int i = 1; i <= len2; i++) {
        vec[0][i] = i;
    }
    int left, down, left_down;
    /*
    i) same char at this position:
        D[i][j] = min(D[i][j-1]+1, D[i-1][j]+1, D[i-1][j-1])
    ii) different char at this position:
        D[i][j] = min(D[i][j-1]+1, D[i-1][j]+1, D[i-1][j-1]+1)
    */
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            left = vec[i - 1][j];
            down = vec[i][j - 1];
            left_down = vec[i - 1][j - 1];
            // i-1 and j-1 is the correct pos of string.
            if (word1[i - 1] == word2[j - 1]) {
                left_down--;
            }
            vec[i][j] = 1 + min(left, min(down, left_down));
        }
    }
    return vec[len1][len2];
}