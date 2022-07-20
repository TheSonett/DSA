// Q. https://leetcode.com/problems/remove-palindromic-subsequences/

#include <iostream>
#include <cstring>
#include <algorithm>

int removePalindromeSub(std::string s)
{
    int left = 0;
    int right = s.length() - 1;

    while (right > left)
    {
        if(s[left] == s[right]) {
           left++;
           right--;
        }
        else {
            return 2; // if not palindrome
        }
    }

    return 1; // if it is palindrome
}

int main()
{
    std::string s = "abababaaba";
    std::cout << removePalindromeSub(s);
    return 0;
}