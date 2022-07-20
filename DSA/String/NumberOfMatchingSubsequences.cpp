#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>


bool isMatchingSubseq(std::string& s, std::string word) {
    int index = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == word[index]) {
            index++;
        }

        if(index == word.size()) {
            return true;
        }
    }

    return false;
}

int numMatchingSubseq(std::string s, std::vector<std::string>& words) {
    std::unordered_map<std::string, int> hashmap;
    int ans = 0;

    for (int i = 0; i < words.size(); i++)
    {
        hashmap[words[i]]++;
    }

    for (auto it : hashmap)
    {
        if(isMatchingSubseq(s, it.first)) {
            ans += it.second;
        }
    }
    
    return ans;
    
}


int main() {
    std::string s = "abcde";
    std::vector<std::string> words {"a","bb","acd","ace"};
    std::cout << numMatchingSubseq(s, words);
    return 0;
}