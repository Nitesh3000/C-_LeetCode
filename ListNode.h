#ifndef LISTNODE_H
#define LISTNODE_H

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    // Method to create a linked list from a vector
    static ListNode* createLinkedList(const std::vector<int>& values);
};

#endif // LISTNODE_H