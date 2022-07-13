// Q. https://leetcode.com/problems/valid-palindrome/

#include <iostream>
#include <string>
#include <regex>

bool isValidPalindrome(std::string &s)
{
    int left = 0;
    int right = s.size() - 1;

    while (right > left)
    {
        // If the first & last element is not equal, then simply return false
        if (s[left] != s[right])
        {
            return false;
        }
        else
        {
            left++;
            right--;
        }
    }
    return true;
}

bool isPalindrome(std::string s)
{
    std::string str = "";

    for (int i = 0; i < s.size(); i++)
    {
        // making all the characters smaller
        s[i] = tolower(s[i]);

        // if there is any numerical value present with the character, add them as well
        if (isalnum(s[i])) {
            str += s[i];
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (isValidPalindrome(str))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::string s = "0P";
    if (isPalindrome(s))
    {
        std::cout << "Palindrome!" << std::endl;
    }
    else
    {
        std::cout << "Not a Palindrome!" << std::endl;
    }
    return 0;
}