#ifndef __top_k_frequent_elements_h__
#define __top_k_frequent_elements_h__

#include <vector>
using namespace std;
class top_k_frequent_elements {
private:
public:
    top_k_frequent_elements();
    ~top_k_frequent_elements();
    vector<int> topKFrequent(vector<int>& nums, int k);
};

#endif