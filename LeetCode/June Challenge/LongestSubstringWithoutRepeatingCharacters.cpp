// Q. https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <cstring>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> freq;

    int i = 0;
    int j = 0;
    int count = 0;

    while (j < s.size())
    {
        freq[s[j]]++;

        // repeated character found
        while (freq[s[j]] != 1)
        {
            freq[s[i]]--;
            i++;
        }
        
        count = std::max(count, j - i + 1);

        j++;
    }
    return count;

}

int main()
{
    std::string s = "bbbbb";
    int result = lengthOfLongestSubstring(s);

    std::cout << result;
    return 0;
}