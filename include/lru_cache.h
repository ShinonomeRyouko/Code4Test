#ifndef __lru_cache_h__
#define __lru_cache_h__

#include <unordered_map>
using namespace std;
class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev{nullptr};
        Node* next{nullptr};
        Node(int key, int value) : key(key), value(value) {}
    };
    Node* head{nullptr};  // dummy head
    Node* tail{nullptr};  // dummy tail
    unordered_map<int, Node*> u_map;
    int capacity{0};

    typedef unordered_map<int, Node*>::iterator node_handle;

    void remove_from_list(Node* node);
    void set_head(Node* node);

public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
    ~LRUCache();
};

#endif
