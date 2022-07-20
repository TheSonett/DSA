// Q. https://leetcode.com/problems/roman-to-integer/

// Note: 1. if first character is smaller than the second one, then first character should be converted into negative
//       2. then if second character is bigger than the third one, then we're gonna add with the first number -> (- first + second)

// So, largest to smallest : add them up
//     smallest to largest : subtract smaller

// Example: CMXCVIII
// -100 + 1000 -> 900 - 10 -> 890 + 100 -> 990 + 8 -> 998 (Ans)


#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int result = 0;

        for (int i = 0; i < s.length(); i++)
        {
            // first check if i+1 is outside the bound or not. If not then we're okay and check if the character has less value than the next value.
            // If so, then subtract it from result. But If it's has larger value than the next one, just add to the result. that's it!
            if (i + 1 < s.length() && roman[s[i]] < roman[s[i+1]]) {
                result -= roman[s[i]];
            } 
            else {
                result += roman[s[i]];
            }
        }
        
        return result;
    }
};

int main()
{
    Solution obj;

    std::string str;
    std::cout << "Enter a roman string: ";
    std::cin >> str;

    std::cout << obj.romanToInt(str);
    return 0;
}