// Q. https://leetcode.com/problems/reverse-linked-list-ii/
// 92. Reverse Linked List II

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *dummy = new ListNode(0); // created dummy node
    dummy->next = head;
    ListNode *prev = dummy; // intialising prev pointer on dummy node
    
    for(int i = 0; i < left - 1; i++)
        prev = prev->next; // adjusting the prev pointer on it's actual index
        
    ListNode *curr = prev->next; // curr pointer will be just after prev
    // reversing
    for(int i = 0; i < right - left; i++){
        ListNode *forw = curr->next; // forw pointer will be after curr
        curr->next = forw->next;
        forw->next = prev->next;
        prev->next = forw;
    }
    return dummy->next;
}

int main()
{
    ListNode* temp4 = new ListNode(5, nullptr);
    ListNode* temp3 = new ListNode(4, temp4);
    ListNode* temp2 = new ListNode(3, temp3);
    ListNode* temp1 = new ListNode(2, temp2);
    ListNode* head = new ListNode(1, temp1);
    int left = 2;
    int right = 4;

    ListNode* temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }

    head = reverseBetween(head, left, right);
    printf("\n");

    temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    
    return 0;
}