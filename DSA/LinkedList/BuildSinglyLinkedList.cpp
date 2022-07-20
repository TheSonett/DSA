#include <iostream>
#include <cstdlib>


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

int main()
{
    Node* head = new Node();
    head = CreateNode(10);
    AddNodeAtEnd(head, 20);
    AddNodeAtEnd(head, 30);

    head = AddNodeAtStart(head, 33);
    Display(head);


    std::cout << "Number of nodes: " << NumberOfNodes(head) << std::endl;


    // Clearing memory
    delete head;
    return 0;
}