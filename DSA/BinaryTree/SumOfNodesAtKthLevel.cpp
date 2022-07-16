#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

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

static int index = -1;
Node* buildBinaryTree(std::vector<int>& nodes) {
    index++;

    if(nodes[index] == -1) {
        return nullptr;
    }

    Node* newNode = new Node((nodes[index]));
    newNode->left = buildBinaryTree(nodes);
    newNode->right = buildBinaryTree(nodes);

    return newNode;
}

int sumOfKthLevel(Node* root, int k) {
    if(root == nullptr) {
        return -1;
    }

    std::queue<Node*> queue;
    queue.push(root);
    queue.push(nullptr);

    int n = 1;
    int sum = 0;

    while (!queue.empty())
    {
        Node* node = queue.front();
        queue.pop();

        if(node == nullptr) {
            if(queue.empty()) {
                break;
            }
            else {
                n++;
                queue.push(nullptr);
            }
        }
        else {
            if(n == k) {
                sum += node->data;
            }
            
            if(node->left != nullptr) {
                queue.push(node->left);
            }

            if(node->right != nullptr) {
                queue.push(node->right);
            }
        }
    }

    return sum;
}

int main() {
    std::vector<int> nodes {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int k = 3;

    Node* root = new Node();
    root = buildBinaryTree(nodes);

    // printing the sum of nodes at kth level
    std::cout << sumOfKthLevel(root, k);


    return 0;
}