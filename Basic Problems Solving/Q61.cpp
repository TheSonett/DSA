// 61.	WAP to find out Longest palindrome in an array

#include <iostream>
#include <cmath>
#include <array>
#include <algorithm>
#include <string>

#define N 15

int main()
{
    std::array<int, N> nums{2, 1, 2, 1, 2, 1, 2, 3, 4, 5, 4, 5, 4, 2, 1};

    bool dp[N][N];
    int result = 0;

    for (int g = 0; g < nums.size(); g++)
    {
        for (int i = 0, j = g; j < nums.size(); i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = true;
            }
            else if (g == 1)
            {
                if (nums[i] == nums[j])
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }
            else
            {
                if (nums[i] == nums[j] && dp[i + 1][j - 1] == true)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }

            if (dp[i][j])
            {
                result = g + 1;
            }
        }
    }

    std::cout << result;

    return 0;
}