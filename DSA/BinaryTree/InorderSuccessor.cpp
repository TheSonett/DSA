// Q. https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/
// Remember: Inorder of a BST gives a sorted node list

// A node's inorder successor is the node with the least value in its right subtree, i.e., its right subtree's leftmost child

#include <iostream>

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* successor = NULL;
        
        if(root == NULL) {
          return successor;
        }
        
        if(x == NULL) {
            return root;
        }
        
        while(root != NULL) {
            if(x->data >= root->data) {
                root = root->right;
            }
            else if(x->data < root->data) {
                successor = root;
                root = root->left;
            }
        }
        
        return successor;
    }
};