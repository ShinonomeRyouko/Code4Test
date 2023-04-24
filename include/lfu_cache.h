#ifndef __lfu_cache_h__
#define __lfu_cache_h__

#include <list>
#include <unordered_map>
using namespace std;
class LFUCache {
private:
    struct Node {
        int key, val, freq;
        Node(int key, int val, int freq) : key(key), val(val), freq(freq) {}
    };
    typedef list<Node>::iterator node_handle;
    unordered_map<int, node_handle> key_table;
    unordered_map<int, list<Node>> freq_table;
    int capacity;
    int min_freq;
public:
    LFUCache(int capacity);
    int get(int key);
    void put(int key, int value);
    ~LFUCache();
};

#endif