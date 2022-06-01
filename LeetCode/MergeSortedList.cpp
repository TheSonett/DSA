// Q. https://leetcode.com/problems/merge-two-sorted-lists/

// NOTE: I solved this problem, but not efficiently!
// Time Complexity is O(n^2)

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         // Check if they pass any two empty list or not
       // if list1 happen to be NULL
		// we will simply return list2.
        if(list1 == NULL)
            return list2;
		
		// if list2 happen to be NULL
		// we will simply return list1.
        if(list2 == NULL)
            return list1;

        // Adding list2 with list1 with the help of list2 head pointer
        ListNode* temp = list1;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = list2;

        // We have to compare two values & then swap
        ListNode *ptr1 = list1;
        ListNode *ptr2;
        
        // O(n^2) -> Not an efficient way, but for not it works!
        while (ptr1->next != nullptr)
        {
            ptr2 = ptr1->next;
            while (ptr2 != nullptr)
            { 
                if(ptr1->val > ptr2->val) {
                    int temp = ptr1->val;
                    ptr1->val = ptr2->val;
                    ptr2->val = temp;
                }

                ptr2 = ptr2->next;
            }
            
            ptr1 = ptr1->next;
        }

        return list1;
    }

public:
    ListNode* CreateNode(int val) {
        ListNode *temp = new ListNode();
        temp->val = val;
        temp->next = nullptr;

        return temp;
    }

    void AddNodeAtEnd(ListNode* head, int val) {
        ListNode *ptr = head;
        ListNode *temp = CreateNode(val);

        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        
        ptr->next = temp;
    }

    void display(ListNode* list) {
        ListNode* temp = list;
        std::cout << "[ ";
        while (temp != nullptr)
        {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << "]\n";
    }
};

int main()
{
    Solution obj;

    ListNode *list1 = new ListNode();
    list1 = obj.CreateNode(1);
    obj.AddNodeAtEnd(list1, 2);
    obj.AddNodeAtEnd(list1, 4);

    ListNode *list2 = new ListNode();
    list2 = obj.CreateNode(1);
    obj.AddNodeAtEnd(list2, 3);
    obj.AddNodeAtEnd(list2, 4);

    obj.display(list1);
    obj.display(list2);

    std::cout << "\nAfter merging two lists ::: \n\n";

    ListNode* head = obj.mergeTwoLists(list1, list2);
    obj.display(head);

    return 0;
}