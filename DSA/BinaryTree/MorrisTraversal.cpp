#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node() {}
        ~Node() {}

        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

static int index = -1;
Node* buildBinaryTree(std::vector<int>& nodes) {
    index++;

    if(nodes[index] == -1) {
        return nullptr;
    }

    Node* newNode = new Node((nodes[index]));
    newNode->left = buildBinaryTree(nodes);
    newNode->right = buildBinaryTree(nodes);

    return newNode;
}

void inorder(Node* root) {
    if(root == nullptr) {
        return;
    }

    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

void morris(Node* root) {
    if(root == nullptr) {
        return;
    }

    Node* current = root;

    while(current != nullptr) {
        if(current->left == nullptr) {
            std::cout << current->data << " ";
            current = current->right;
        }
        else {
            Node* predecessor = current->left;
            while(predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if(predecessor->right == nullptr) {
                predecessor->right = current;
                current = current->left;
            }
            else {
                predecessor->right = nullptr;
                std::cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

int main() {
    std::vector<int> nodes = {1, 2, 4, -1, 7, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = new Node();
    root = buildBinaryTree(nodes);

    inorder(root);
    printf("\n");
    morris(root);
    return 0;
}