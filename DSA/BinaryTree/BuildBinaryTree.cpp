#include <iostream>
#include <vector>
#include <stack>

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

// recursive methods
// Time Complexity -> O(n)
// Space Complexity -> O(n)

void preorderRecursive(Node* root) {
    if(root == nullptr) {
        return;
    }

    std::cout << root->data << " ";
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

void inorderRecursive(Node* root) {
    if(root == nullptr) {
        return;
    }

    preorderRecursive(root->left);
    std::cout << root->data << " ";
    preorderRecursive(root->right);
}

void postorderRecursive(Node* root) {
    if(root == nullptr) {
        return;
    }

    preorderRecursive(root->left);
    preorderRecursive(root->right);
    std::cout << root->data << " ";
}


// Iterative method
void preorderIterative(Node* root) {
    std::stack<Node*> stack;
    stack.push(root);

    while (true)
    {
        if(stack.empty()) {
            break;
        }

        root = stack.top();
        stack.pop();

        std::cout << root->data << " ";
        if(root->right != nullptr) {
            stack.push(root->right);
        }

        if(root->left != nullptr) {
            stack.push(root->left);
        }
    }
}

void inorderIterative(Node* root) {
    std::stack<Node*> stack;

    while (root != nullptr || !stack.empty())
    {
        while(root != nullptr) {
            stack.push(root);
            root = root->left;
        }

        root = stack.top();
        stack.pop();

        std::cout << root->data << " ";
        root = root->right;
    }
}


int main() {
    // -1 are basically for null nodes
    std::vector<int> nodes {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    //std::vector<int> nodes {1, 2, 3, -1, -1, 4, 5, -1, -1, 6, -1, -1, 7, -1, -1};


    // Creating a node
    Node* root = new Node();
    root = buildBinaryTree(nodes);

    // Traversals
    preorderIterative(root);
    printf("\n");
    inorderIterative(root);

    return 0;
}