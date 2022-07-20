#include <iostream>
#include <vector>
#include <algorithm>

int minOperation(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int middleElement = nums[nums.size() / 2];

    int minOperations = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        minOperations += std::abs(nums[i] - middleElement);
    }
    return minOperations;
}


int main()
{
    std::vector<int> nums = {1, 10, 2, 9};
    std::cout << minOperation(nums) << std::endl;
    
    return 0;
}