#include "lru_cache.h"

void LRUCache::remove_from_list(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void LRUCache::set_head(Node *node) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
}

LRUCache::LRUCache(int capacity) : capacity(capacity) {
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
}

int LRUCache::get(int key) {
    node_handle handle = u_map.find(key);
    if (handle == u_map.end()) {
        return -1;
    }
    Node *node = handle->second;
    int ret = node->value;
    remove_from_list(node);
    set_head(node);
    return ret;
}

void LRUCache::put(int key, int value) {
    node_handle handle = u_map.find(key);
    if (handle != u_map.end()) {
        Node *node = handle->second;
        node->value = value;
        remove_from_list(node);
        set_head(node);
    } else {
        Node *node = new Node(key, value);
        u_map.insert(make_pair(key, node));
        set_head(node);
        if (u_map.size() > capacity) {
            Node *remove_node = tail->prev;
            remove_from_list(remove_node);
            node_handle remove_handle = u_map.find(remove_node->key);
            u_map.erase(remove_handle);
            delete remove_node;
        }
    }
}

LRUCache::~LRUCache() {
    for (auto it : u_map) {
        delete it.second;
    }
    delete head;
    delete tail;
}
