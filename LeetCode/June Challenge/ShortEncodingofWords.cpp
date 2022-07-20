// Q. https://leetcode.com/problems/short-encoding-of-words/

#include <iostream>
#include <vector>
#include <string>
#include <set>

class Solution {
public:
    int minimumLengthEncoding(std::vector<std::string>& words) {
        // Storing the words in a set which stores unique values
        std::set<std::string> str (words.begin(), words.end());
        int len = 0;

        // iterating each words
        for (auto& word : words)
        {
            // time -> me -> bell
            for (int j = 1; j < word.size(); j++)
            {
                // ime -> me -> e // find substrings from each word, and remove the word from the set
                str.erase(word.substr(j));
            }
        }
        
        // calculating length // we have to add # for each word, so add a extra +1 length for that
        for(auto& i : str) {
            len += i.length() + 1;
        }

        return len;
    }
};



int main()
{
    //std::vector<std::string> words {"time", "me", "bell"}; // 10
    std::vector<std::string> words {"t"}; // 2

    Solution sol;
    std::cout << sol.minimumLengthEncoding(words);
    return 0;
}