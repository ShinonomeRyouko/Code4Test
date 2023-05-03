#ifndef __largest_number_h__
#define __largest_number_h__

#include <string>
#include <vector>
using std::string;
using std::vector;

class largest_number {
private:
public:
    largest_number();
    ~largest_number();
    string largestNumber(vector<int>& nums);
};

#endif