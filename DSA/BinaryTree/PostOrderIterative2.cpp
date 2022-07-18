// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <stack>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node() {}
    ~Node() {}

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

static int index = -1;
Node *buildBinaryTree(std::vector<int> &nodes)
{
    index++;

    if (nodes[index] == -1)
    {
        return nullptr;
    }

    Node *newNode = new Node((nodes[index]));
    newNode->left = buildBinaryTree(nodes);
    newNode->right = buildBinaryTree(nodes);

    return newNode;
}

std::vector<int> postorder(Node *root)
{
    std::vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }

    std::stack<Node *> s1;
    std::stack<Node *> s2;
    s1.push(root);

    while (!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);

        if (root->left != nullptr)
        {
            s1.push(root->left);
        }

        if (root->right != nullptr)
        {
            s1.push(root->right);
        }
    }

    while (!s2.empty())
    {
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    return ans;
}

int main()
{
    std::vector<int> nodes{1, 2, 3, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = new Node();
    root = buildBinaryTree(nodes);

    std::cout << root->data << "\n";

    std::vector<int> ans = postorder(root);
    for(auto i: ans) {
        std::cout << i << " ";
    }

    return 0;
}