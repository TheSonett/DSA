#include <iostream>
#include <vector>

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

int maxHeightOfTree(Node* root) {
    if(root == nullptr) {
        return 0;
    }

    int maxHeightOfLeftNodes = maxHeightOfTree(root->left);
    int maxHeightOfRightNodes = maxHeightOfTree(root->right);

    return std::max(maxHeightOfLeftNodes, maxHeightOfRightNodes) + 1;
}

int main() {
    std::vector<int> nodes {1, 2, 4, -1, -1, 5, -1, 9, -1, -1, 3, -1, 6, -1, -1};

    Node* root = new Node();
    root = buildBinaryTree(nodes);

    int maxHeight = maxHeightOfTree(root);
    std::cout << maxHeight << "\n";

    return 0;
}
