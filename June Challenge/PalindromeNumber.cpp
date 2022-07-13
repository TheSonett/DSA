// Q. https://leetcode.com/problems/palindrome-number/

// Learned: Remember always store your result in a large range of variables like "long long". Otherwise It will give you a runtime error!

#include <iostream>
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long long result = 0;

        while(x > 0) {
            // getting last element
            int rem = x % 10;
            // storing in reverse order
            result = (result * 10) + rem;
            // removing the last element
            x /= 10;
        }

        if(temp == result) {
            return true;
        }
        else {
            return false;
        }
    }
};


int main()
{
    Solution obj;

    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if(obj.isPalindrome(num)) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
    return 0;
}
