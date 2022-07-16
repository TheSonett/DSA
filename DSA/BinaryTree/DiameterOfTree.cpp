#include <iostream>
#include <vector>
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

int maxHeightOfTree(Node* root) {
    if(root == nullptr) {
        return 0;
    }

    int maxHeightOfLeftNodes = maxHeightOfTree(root->left);
    int maxHeightOfRightNodes = maxHeightOfTree(root->right);

    return std::max(maxHeightOfLeftNodes, maxHeightOfRightNodes) + 1;
}

// TC -> O(n^2)
int diameterOfTree(Node* root) {
    if(root == nullptr) {
        return 0;
    }

    int diameterOfLeft = diameterOfTree(root->left);
    int diameterOfRight = diameterOfTree(root->right);
    int diameterOfLeftRight = maxHeightOfTree(root->left) + maxHeightOfTree(root->right) + 1;

    return std::max({diameterOfLeft, diameterOfRight, diameterOfLeftRight});
}

struct TreeDia {
    int height;
    int diameter;

    TreeDia(int height, int diameter) {
        this->height = height;
        this->diameter = diameter;
    }
};

// TC -> O(n)
TreeDia DiameterOfTree(Node* root) {
    if(root == nullptr) {
        return TreeDia(0, 0);
    }

    // calculate heights of left & right sub-tree
    TreeDia leftSubtree = DiameterOfTree(root->left);
    TreeDia rightSubtree = DiameterOfTree(root->right);
    int maxHeightOfTree = std::max(leftSubtree.height, rightSubtree.height) + 1;

    // calculate the diameters
    int diameterOfLeft = leftSubtree.diameter;
    int diameterOfRight = rightSubtree.diameter;
    int diameterOfLeftRight = leftSubtree.height + rightSubtree.height + 1;
    int totalDiameter = std::max({diameterOfLeft, diameterOfRight, diameterOfLeftRight});

    return TreeDia(maxHeightOfTree, totalDiameter);
}


int main() {
    std::vector<int> nodes {1, 2, 4, -1, -1, 5, -1, 9, -1, -1, 3, -1, 6, -1, -1};

    Node* root = new Node();
    root = buildBinaryTree(nodes);

    // int maxHeight = maxHeightOfTree(root);
    // std::cout << maxHeight << "\n";

    // int diameter = diameterOfTree(root);
    // std::cout << diameter << "\n";

    TreeDia diameter = DiameterOfTree(root);
    std::cout << diameter.diameter << "\n";

    return 0;
}