// Q. https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <climits>
#include <vector>


// Kadane's Algorithm - O(n) Time Complexity Solution
int maxSubArray(std::vector<int>& nums)
{
    int maxSum = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        currSum += nums[i];

        if(currSum > maxSum) {
            maxSum = currSum;
        }

        if(currSum < 0) {
            currSum = 0;
        }
    }
    
    return maxSum;
}


int main()
{
    std::vector<int> nums = {-2, 1, -3 ,4, -1, 2, 1, -5, 4};
    std::cout << maxSubArray(nums);
    return 0;
}