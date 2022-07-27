// Q. https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Q. https://practice.geeksforgeeks.org/problems/construct-tree-1/1/
// 105. Construct Binary Tree from Preorder and In-order Traversal


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
        // TC -> O(n^2)
        // int findPosition(int inorder[], int& element, int& n) {
        //     for (int i = 0; i < n; i++)
        //     {
        //         if (inorder[i] == element) {
        //             return i;
        //             break;
        //         }
        //     }

        //     return -1;
        // }


        Node* solve(std::vector<int>& in, std::vector<int>& pre, int& preorderIndex, int inorderStartIndex, int inorderEndIndex, int n) {
            if (preorderIndex >= n || inorderStartIndex > inorderEndIndex) {
                return nullptr;
            }

            int element = pre[preorderIndex++];
            Node* node = new Node(element);
            // TC -> O(1)
            int position = hashmap[element];

            // recursive calls
            node->left = solve(in, pre, preorderIndex, inorderStartIndex, position - 1, n);
            node->right = solve(in, pre, preorderIndex, position + 1, inorderEndIndex, n);

            return node;
        }


        Node* buildTree(std::vector<int>& in, std::vector<int> pre, int n)
        {
            int preorderIndex = 0;
            int inorderStartIndex = 0;
            int inorderEndIndex = n - 1;

            // TC -> inserting in map is O(1)
            for(int i = 0; i < sizeof(in); i++) {
                hashmap[in[i]] = i;
            }
            

            Node* answer = solve(in, pre, preorderIndex, inorderStartIndex, inorderEndIndex, n);
            return answer;
        }
};

void postorder(Node* root) {
    if(root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}


int main()
{
    Solution obj;

    std::vector<int> in {1, 6, 8, 7};
    std::vector<int> pre {1, 6, 7, 8};

    Node* root = obj.buildTree(in, pre, in.size());
    postorder(root); // 8 7 6 1

    return 0;
}