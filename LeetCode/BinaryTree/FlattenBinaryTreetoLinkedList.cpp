// Q. https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// 114. Flatten Binary Tree to Linked List

#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC -> O(n)
// SC -> O(1)
void flatten(TreeNode* root) {
    if(root == nullptr) {
        return;
    }

    TreeNode* current = root;
    while (current != nullptr)
    {
        // find predecessor
        if(current->left != nullptr) {
            TreeNode* predecessor = current->left;
            while (predecessor->right != nullptr) {
                predecessor = predecessor->right;
            }
            
            // linking
            predecessor->right = current->right;
            current->right = current->left;
            current->left = nullptr;
        }

        // if left doesn't exists, then move forward to right
        current = current->right;
    }
    // left part null
    current = root;
    while(current != nullptr) {
        current->left = nullptr;
        current = current->right;
    }

    // printing
    while(root != nullptr) {
        std::cout << root->val << " ";
        root = root->right;
    }
}

static int index = -1;
TreeNode* buildBinaryTree(std::vector<int>& nodes) {
    index++;

    if(nodes[index] == -1) {
        return nullptr;
    }

    TreeNode* newNode = new TreeNode((nodes[index]));
    newNode->left = buildBinaryTree(nodes);
    newNode->right = buildBinaryTree(nodes);

    return newNode;
}


int main() {
    std::vector<int> nodes = {1, 2, 3, -1, -1, 4, -1, -1, 5, -1, 6, -1, -1};
    TreeNode* root = buildBinaryTree(nodes);

    flatten(root);

    return 0;
}