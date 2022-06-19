// Q. https://leetcode.com/problems/word-break/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::unordered_map<std::string, bool> hashmap;
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        if(s.size() == 0) {
            return true;
        }

        if(hashmap.find(s) != hashmap.end()) {
            return hashmap[s];
        }

        for (int i = 0; i < wordDict.size(); i++) {
            if(s.find(wordDict[i]) == 0) {
                auto suffix = s.substr(wordDict[i].length());

                if(wordBreak(suffix, wordDict) == true) {
                    hashmap[s] = true;
                    return hashmap[s];
                }
            }
        }
        
        hashmap[s] = false;
        return hashmap[s];  
    }
};

int main()
{
    std::vector<std::string> words {"ab", "abc", "cd", "def", "abcd"};
    std::string target = "abcdef"; // true 

    // std::vector<std::string> words {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    // std::string target = "skateboard"; // false

    // std::vector<std::string> words {"a", "p", "ent", "enter", "ot", "o", "t"};
    // std::string target = "enterapotentpot"; // true

    // std::vector<std::string> words {"cats","dog","sand","and","cat"};
    // std::string target = "catsandog"; // false

    Solution obj;

    if(obj.wordBreak(target, words) == true) {
        std::cout << "true";
    }
    else {
        std::cout << "false";
    }
    return 0;
}