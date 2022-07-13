// Q. https://leetcode.com/problems/longest-palindromic-substring/

// NOTE: It is LeetCode's Medium level Dynamic Programming Problem

#include <iostream>
#include <cmath>
#include <string>

std::string longestPalindrome(std::string s) {
    int low, high;
    int start = 0, end = 1; // for taking out the substring


    std::string substring = "";

    for (int i = 1; i < s.length(); i++)
    {
        // for even part
        low = i - 1;
        high = i;

        while(low >= 0 && high < s.length() && s[low] == s[high]) {
            // we have to keep track of the substring we're getting
            if(high - low + 1 > end) {
                start = low;
                end = high - low + 1;
            }

            low--;
            high++;
        }

        // for odd part
        low = i - 1;
        high = i + 1;

        while(low >= 0 && high < s.length() && s[low] == s[high]) {
            // we have to keep track of the substring we're getting
            if(high - low + 1 > end) {
                start = low;
                end = high - low + 1;
            }

            low--;
            high++;
        }
    }
    
    for (int i = start; i <= start+end-1; i++)
    {
        substring.push_back(s[i]);
    }
    
    return substring;
}


int main() 
{
    std::string s = "cbbd";
    std::string result = longestPalindrome(s);

    std::cout << result << std::endl;
    return 0;
}
