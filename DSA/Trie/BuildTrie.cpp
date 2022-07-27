#include <iostream>
#include <vector>
#include <algorithm>

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminalNode;

        TrieNode(char data) {
            this->data = data;
            for(int i = 0; i < 26; i++) { children[i] = NULL; }
            isTerminalNode = false;
        }
};

class Trie {
    private:
        void insertWord(TrieNode* root, std::string word) {
            // base case 
            // We have traversed all the characters of that word. So make last char as terminal node
            if(word.size() == 0) {
                root->isTerminalNode = true;
                return;
            }

            // character mapping
            int index = word[0] - 'A';
            TrieNode* child;

            // character already present
            if(root->children[index] != NULL) {
                // just move forward
                child = root->children[index];
            }
            else {
                // absent
                // So first create node, then move forward
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            // recursion call
            insertWord(child, word.substr(1));
        }

        bool searchWord(TrieNode* root, std::string word) {
            // base case
            if(word.size() == 0) {
                return root->isTerminalNode;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL) {
                child = root->children[index];
            }
            else {
                //absent
                return false;
            }

            return searchWord(child, word.substr(1));
        }

        void removeWord(TrieNode* root, std::string word) {
            if(word.size() == 0) {
                root->isTerminalNode = false;
                return;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL) {
                child = root->children[index];
            }
            else {
                // absent
                std::cout << "Word not found!! Unable to delete!!\n";
                return;
            }

            removeWord(child, word.substr(1));
        }
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode('\0');
        }

         // Insertion
        void insert(std::string word) {
            insertWord(root, word);
        }

        // Searching
        bool search(std::string word) {
            return searchWord(root, word);
        }

        // Deletion
        void remove(std::string word) {
            removeWord(root, word);
        }
};

int main()
{
    Trie trie;
    trie.insert("ABCDE");
    trie.insert("TIME");
    trie.insert("TIM");

    std::cout << trie.search("TIM") << "\n";
    trie.remove("XX");
    std::cout << trie.search("TIM") << "\n";
    return 0;
}



// Q. https://www.codingninjas.com/codestudio/problems/implement-trie_631356
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

// class TrieNode {
//     public:
//         char data;
//         TrieNode* children[26];
//         bool isTerminalNode;

//         TrieNode(char data) {
//             this->data = data;
//             for(int i = 0; i < 26; i++) { children[i] = NULL; }
//             isTerminalNode = false;
//         }
// };

// class Trie {
//     private:
//         void insertWord(TrieNode* root, std::string word) {
//             // base case 
//             // We have traversed all the characters of that word. So make last char as terminal node
//             if(word.size() == 0) {
//                 root->isTerminalNode = true;
//                 return;
//             }

//             // character mapping
//             int index = word[0] - 'a';
//             TrieNode* child;

//             // character already present
//             if(root->children[index] != NULL) {
//                 // just move forward
//                 child = root->children[index];
//             }
//             else {
//                 // absent
//                 // So first create node, then move forward
//                 child = new TrieNode(word[0]);
//                 root->children[index] = child;
//             }

//             // recursion call
//             insertWord(child, word.substr(1));
//         }

//         bool searchWord(TrieNode* root, std::string word) {
//             // base case
//             if(word.size() == 0) {
//                 return root->isTerminalNode;
//             }

//             int index = word[0] - 'a';
//             TrieNode* child;

//             if(root->children[index] != NULL) {
//                 child = root->children[index];
//             }
//             else {
//                 //absent
//                 return false;
//             }

//             return searchWord(child, word.substr(1));
//         }
    
//         bool prefixWord(TrieNode* root, std::string prefix) {
//             // base case
//             if(prefix.size() == 0) {
//                 return true;
//             }

//             int index = prefix[0] - 'a';
//             TrieNode* child;

//             if(root->children[index] != NULL) {
//                 child = root->children[index];
//             }
//             else {
//                 //absent
//                 return false;
//             }

//             return prefixWord(child, prefix.substr(1));
//         }

//         void removeWord(TrieNode* root, std::string word) {
//             if(word.size() == 0) {
//                 root->isTerminalNode = false;
//                 return;
//             }

//             int index = word[0] - 'a';
//             TrieNode* child;

//             if(root->children[index] != NULL) {
//                 child = root->children[index];
//             }
//             else {
//                 // absent
//                 std::cout << "Word not found!! Unable to delete!!\n";
//                 return;
//             }

//             removeWord(child, word.substr(1));
//         }
// public:

//     /** Initialize your data structure here. */
//     TrieNode* root;
//     Trie() {
//         root = new TrieNode('\0');
//     }

//     /** Inserts a word into the trie. */
//     void insert(std::string word) {
//         insertWord(root, word);
//     }

//     /** Returns if the word is in the trie. */
//     bool search(string word) {
//         return searchWord(root, word);
//     }

//     /** Returns if there is any word in the trie that starts with the given prefix. */
//     bool startsWith(string prefix) {
//         return prefixWord(root, prefix);
//     }
// };