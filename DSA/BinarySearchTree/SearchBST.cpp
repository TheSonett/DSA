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

// TC -> O(H)
bool searchKey(Node* root, int val) {
    if(root == nullptr) {
        return false;
    }

    if(root->val == val) {
        return true;
    }

    if(root->val > val) {
        // search on left subtree only
        return searchKey(root->left, val);
    }
    else if(root->val < val) {
        // search on right subtree only
        return searchKey(root->right, val);
    }

    return false;
}

int main() {
    std::vector<int> nodes {3, 4, 2, 7, 5, 6};
    Node* root = nullptr;

    for(int i = 0; i < nodes.size(); i++) {
        root = buildBST(root, nodes[i]);
    }

    if(searchKey(root, 3)) {
        std::cout << "Found!\n";
    }
    else {
        std::cout << "Not Found!\n";
    }


    return 0;
}