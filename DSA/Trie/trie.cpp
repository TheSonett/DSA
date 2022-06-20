#include <iostream>
#include <string>
#include <cstring>

// TODO: Not giving correct ans

class TrieNode {
    public:
        char data;
        TrieNode* children[26]; // Every node can have 26 childrens
        bool isTerminalNode;
    public:
        TrieNode(char data) {
            this->data = data;
            for (int i = 0; i < 26; i++)
            {
                children[i] = NULL;
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
            // If reached the destination & mark it as terminal node, then return
            if(word.length() == 0) {
                root->isTerminalNode = true;
                return;
            }

            // map the character to particular index
            int index = word[0] - 'a';
            TrieNode* child;

            // check if the character is present or not
            // is present
            if(root->children[index] != NULL) {
                child = root->children[index];
            }
            else {
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            insert(word.substr(1));
        }
        
        bool search(std::string word) {
            if(word.length() ==  0) {
                return root->isTerminalNode;
            }

            int index = word[0] - 'a';
            TrieNode* child;

            // present
            if(root->children[index] != NULL) {
                child = root->children[index];
            }
            else {
                // absent
                return false;
            }

            return search(word.substr(1));
        }
        
        bool startsWith(std::string prefix) {
            if(prefix.length() ==  0) {
                return true;
            }

            int index = prefix[0] - 'a';
            TrieNode* child;

            // present
            if(root->children[index] != NULL) {
                child = root->children[index];
            }
            else {
                // absent
                return false;
            }

            return startsWith(prefix.substr(1));
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