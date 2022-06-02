// June Challenge - Day1
// Q. https://leetcode.com/problems/running-sum-of-1d-array/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

std::vector<int> runningSum(std::vector<int>& nums) {
    for(int i = 1; i < nums.size(); i++) {
       nums[i] += nums[i-1];
    }

    return nums;
}


int main()
{
    std::vector<int> nums {1, 1, 1, 1, 1};
    std::vector<int> result = runningSum(nums);

    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}