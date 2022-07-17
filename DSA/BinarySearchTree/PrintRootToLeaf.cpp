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

void printPath(std::vector<int>* path) {
    for (int i = 0; i < path->size(); i++)
    {
        std::cout << path->at(i) << "->";
    }
    std::cout << std::endl;
}

void printInRange(Node* root, std::vector<int>* path) {
    if(root == nullptr) {
        return;
    }

    path->push_back(root->val);

    // leaf node
    if(root->left == nullptr && root->right == nullptr) {
        printPath(path);
    }
    else { // non-leaf nodes
        printInRange(root->left, path);
        printInRange(root->right, path);
    }

    path->pop_back();
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
    printInRange(root, new std::vector<int>{});
    return 0;
}