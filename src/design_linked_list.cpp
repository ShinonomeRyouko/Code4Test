#include "design_linked_list.h"

using namespace std;

MyLinkedList::MyLinkedList() {
    head = new Node();
    head->next = tail;
    tail = new Node();
    tail->prev = head;
}

MyLinkedList::~MyLinkedList() {
    Node* prev = head;
    Node* cur = head->next;
    while (prev != nullptr) {
        delete prev;
        prev = cur;
        if (cur != nullptr) {
            cur = cur->next;
        }
    }
}

int MyLinkedList::get(int index) {
    Node* node = get_node_at_index(index);
    return (node == nullptr) ? -1 : node->val;
}

void MyLinkedList::addAtHead(int val) { insert_node_at_index(val, 0); }

void MyLinkedList::addAtTail(int val) { insert_node_at_index(val, size); }

void MyLinkedList::addAtIndex(int index, int val) { insert_node_at_index(val, index); }

void MyLinkedList::deleteAtIndex(int index) { remove_node_at_index(index); }
