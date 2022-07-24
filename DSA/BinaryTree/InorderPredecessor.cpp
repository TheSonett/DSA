// Q. https://workat.tech/problem-solving/practice/inorder-predecessor-bst
// In-order predecessor means the right most element of BST
// A node's inorder predecessor is a node with maximum value in its left subtree, i.e., its left subtree's right-most child

#include <iostream>

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int data) {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

Node* findPredecessor(Node* root, Node* p) {
    Node* predecessor = NULL;
	
	if(root == NULL) {
		return predecessor;
	}
	
	if(p == NULL) {
		return root;
	}
	
	while(root != NULL) {
		if(p->data <= root->data) {
			root = root->left;
		}
		else if(p->data > root->data) {
			predecessor = root;
			root = root->right;
		}
	}
	return predecessor;
}