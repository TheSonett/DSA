#include <iostream>
#include <vector>
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

// recursive methods
// Time Complexity -> O(n)
// Space Complexity -> O(n)

void preorder(Node* root) {
    if(root == nullptr) {
        return;
    }

    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(root == nullptr) {
        return;
    }

    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}


// Iterative methods
void preorderIterative(Node* root) {
    std::stack<Node*> stack;
    stack.push(root);

    while (!stack.empty())
    {
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

// Two stack approach
// TC -> O(n)
// SC -> O(n)
void postorderIterative(Node* root) {
    if(root == nullptr) {
        return;
    }

    std::stack<Node*> stack1;
    std::stack<Node*> stack2;

    stack1.push(root);
    while (!stack1.empty())
    {
        root = stack1.top();
        stack1.pop();

        stack2.push(root);

        if(root->left != nullptr) {
            stack1.push(root->left);
        }

        if(root->right != nullptr) {
            stack1.push(root->right);
        }
    }

    while (!stack2.empty())
    {
        std::cout << stack2.top()->data << " ";
        stack2.pop();
    }
}

// One Stack Approach
void postorderIterative2(Node* root) {
    if(root == nullptr) {
        return;
    }

    std::stack<Node*> stack;
    std::vector<int> postorder;

    stack.push(root);
    while (!stack.empty())
    {
        postorder.push_back(stack.top()->data);

        root = stack.top();
        stack.pop();

        if(root->left != nullptr) {
            stack.push(root->left);
        }

        if(root->right != nullptr) {
            stack.push(root->right);
        }
    }

    std::for_each(postorder.rbegin(), postorder.rend(), [](int x) {
        std::cout << x << " ";
    });
}


int main() {
    // -1 are basically for null nodes
    //std::vector<int> nodes {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    //std::vector<int> nodes {1, 2, 3, -1, -1, 4, 5, -1, -1, 6, -1, -1, 7, -1, -1};
    std::vector<int> nodes {2, 3, 4, -1, -1, 5, -1, -1, 7, -1, 8, -1, -1};

    // Creating a node
    Node* root = new Node();
    root = buildBinaryTree(nodes);

    // Traversals
    postorderIterative(root);
    printf("\n");
    postorderIterative2(root);

    return 0;
}