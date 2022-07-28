#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

// brute force approach
// TC -> O(nlogn)
// SC -> O(n)
bool isAnagram(std::string s, std::string t) {
    std::vector<char> str1{};
    std::vector<char> str2{};

    for(int i = 0; s[i] != '\0'; i++) {
        str1.push_back(s[i]);
    }

    for(int i = 0; t[i] != '\0'; i++) {
        str2.push_back(t[i]);
    }

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    if(str1.size() != str2.size()) {
        return false;
    }
    
    for(int i = 0; i < str1.size(); i++) {
        if(str1[i] != str2[i]) {
            return false;
        }
    }
    return true;

    // You can also do like this ->
    // std::sort(s.begin(), s.end());
    // std::sort(t.begin(), t.end());
    // return s == t;
}

// Better approach
// TC -> O(N)
// SC -> O(N)
bool isAnagram(std::string s, std::string t) {
    if(s.size() != t.size()) {
        return false;
    }

    std::unordered_map<char, int> hashmap;
    for(int i = 0; s[i] != '\0'; i++) {
        hashmap[s[i]]++;
    }

    for(int i = 0; i < t.size(); i++) {
        // if we found, the reduce the frequency of that character
        if(hashmap.find(t[i]) != hashmap.end()) {
            hashmap[t[i]]--;
        }
    }

    for(auto i : hashmap) {
        if(i.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string s = "anagram";
    std::string t = "nagaram";

    if(isAnagram(s, t)) {
        std::cout << "true\n";
    }
    else {
        std::cout << "false\n";
    }

    return 0;
}