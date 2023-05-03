#ifndef __design_linked_list_h__
#define __design_linked_list_h__

#include <cassert>
#include <vector>
using std::vector;

class MyLinkedList {
private:
    struct Node {
        int val{0};
        Node* prev{nullptr};
        Node* next{nullptr};
        Node() {}
        Node(int val) : val(val) {}
    };
    // dummy head and dummy tail.
    Node* head{nullptr};
    Node* tail{nullptr};
    int size{0};

    Node* get_node_at_index(int index) const {
        if (index >= size) {
            return nullptr;
        }
        Node* ret = head;
        while (index >= 0) {
            ret = ret->next;
            index--;
        }
        return ret;
    }

    void remove_node_at_index(int index) {
        Node* cur = get_node_at_index(index);
        if (cur == nullptr) {
            return;
        }
        Node* prev = cur->prev;
        Node* next = cur->next;
        prev->next = next;
        next->prev = prev;
        cur->prev = nullptr;
        cur->next = nullptr;
        delete cur;
        size--;
    }

    void insert_before(Node* cur, Node* next) {
        assert(next != nullptr);
        cur->prev = next->prev;
        cur->prev->next = cur;
        next->prev = cur;
        cur->next = next;
    }

    void insert_node_at_index(int val, int index) {
        Node* node = new Node(val);
        Node* pos = get_node_at_index(index);
        if (pos == nullptr) {
            // must be the tail, pos >= size.
            if (index > size) {
                delete node;
                return;
            }
            insert_before(node, tail);
        } else {
            insert_before(node, pos);
        }
        size++;
    }

public:
    MyLinkedList();
    ~MyLinkedList();

    int get(int index);

    void addAtHead(int val);

    void addAtTail(int val);

    void addAtIndex(int index, int val);

    void deleteAtIndex(int index);
};

#endif