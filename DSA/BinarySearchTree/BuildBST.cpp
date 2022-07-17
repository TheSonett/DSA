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

int main()
{
    std::vector<int> nodes {3, 4, 2, 7, 5, 1, 6};
    Node* root = nullptr;

    for(int i = 0; i < nodes.size(); i++) {
        root = buildBST(root, nodes[i]);
    }

    inorder(root);
    return 0;
}