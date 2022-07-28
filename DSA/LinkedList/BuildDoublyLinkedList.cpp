#include <iostream>
#include <vector>
#include <algorithm>

class Node {
    public:
        Node* prev;
        int data;
        Node* next;

        Node(int data) {
            this->prev = NULL;
            this->data = data;
            this->next = NULL;
        }
};

Node* insertAtEnd(Node* head, int data) {
    if(head == NULL) {
        head = new Node(data);
        return head;
    }

    Node* temp = new Node(data);
    Node* ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->prev = ptr;

    return head;
}

Node* insertAtBeg(Node* head, int data) {
    if(head == NULL) {
        head = new Node(data);
        return head;
    }

    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;

    return head;
}

Node* insertToPosition(Node* head, int data, int position) {
    if(head == NULL) {
        std::cout << "There is no node!\n";
        return head;
    }

    Node* temp = head;
    Node* newNode = new Node(data);

    while(position != 2) {
        temp = temp->next;
        position--;
    }

    Node* temp2 = temp->next;
    temp->next = newNode;
    newNode->prev = temp;

    newNode->next = temp2;
    temp2->prev = newNode;

    return head;
}

void deleteNodeFromEnd(Node* head) {
    if(head == NULL) {
        std::cout << "There is nothing to delete!\n";
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    Node* temp2 = temp->prev;

    temp2->next = NULL;
    delete(temp);
    temp = NULL;
}


void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }std::cout << std::endl;
}

int main()
{
    Node* head = new Node(10);

    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtBeg(head, 22);
    printList(head);

    head = insertToPosition(head, 66, 2);
    printList(head);
    //deleteNodeFromEnd(head);
    //printList(head);
    return 0;
}