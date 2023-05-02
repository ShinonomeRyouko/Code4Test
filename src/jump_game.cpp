#include "jump_game.h"

using namespace std;

jump_game::jump_game() {}

jump_game::~jump_game() {}

bool jump_game::canJump(vector<int>& nums) {
    int len = nums.size();
    int rightmost = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (rightmost >= i) {
            rightmost = max(rightmost, i + nums[i]);
        } else {
            break;
        }
    }
    return rightmost >= len - 1;
}