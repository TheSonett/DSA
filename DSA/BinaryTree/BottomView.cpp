#include <iostream>
#include <vector>
#include <queue>
#include <map>

struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution {
  public:
    std::vector<int> bottomView(Node *root) {
        std::vector<int> ans;
        
        if(root == NULL) {
            return ans;
        }
        
        std::map<int, int> map;
        std::queue<std::pair<Node*, int>> queue;
        
        queue.push(std::make_pair(root, 0));
        
        while(!queue.empty()) {
            std::pair<Node*, int> temp = queue.front();
            queue.pop();
            
            int horizontalValue = temp.second;
            Node* node = temp.first;
            
            map[horizontalValue] = node->data;
            
            if(node->left) {
                queue.push(std::make_pair(node->left, horizontalValue-1));
            }
            
            if(node->right) {
                queue.push(std::make_pair(node->right, horizontalValue+1));
            }
        }
        
        for(auto i : map) {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};