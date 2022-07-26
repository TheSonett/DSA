// Q. https://leetcode.com/problems/permutation-in-string/
// 567. Permutation in String

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

bool checkEqual(int count1[26], int count2[26]) {
    for (int i = 0; i < 26; i++)
    {
        if(count1[i] != count2[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(std::string s1, std::string s2) {
    // counting the occurrences of s1
    int count1[26] = {0};
    for(int i = 0; i < s1.size(); i++) {
        count1[s1[i] - 'a']++;
    }

    // sliding window of size s1 && counting characters of the first window
    int i = 0;
    int count2[26] = {0};
    while (i < s1.size() && i < s2.size())
    {
        count2[s2[i] - 'a']++;
        i++;
    }

    // check if both counts are qual
    if(checkEqual(count1, count2)) {
        return true;
    }

    // check for rest of window characters
    while (i < s2.size())
    {
        // next character for adding
        count2[s2[i] - 'a']++;

        // removing previous character from window
        count2[s2[i - s1.size()] - 'a']--;

        i++;

        // check if both counts are qual
        if(checkEqual(count1, count2)) {
            return true;
        }
    }

    return false;
}


int main()
{
    std::string s1 = "ab";
    std::string s2 = "eidbaooo";

    if(checkInclusion(s1, s2)) {
        std::cout << "true\n";
    }
    else {
        std::cout << "false\n";
    }
    
    return 0;
}