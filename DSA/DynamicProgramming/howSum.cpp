#include <iostream>
#include <vector>

std::vector<int> howSum(int targetSum, std::vector<int>& nums) {
    std::vector<int> vec{};

    if(targetSum == 0)
        return {};
    if(targetSum < 0)
        return {NULL};
    
    for (int i = 0; i < nums.size(); i++)
    {
        int remainder = targetSum - nums[i];
        std::vector<int> result = howSum(remainder, nums);

        if(result[i] != NULL) {
            vec.push_back(nums[i]);
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }

    return vec;
}

int main()
{
    std::vector<int> nums = {2, 3, 5};
    int targetSum = 8;

    std::vector<int> ans = howSum(targetSum, nums);
    for(auto i : ans) {
        std::cout << i << " ";
    }
    
    return 0;
}