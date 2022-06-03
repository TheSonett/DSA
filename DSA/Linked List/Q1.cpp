// Q. Remove duplicate elements from a sorted list/unsorted list

#include <iostream>
#include <unordered_map>

class Node {
    public:
        int val; // 4 BYTES
        Node* next; // 4 * 4 = 16 BYTES

        ~Node() {
            //std::cout << "Destroyed!" << std::endl;
        }
};

// Creating a Node
Node* CreateNode(int val) {
    Node *temp = new Node();
    temp->val = val;
    temp->next = nullptr;

    return temp;
    delete temp;
}

void AddNodeAtEnd(Node* head, int val) {
    Node* ptr = head;
    Node* temp = CreateNode(val);

    while(ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

Node* AddNodeAtStart(Node* head, int val) {
    Node* temp = CreateNode(val);
    temp->next = head;
    head = temp;

    return head;
}

int NumberOfNodes(Node* head) {
    Node* temp = head;
    int count = 0;

    while(temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

void Display(Node* head) {
    Node* temp = head;

    while (temp != nullptr)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    printf("\n");
}

// Time Complexity -> O(n)
Node* RemoveDuplicatesFromSortedList(Node* head) {
    Node* current = head;

    if(current == NULL) {
        std::cout << "Node not created!\n";
        return NULL;
    } 
    
    while (current->next != NULL)
    {
        if(current->val == current->next->val) {
            Node* next_next = current->next->next;
            Node* nodeToDelete = current->next;
            
            delete(nodeToDelete);

            current->next = next_next;
        }
        else {
            current = current->next;
        }
    }
    
    return head;
}

// Time Complexity -> O(n^2)
// Node* RemoveDuplicatesFromUnsortedList(Node* head) {
//     Node* current = head;

//     if(current == NULL) {
//         std::cout << "Node not created!\n";
//         return NULL;
//     } 
    
//     while (current != NULL)
//     {
//         Node* temp = current->next;
//         Node* prev = current;
        
//         while (temp != NULL)
//         {
//             if(current->val == temp->val) {
//                 Node* nextNode = temp->next;
//                 delete(temp);

//                 prev->next = nextNode;
//                 temp = nextNode;
//             }
//             else {
//                 temp = temp->next;
//                 prev = prev->next;
//             }
//         }
        
//         current = current->next;
//     }
    
//     return head;
// }

// Time Complexity O(n)
// Node* RemoveDuplicatesFromUnsortedList(Node* head) {
//     head = RemoveDuplicatesFromSortedList(head);

//     Node* current = head;

//     if(current == NULL) {
//         std::cout << "Node not created!\n";
//         return NULL;
//     } 
    
//     while (current->next != NULL)
//     {
//         if(current->val == current->next->val) {
//             Node* next_next = current->next->next;
//             Node* nodeToDelete = current->next;
            
//             delete(nodeToDelete);

//             current->next = next_next;
//         }
//         else {
//             current = current->next;
//         }
//     }
    
//     return head;
// }


Node* RemoveDuplicatesFromUnsortedList(Node* head) {
    Node* current = head;
    Node* prev = NULL;

    if(current == NULL) {
        std::cout << "Node not created!\n";
        return NULL;
    }

    std::unordered_map<int, int> visited;
    while (current != NULL)
    {
        if(!visited[current->val]) {
            visited[current->val] = 1;

            prev = current;
            current = current->next;
        }
        else {
            Node* nextNode = current->next;
            prev->next = nextNode;

            delete(current);
            current = nextNode;
        }
    }
    
    return head;
}

int main()
{
    Node* head = new Node();
    head = CreateNode(2);
    AddNodeAtEnd(head, 3);
    AddNodeAtEnd(head, 2);
    AddNodeAtEnd(head, 2);
    AddNodeAtEnd(head, 4);
    AddNodeAtEnd(head, 3);
    AddNodeAtEnd(head, 5);
    AddNodeAtEnd(head, 1);
    AddNodeAtEnd(head, 1);

    //head = AddNodeAtStart(head, 33);
    Display(head);

    head = RemoveDuplicatesFromUnsortedList(head);
    std::cout << "\nAfter removing duplicate elements from list, we have -> \n";
    Display(head);

    // Clearing memory
    delete head;
    return 0;
}