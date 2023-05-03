#ifndef __partition_labels_h__
#define __partition_labels_h__

#include <string>
#include <vector>
using std::string;
using std::vector;

class partition_labels {
private:
public:
    partition_labels();
    ~partition_labels();
    vector<int> partitionLabels(string s);
};

#endif