// Q. https://leetcode.com/problems/add-two-numbers/

#include <iostream>

//  Definition for singly-linked list.
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
    ListNode* CreateNode(int val) {
        ListNode *temp = new ListNode();
        temp->val = val;
        temp->next = nullptr;

        return temp;
        delete temp;
    }
    void AddNodeAtEnd(ListNode* head, int val) {
        ListNode* ptr = head;
        ListNode* temp = CreateNode(val);

        while(ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }

    void Display(ListNode* head) {
        ListNode* temp = head;

        while (temp != nullptr)
        {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        printf("\n");
    }

    ListNode *reverseList(ListNode *head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (head != nullptr)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        head = prev;

        return head;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        uint64_t val1 = 0;
        uint64_t val2 = 0;
        uint64_t sum = 0;

        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        while (temp1 != nullptr)
        {
            val1 = (val1 * 10) + (temp1->val % 10);
            temp1 = temp1->next;
        }

        while (temp2 != nullptr)
        {
            val2 = (val2 * 10) + (temp2->val % 10);
            temp2 = temp2->next;
        }
        sum = val1 + val2;

        std::cout << val1 << "+" << val2 << " = " << sum << std::endl;

        ListNode * head = new ListNode();

        uint64_t mod = sum % 10;
        sum = sum / 10;
        head = CreateNode(mod);

        while (sum > 0)
        {
            mod = sum % 10;
            AddNodeAtEnd(head, mod);
            sum = sum / 10;
        }

        return head;
    }
};


int main()
{
    // [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]
    Solution obj;

    ListNode *head1 = new ListNode();
    head1 = obj.CreateNode(1);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 0);
    obj.AddNodeAtEnd(head1, 1);

    ListNode *head2 = new ListNode();
    head2 = obj.CreateNode(5);
    obj.AddNodeAtEnd(head2, 6);
    obj.AddNodeAtEnd(head2, 4);

    obj.Display(head1);
    obj.Display(head2);

    ListNode *head = new ListNode();
    head = obj.addTwoNumbers(head1, head2);

    obj.Display(head);
    return 0;
}

// Ans ->
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* ans = new ListNode();
        
//         ListNode* head = ans;
//         int carry = 0, val1, val2;
        
//         while(l1 != nullptr || l2 != nullptr) {
//             val1 = 0; 
//             val2 = 0;    // Initiallizing as 0 incase node doesn't exist
            
//             if(l1 != nullptr) {
//                 val1 = l1->val;
//                 l1 = l1->next;
//             }
            
//             if(l2 != nullptr) {
//                 val2 = l2->val;
//                 l2 = l2->next;
//             }
         
//             head->val = (val1 + val2 + carry) % 10; // taking out last digit    
//             carry = (val1 + val2 + carry) / 10; // taking out first digit
            
//             // If any of this is true then,
//             // we will create another node using constructor
//             if(l1 != nullptr || l2  != nullptr || carry != 0)   
//             {
//                 head->next = new ListNode();
//                 head = head->next;
//             }
//         }
        
//         // Edge Case
//         if(carry) {
//             head->val = carry;
//         }
        
//         return ans;
//     }
// };