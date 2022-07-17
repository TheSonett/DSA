#include <iostream>
#include <vector>

class Node {
    public:
        int val;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(int val) {
            this->val = val;
        }
};

Node* buildBST(Node* root, int val) {
    if(root == nullptr) {
        root = new Node(val);
        return root;
    }

    if(root->val > val) {
        // go to left subtree
        root->left = buildBST(root->left, val);
    }
    else if(root->val <= val) {
        // go to right subtree
        root->right = buildBST(root->right, val);
    }

    return root;
}

void inorder(Node* root) {
    if(root == nullptr) {
        return;
    }

    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}

void printInRange(Node* root, int X, int Y) {
    if(root == nullptr) {
        return;
    }

    if(X <= root->val && Y >= root->val) {
        printInRange(root->left, X, Y);
        std::cout << root->val << " ";
        printInRange(root->right, X, Y);
    }
    else if(Y > root->val) {
        printInRange(root->right, X, Y);
    }
    else if(X < root->val) {
        printInRange(root->left, X, Y);
    }
}


int main()
{
    std::vector<int> nodes {8, 5, 3, 6, 10, 11, 14};
    Node* root = nullptr;

    for(int i = 0; i < nodes.size(); i++) {
        root = buildBST(root, nodes[i]);
    }

    inorder(root);
    printf("\n");

    printInRange(root, 5, 10);


    return 0;
}