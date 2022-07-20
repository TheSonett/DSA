// Q. https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

#include <iostream>
#include <string>
#include <algorithm>

std::string removeOccurrences(std::string s, std::string part)
{
    std::string result = "";

    for (int i = 0; i < s.length(); i++)
    {
        result.push_back(s[i]);

        if(result.size() >= part.size() && result.substr(result.size() - part.size()) == part) {
            int size = part.size();
            while (size != 0)
            {
                result.pop_back();
                size--;
            }
            
        }
    }
    
    return result;
}

int main() {
    std::string s = "daabcbaabcbc";
    std::string part = "abc";

    std::cout << removeOccurrences(s, part); // "dab"
    return 0;
}