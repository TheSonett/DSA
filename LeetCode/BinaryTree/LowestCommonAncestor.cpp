// Q. https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// 236. Lowest Common Ancestor of a Binary Tree

// Approach:
// If root is null or if root is x or if root is y then return root
// Made a recursion call for both on Left subtree and Right subtree
// If the left subtree recursive call gives a null value that means we haven’t found LCA in the left subtree, which means we found LCA on the right subtree. So we will return right.
// If the right subtree recursive call gives null value, that means we haven’t found LCA on the right subtree, which means we found LCA on the left subtree. So we will return left .
// If both left & right calls give values (not null) that means the root is the LCA.



#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

// TC -> O(n) where n is the number of nodes
// SC -> O(n)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) {
        return root;
    }

    TreeNode* leftSubTree = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightSubTree = lowestCommonAncestor(root->right, p, q);

    if(leftSubTree == NULL) {
        return rightSubTree;
    }
    else if(rightSubTree == NULL) {
        return leftSubTree;
    } 
    else {
        return root;
    }
}

int main()
{
    std::vector<int> nodes = {3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1};
    TreeNode* root = buildBinaryTree(nodes);
    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(1);

    TreeNode* ans = lowestCommonAncestor(root, p, q);
    std::cout << ans->val << std::endl;

    return 0;
}