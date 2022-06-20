// Q. https://leetcode.com/problems/implement-trie-prefix-tree/

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
    trie->insert("apple");
    std::cout << trie->search("apple") << std::endl;   // return True
    std::cout << trie->search("app") << std::endl;     // return False
    std::cout << trie->startsWith("app") << std::endl; // return True

    trie->insert("app");
    std::cout << trie->search("app") << std::endl;     // return True
    
    delete trie;
    return 0;
}