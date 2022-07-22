// Q. https://leetcode.com/problems/partition-list/
// 86. Partition List

#include <iostream>
#include <algorithm>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode* left = new ListNode(0, nullptr);
    ListNode* right = new ListNode(0, nullptr);

    ListNode* leftHead = left;
    ListNode* rightHead = right;

    while(head != nullptr) {
        if(head->val < x) {
            // adding the node to leftHead, then move the leftHead
            leftHead->next = head;
            leftHead = leftHead->next;
        }
        else if (head->val >= x) {
            rightHead->next = head;
            rightHead = rightHead->next;
        }

        head = head->next;
    }

    // connecting two lists
    leftHead->next = right->next;
    rightHead->next = nullptr;

    return leftHead->next;
}