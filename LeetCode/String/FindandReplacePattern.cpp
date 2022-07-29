// Q. https://leetcode.com/problems/find-and-replace-pattern/
// 890. Find and Replace Pattern

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

// TC -> O(N)
// SC -> O(N)

std::vector<int> foundPattern(std::string& pattern) {
    std::vector<int> ans{};
    if(pattern.size() == 0) {
        return ans;
    }

    std::unordered_map<char, int> hashmap;
    for(int i = 0; i < pattern.size(); i++) {
        if(hashmap.find(pattern[i]) == hashmap.end()) {
            // if not present, then insert into the map
            hashmap.insert({pattern[i], i});

            // insert that value of that key
            ans.push_back(hashmap[pattern[i]]);
        }
        else {
            // if character is already present then insert the same index to result vector
            ans.push_back(hashmap[pattern[i]]);
        }
    }

    return ans;
}


std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words, std::string pattern) {
    std::vector<std::string> ans{};
    std::vector<int> numericalPattern = foundPattern(pattern);

    for(auto i : numericalPattern) {
        std::cout << i << " ";
    }std::cout << std::endl;

    for(int i = 0; i < words.size(); i++) {
        std::vector<int> everyPattern = foundPattern(words[i]);

        if(numericalPattern == everyPattern) {
            ans.push_back(words[i]);
        }
    }

    return ans;
}


int main() {
    std::vector<std::string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    std::string pattern = "abb";

    auto ans = findAndReplacePattern(words, pattern);
    for(std::string i : ans) {
        std::cout << i << " ";
    }

    return 0;
}
