// Q. https://leetcode.com/problems/longest-string-chain/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <unordered_set>
#include <vector>

bool checkPossibility(std::string& wordA, std::string& wordB) {
    if(wordA.size() != 1 + wordB.size()) { // wordA must be one length greater than wordB, if not, than simply return false
        return false;
    }
    else {
        int i = 0;
        int j = 0;

        while (i < wordA.size()) // "bdca" -> "bda", so WordA will always be greater
        {
            if(j < wordB.size() && wordA[i] == wordB[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        
        if(i == wordA.size() && j == wordB.size()) {
            return true;
        }
        else {
            return false;
        }
    }
}

// As it is not subsequence, so we have to sort the array of words according to their size in ascending order
static bool makeOrder(std::string& wordA, std::string& wordB) {
    if(wordA.size() < wordB.size()) {
        return true;
    }
    else {
        return false;
    }
}

int longestStrChain(std::vector<std::string>& words) {

    std::sort(words.begin(), words.end(), makeOrder);

    int size = words.size();

    std::vector<int> dp (size, 1);
    int maxNum = 1;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(checkPossibility(words[i], words[j]) && 1 + dp[j] > dp[i]) {
                dp[i] = 1 + dp[j];
            }
        }

        // if(dp[i] > maxNum) {
        //     maxNum = dp[i];
        // }

        maxNum = std::max(maxNum, dp[i]);
    }

    return maxNum;
}


int main()
{
    std::vector<std::string> words {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    std::cout << longestStrChain(words);
    return 0;
}