#ifndef __jump_game_h__
#define __jump_game_h__

#include <vector>
using std::vector;

class jump_game {
private:
public:
    jump_game();
    ~jump_game();
    bool canJump(vector<int>& nums);
};

#endif