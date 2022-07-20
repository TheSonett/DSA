// Construct Binary Tree from Postorder and In-order Traversal

#include <iostream>
#include <vector>
#include <unordered_map>

// TC -> O(nlogn)
// SC -> O(n^2)

struct Node
{
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int data) {
        this->data = data;
    }
};


class Solution {
    private:
        std::unordered_map<int, int> hashmap;
    public:
        Node* solve(std::vector<int>& in, std::vector<int>& post, int& postorderIndex, int inorderStartIndex, int inorderEndIndex, int n) {
            if (postorderIndex < 0 || inorderStartIndex > inorderEndIndex) {
                return nullptr;
            }

            int element = post[postorderIndex--];
            Node* node = new Node(element);
            // TC -> O(1)
            int position = hashmap[element];

            // recursive calls (In postorder, right subtree builds first, then left)
            node->right = solve(in, post, postorderIndex, position + 1, inorderEndIndex, n);
            node->left = solve(in, post, postorderIndex, inorderStartIndex, position - 1, n);

            return node;
        }


        Node* buildTree(std::vector<int>& in, std::vector<int> post, int n)
        {
            int postorderIndex = n-1;
            int inorderStartIndex = 0;
            int inorderEndIndex = n - 1;

            // TC -> inserting in map is O(logn)
            for(int i = 0; i < n; i++) {
                hashmap[in[i]] = i;
            }
            
            Node* answer = solve(in, post, postorderIndex, inorderStartIndex, inorderEndIndex, n);
            return answer;
        }
};

void preorder(Node* root) {
    if(root == nullptr) {
        return;
    }

    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


int main()
{
    Solution obj;

    std::vector<int> in {4, 8, 2, 5, 1, 6, 3, 7};
    std::vector<int> post {8, 4, 5, 2, 6, 7, 3, 1};

    Node* root = obj.buildTree(in, post, in.size());
    preorder(root); // 1 2 4 8 5 3 6 7

    return 0;
}