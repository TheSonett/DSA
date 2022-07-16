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

void levelOrder(Node* root) {
    if(root == nullptr) {
        return;
    }

    std::queue<Node*> queue;
    queue.push(root);
    queue.push(nullptr);

    while (!queue.empty())
    {
        Node* node = queue.front();
        queue.pop();

        if(node == nullptr) {
            printf("\n");
            if(queue.empty()) {
                break;
            }
            else {
                queue.push(nullptr);
            }
        }
        else {
            std::cout << node->data << " ";
            
            if(node->left != nullptr) {
                queue.push(node->left);
            }

            if(node->right != nullptr) {
                queue.push(node->right);
            }
        }

    }
}

bool isIdenticalTree(Node* root, Node* subRoot) {
    if(root == nullptr && subRoot == nullptr) {
        return true;
    }

    if(root == nullptr || subRoot == nullptr) {
        return false;
    }

    if(root->data == subRoot->data) {
        return isIdenticalTree(root->left, subRoot->left) && isIdenticalTree(root->right, subRoot->right);
    }

    return false;
}

bool isSubtree(Node* root, Node* subRoot) {
    if(root == nullptr) {
        return false;
    }

    if(subRoot == nullptr) {
        return true;
    }

    if(root->data == subRoot->data) {
        if(isIdenticalTree(root, subRoot)) {
            return true;
        }
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
    std::vector<int> nodes {9, 7, 8, -1, -1, 1, 2, -1, -1, 8, -1, -1, 4, 5, -1, -1, 6, -1, -1};
    std::vector<int> subtree {1, 2, -1, -1, 8, -1, -1};

    Node* root = new Node();
    root = buildBinaryTree(nodes);

    Node* subRoot = new Node();
    subRoot = buildBinaryTree(subtree);

    // Level Order
    levelOrder(subRoot);

    // subtree of a another tree
    std::cout << isSubtree(root, subRoot);
    

    return 0;
}