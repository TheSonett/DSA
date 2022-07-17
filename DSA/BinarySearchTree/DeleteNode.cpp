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

Node* inorderSuccessor(Node* root)
{
    if(root->left != nullptr) {
        root = root->left;
    }

    return root;
}

Node* deleteNode(Node* root, int val) {
    if(root->val > val) {
        root->left = deleteNode(root->left, val);
    }
    else if(root->val < val) {
        root->right = deleteNode(root->right, val);
    }
    else { // root->val == val
        // case 1
        if(root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }

        // case 2
        if(root->left == nullptr) {
            return root->right;
        }

        if(root->right == nullptr) {
            return root->left;
        }

        // case 3
        Node* temp = inorderSuccessor(root);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
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


int main() {
    std::vector<int> nodes {3, 4, 2, 7, 5, 6};
    Node* root = nullptr;

    for(int i = 0; i < nodes.size(); i++) {
        root = buildBST(root, nodes[i]);
    }

    inorder(root);
    printf("\n");
    
    root = deleteNode(root, 7);
    inorder(root);


    return 0;
}