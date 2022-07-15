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

void postorderIterative(Node* root) {
    std::stack<Node*> stack;
    stack.push(root);

    while (root != nullptr || !stack.empty()) {
        if(root != nullptr) {
            stack.push(root);
            root = root->left;
        }
        else {
            Node* temp = stack.top()->right;
            if(temp == nullptr) {
                temp = stack.top();
                stack.pop();
                while (!stack.empty() && temp == stack.top()->right) {
                    temp = stack.top();
                    stack.pop();
                    std::cout << temp->data << " ";
                }
            }
            else {
                root = temp;
            }
        }
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
    postorderIterative(root);

    return 0;
}