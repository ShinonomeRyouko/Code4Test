#ifndef __edit_distance_h__
#define __edit_distance_h__

#include <string>
using std::string;
class edit_distance {
private:
public:
    edit_distance();
    ~edit_distance();

    int minDistance(string word1, string word2);
};

#endif