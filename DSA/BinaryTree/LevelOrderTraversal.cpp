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

// void levelOrder(Node* root) {
//     if(root == nullptr) {
//         return;
//     }

//     std::queue<Node*> queue;
//     queue.push(root);
//     queue.push(nullptr);

//     while (!queue.empty())
//     {
//         Node* node = queue.front();
//         queue.pop();

//         if(node == nullptr) {
//             printf("\n");
//             if(queue.empty()) {
//                 break;
//             }
//             else {
//                 queue.push(nullptr);
//             }
//         }
//         else {
//             std::cout << node->data << " ";
            
//             if(node->left != nullptr) {
//                 queue.push(node->left);
//             }

//             if(node->right != nullptr) {
//                 queue.push(node->right);
//             }
//         }

//     }
// }

std::vector<std::vector<int>> levelOrder(Node* root) {
    std::vector<std::vector<int>> ans{};
    if(root == nullptr) {
        return ans;
    }

    std::queue<Node*> queue;
    queue.push(root);
    queue.push(nullptr);

    while (!queue.empty())
    {
        std::vector<int> level{};

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
            //std::cout << node->data << " ";
            if(node->left != nullptr) {
                queue.push(node->left);
            }

            if(node->right != nullptr) {
                queue.push(node->right);
            }

            level.push_back(node->data);
        }

        ans.push_back(level);
    }

    return ans;
}

int main() {
    // -1 are basically for null nodes
    std::vector<int> nodes {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    //std::vector<int> nodes {1, 2, 3, -1, -1, 4, 5, -1, -1, 6, -1, -1, 7, -1, -1};
    //std::vector<int> nodes {3, 9, 20, -1, -1, 15, 7};

    // Creating a node
    Node* root = new Node();
    root = buildBinaryTree(nodes);

    // Level Order
    std::vector<std::vector<int>> ans = levelOrder(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            std::cout << ans[i][j] << " ";   
        }
        std::cout << "--";        
    }

    return 0;
}