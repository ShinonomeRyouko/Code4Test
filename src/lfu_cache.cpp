#include "lfu_cache.h"

LFUCache::LFUCache(int capacity) : capacity(capacity) { min_freq = 0; }

int LFUCache::get(int key) {
    auto handle = key_table.find(key);
    if (handle == key_table.end()) {
        return -1;
    }
    node_handle node = handle->second;
    int val = node->val;
    int freq = node->freq;
    freq_table[freq].erase(node);
    if (freq_table[freq].size() == 0) {
        freq_table.erase(freq);
        if (min_freq == freq) {
            min_freq++;
        }
    }
    freq++;
    freq_table[freq].push_front(Node{key, val, freq});
    key_table[key] = freq_table[freq].begin();
    return val;
}

void LFUCache::put(int key, int value) {
    auto handle = key_table.find(key);
    if (handle != key_table.end()) {
        node_handle node = handle->second;
        int freq = node->freq;
        freq_table[freq].erase(node);
        if (freq_table[freq].size() == 0) {
            freq_table.erase(freq);
            if (min_freq == freq) {
                min_freq++;
            }
        }
        freq++;
        freq_table[freq].push_front(Node{key, value, freq});
        key_table[key] = freq_table[freq].begin();
    } else {
        if (key_table.size() == capacity) {
            auto node = freq_table[min_freq].back();
            key_table.erase(node.key);
            freq_table[min_freq].pop_back();
            if (freq_table[min_freq].size() == 0) {
                freq_table.erase(min_freq);
            }
        }
        min_freq = 1;
        freq_table[min_freq].push_front(Node{key, value, min_freq});
        key_table[key] = freq_table[min_freq].begin();
    }
}

LFUCache::~LFUCache() {}