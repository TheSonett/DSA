// Q. https://leetcode.com/problems/delete-operation-for-two-strings/

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>


class Solution {
public:
    int LCS(std::string& X, std::string& Y, int n1, int n2) {
        int matrix[n1 + 1][n2 + 1];  // +1 for storing 0 extra space

        // filling up the 0 first
        for (int i = 0; i < n1 + 1; i++)
        {
            for (int j = 0; j < n2 + 1; j++)
            {
                if(i == 0 || j == 0) {
                    matrix[i][j] = 0;
                }
            }
            
        }

        // longest common subsequence calculation
        for (int i = 1; i < n1 + 1; i++)
        {
            for (int j = 1; j < n2 + 1; j++)
            {
                if(X[i - 1] == Y[j - 1]) {
                    matrix[i][j] = 1 + matrix[i - 1][j - 1];
                }
                else {
                    matrix[i][j] = std::max(matrix[i][j - 1], matrix[i - 1][j]);
                }
            }
        }
        
        //return matrix[n1][n2];
        return n1 - matrix[n1][n2] + n2 - matrix[n1][n2];
    }

    int minDistance(std::string word1, std::string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        //long long result = n1 + n2 - (2 * LCS(word1, word2, n1, n2));
        long long result = LCS(word1, word2, n1, n2);
        return result;
    }
};

int main()
{
    Solution sol;

    std::string word1 = "sea";
    std::string word2 = "eat";

    std::cout << sol.minDistance(word1, word2);
    return 0;
}