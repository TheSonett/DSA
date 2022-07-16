// Q. https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Q. https://practice.geeksforgeeks.org/problems/construct-tree-1/1/
// 105. Construct Binary Tree from Preorder and Inorder Traversal


#include <iostream>
#include <vector>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
    }
};


class Solution {
public:
    int findPosition(int inorder[], int& element, int& n) {
        for (int i = 0; i < n; i++)
        {
            if (inorder[i] == element) {
                return i;
                break;
            }
        }

        return -1;
    }


    Node* solve(int in[], int pre[], int& preorderIndex, int inorderStartIndex, int inorderEndIndex, int n) {
        if (preorderIndex >= n || inorderStartIndex > inorderEndIndex) {
            return NULL;
        }

        int element = pre[preorderIndex++];
        Node* node = new Node(element);
        int position = findPosition(in, element, n);

        // recursive calls
        node->left = solve(in, pre, preorderIndex, inorderStartIndex, position - 1, n);
        node->right = solve(in, pre, preorderIndex, position + 1, inorderEndIndex, n);

        return node;
    }


    Node* buildTree(int in[], int pre[], int n)
    {
        int preorderIndex = 0;
        int inorderStartIndex = 0;
        int inorderEndIndex = n - 1;

        Node* answer = solve(in, pre, preorderIndex, inorderStartIndex, inorderEndIndex, n);
        return answer;
    }
};