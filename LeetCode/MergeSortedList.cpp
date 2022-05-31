#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <array>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <set>
#include <any>
#include <cstring>
#include <string>
#include <memory>
#include <climits>
#include <bitset>
#include <string_view>
#include <iterator>

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
        if(!list1 || !list2) {
            return nullptr;
        } 
        else if((list1->next == NULL && list2->val == 0) || (list1->val == 0 && list2->next == NULL)) {
            ListNode *temp = new ListNode(0);
            return temp;
        }

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
        
        // O(n^2) Not efficient method
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
    //list1 = obj.CreateNode(0);
    // obj.AddNodeAtEnd(list1, 2);
    // obj.AddNodeAtEnd(list1, 4);

    ListNode *list2 = new ListNode();
    list2 = obj.CreateNode(1);
    // obj.AddNodeAtEnd(list2, 3);
    // obj.AddNodeAtEnd(list2, 4);

    obj.display(list1);
    obj.display(list2);

    std::cout << "\nAfter merging two lists, We have ..........\n\n";

    ListNode* head = obj.mergeTwoLists(list1, list2);
    obj.display(head);

    return 0;
}