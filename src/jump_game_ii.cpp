#include "jump_game_ii.h"

using namespace std;

jump_game_ii::jump_game_ii() {}

jump_game_ii::~jump_game_ii() {}

int jump_game_ii::jump(vector<int>& nums) {
    int rightmost = 0, end = 0, step = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        rightmost = max(rightmost, nums[i] + 1);
        if (i == end) {
            end = rightmost;
            step++;
            // reach (0, nums[0]] by 1 step,
            // iterate [1, nums[0]] to see how far we can reach by 2 steps.
            // Then, reach (rightmost_prev, rightmost_now) by i steps,
            // iterate [rightmost_prev + 1, rightmost_now]
            // to see how far we can reach by i + 1 steps.
        }
    }
    return step;
}