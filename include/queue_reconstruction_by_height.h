#ifndef __queue_reconstruction_by_height_h__
#define __queue_reconstruction_by_height_h__

#include <vector>
using std::vector;

class queue_reconstruction_by_height {
private:
public:
    queue_reconstruction_by_height();
    ~queue_reconstruction_by_height();
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people);
};

#endif