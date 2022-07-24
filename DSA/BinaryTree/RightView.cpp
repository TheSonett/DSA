#include <iostream>
#include <vector>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void solve(Node* root, std::vector<int>& ans, int level) {
    if(root == NULL) {
        return;
    }
    
    if(level == ans.size()) {
        ans.push_back(root->data);
    }
    
    // right subtree should be first
    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);
}

std::vector<int> leftView(Node *root)
{
   std::vector<int> ans;
   int level = 0;
   
   solve(root, ans, level);
   return ans;
}
