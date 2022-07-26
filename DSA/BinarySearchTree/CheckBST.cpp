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


bool isSubstreeLesser(Node* root, int val) {
    if(root == NULL) {
        return true;
    }

    if(root->val <= val && 
       isSubstreeLesser(root->left, val) && 
       isSubstreeLesser(root->right, val)) {
        return true;
    }
    return false;
}

bool isSubstreeGreater(Node* root, int val) {
    if(root == NULL) {
        return true;
    }

    if(root->val > val && 
       isSubstreeGreater(root->left, val) && 
       isSubstreeGreater(root->right, val)) {
        return true;
    }
    return false;
}

bool isBST(Node* root) {
    if(root == NULL) {
        return true;
    }

    if(isSubstreeLesser(root->left, root->val) && 
       isSubstreeGreater(root->right, root->val) &&
       isBST(root->left) &&
       isBST(root->right)) {
        return true;
    }
    return false;
}

int main()
{
    std::vector<int> nodes {20, 20, 78, 98, 99, 97};
    Node* root = nullptr;

    for(int i = 0; i < nodes.size(); i++) {
        root = buildBST(root, nodes[i]);
    }

    std::cout << isBST(root);
    
    return 0;
}