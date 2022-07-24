#include <iostream>
#include <vector>
#include <queue>

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node() {}
        ~Node() {}

        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

std::vector<int> diagonal(Node *root)
{
   std::vector<int> ans;
   if(root == NULL) {
       return ans;
   }
   
   std::queue<Node*> queue;
   queue.push(root);
   
   while(!queue.empty()) {
       Node* temp = queue.front();
       queue.pop();
       
       ans.push_back(temp->data);
       
       while(temp != NULL) {
            if(temp->left) {
               queue.push(temp->left);
            }
            
            temp = temp->right;
            
            if(temp != NULL) {
                ans.push_back(temp->data);
            }
       }
   }
   
   return ans;
}