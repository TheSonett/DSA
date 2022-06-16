// Q. https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
// LCS Problem -> Important

// Recursive Approach -> Top Down Approach
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>

int lcs(int x, int y, std::string s1, std::string s2, std::vector<std::vector<int>>& dp)
{
    if(x == 0 || y == 0) {
        return 0;
    }

    if(dp[x][y] != -1) {
        return dp[x][y];
    }

    if(s1[x-1] == s2[y-1]) {
        return dp[x][y] = 1 + lcs(x-1, y-1, s1, s2, dp);
    }
    else {
        return dp[x][y] = std::max(lcs(x-1, y, s1, s2, dp), lcs(x, y-1, s1, s2, dp));
    }
}

// Tabulation Approach - Bottom Up approach
int lcs2(int x, int y, std::string s1, std::string s2) {
    std::vector<char> temp{};
    std::vector<std::vector<int>> dp (x + 1, std::vector<int>(y + 1, 0));

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    for (int i = x; i >= 1; i--)
    {
        for (int j = y; j >= 1; j--) {
            if(dp[i][j] != std::max(dp[i][j-1], dp[i-1][j])) {
                temp.push_back(s1[i]);
            }
        }
    }
    
    for (int i = 1; i <= temp.size(); i++)
    {
        std::cout << temp[i] << " ";
    } std::cout << std::endl;
    
    return dp[x][y];
}

int main() {
    std::string s1 = "abcab";
    std::string s2 = "aecb";

    int x = s1.length();
    int y = s2.length();

    std::vector<std::vector<int>> dp(x + 1, std::vector<int>(y + 1));

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            dp[i][j] = -1;
        }
    }
    
    printf("By Recursive Method\n");
    std::cout << lcs(x, y, s1, s2, dp);
    printf("\nBy Tabulation Method\n");
    std::cout << lcs2(x, y, s1, s2);

    return 0;
}


// class Solution
// {
//     public:
//     //Function to find the length of longest common subsequence in two strings.
//     int lcs(int x, int y, std::string s1, std::string s2)
//     {
//         std::vector<std::vector<int>> dp(x + 1, std::vector<int>(y + 1));
    
//         for (int i = 1; i <= x; i++)
//         {
//             for (int j = 1; j <= y; j++)
//             {
//                 dp[i][j] = -1;
//             }
//         }
        
//         return solve(x, y, s1, s2, dp);
//     }
    
//     int solve(int x, int y, std::string s1, std::string s2, std::vector<std::vector<int>>& dp) {
//         if(x == 0 || y == 0) {
//             return 0;
//         }
    
//         if(dp[x][y] != -1) {
//             return dp[x][y];
//         }
    
//         if(s1[x-1] == s2[y-1]) {
//             return dp[x][y] = 1 + solve(x-1, y-1, s1, s2, dp);
//         }
//         else {
//             return dp[x][y] = std::max(solve(x-1, y, s1, s2, dp), solve(x, y-1, s1, s2, dp));
//         }
//     }
// };
