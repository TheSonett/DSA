// Q. https://leetcode.com/problems/implement-trie-prefix-tree/

// Time complexity:
// startsWith -> O(n) where n is the number of characters in a word
// Insertion -> O(n)
// Searching -> O(n)

// Space complexity:
// startsWith -> O(1)
// Insertion -> O(n)
// Searching -> O(1)

#include <iostream>
#include <string>
#include <cstring>

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminalNode;
    public:
        TrieNode(char data) {
            this->data = data;
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
            
            isTerminalNode = false;
        }
};

class Trie {
    public:
        TrieNode* root;
    public:
        Trie() {
            root = new TrieNode('\0');
        }

        ~Trie() {
            delete root;
        }
        
        void insert(std::string word) {
            TrieNode* current = root;

            for (int i = 0; i < word.length(); i++)
            {
                char c = word.at(i);
                if(current->children[c - 'a'] == nullptr) {
                    current->children[c - 'a'] = new TrieNode(c);
                }

                current = current->children[c - 'a']; // moving down
            }

            current->isTerminalNode = true;
        }
        
        bool search(std::string word) {
            TrieNode* current = findNode(word);

            if(current != nullptr && current->isTerminalNode) {
                return true;
            }
            else {
                return false;
            }
        }
        
        bool startsWith(std::string prefix) {
            if(findNode(prefix) != nullptr) {
                return true;
            }
            else {
                return false;
            }
        }

        // TrieNode* deleteNode(std::string word) {
        //     TrieNode* current = findNode(word);

        //     if(current != nullptr) {
        //         return nullptr;
        //     }
        //     else {
        //         delete(current);
        //         return current;
        //     }

        //     current->isTerminalNode = false;
        // }

    public:
        TrieNode* findNode(std::string word) {
            TrieNode* current = root;
            for (int i = 0; i < word.length(); i++)
            {
                char c = word.at(i);
                if(current->children[c - 'a'] == nullptr) {
                    return nullptr;
                }
                
                current = current->children[c - 'a'];
            }
            return current;
        }
};

int main()
{
    Trie *trie = new Trie();
    trie->insert("abc");
    
    std::cout << trie->search("ab") << std::endl;  // 0
    std::cout << trie->search("abc") << std::endl; // 1

    std::cout << trie->startsWith("ab") << std::endl; // 1
    std::cout << trie->search("abc") << std::endl; // 1

    delete trie;
    return 0;
}