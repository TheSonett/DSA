// Q. https://leetcode.com/problems/longest-increasing-subsequence/

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

int lengthOfLIS(std::vector<int>& nums) {
    int size = nums.size();
    std::vector<int> dp (size, 1);

    int maxLength = 1;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(nums[i] > nums[j] && 1 + dp[j] > dp[i]) {
                dp[i] = 1 + dp[j];
            }
        }

        maxLength = std::max(maxLength, dp[i]);
    }
    
    return maxLength;
}

int main()
{
    std::vector<int> nums {10,9,2,5,3,7,101,18};
    std::cout << lengthOfLIS(nums);
    return 0;
}