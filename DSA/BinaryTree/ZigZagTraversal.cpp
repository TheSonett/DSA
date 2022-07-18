#include <iostream>
#include <vector>
#include <queue>

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

std::vector<std::vector<int>> ZigZag(Node* root) {
    if(root == nullptr) {
        return {};
    }

    Node* node = root;
    std::vector<std::vector<int>> ans{};
    bool LeftToRight = true;

    std::queue<Node*> queue;
    queue.push(node);

    while (!queue.empty())
    {
        int size = queue.size();
        std::vector<int> temp(size);


        for (int i = 0; i < size; i++)
        {
            Node* takeOut = queue.front();
            queue.pop();

            int index = LeftToRight ? i : size - i - 1;
            temp[index] = takeOut->data;
            

            if(takeOut->left != nullptr) {
                queue.push(takeOut->left);
            }

            if(takeOut->right != nullptr) {
                queue.push(takeOut->right);
            }
        }

        // changing the direction
        LeftToRight = !LeftToRight;

        ans.push_back(temp);
    }

    return ans;
}


int main() {
    std::vector<int> nodes {1, 2, 3, -1, -1, 4, -1, -1, 5, -1, 6, -1, -1};

    Node* root = new Node();
    root = buildBinaryTree(nodes);

    std::vector<std::vector<int>> answers = ZigZag(root);
    
    for(auto ans : answers) {
        for (auto i : ans)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}