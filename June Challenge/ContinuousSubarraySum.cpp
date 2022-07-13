// Q. https://leetcode.com/problems/continuous-subarray-sum/

#include <iostream>
#include <vector>
#include <unordered_map>


std::unordered_map<int, int> hashmap {0 , -1}; // mapping remainder : end index
bool checkSubarraySum(std::vector<int>& nums, int k)
{
    
}

int main()
{
    std::vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;

    std::cout << checkSubarraySum(nums, k);
    return 0;
}