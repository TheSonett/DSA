#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> bestSum(int& targetSum, std::vector<int>& nums) {
    std::vector<int> result{};

    if (targetSum == 0) {
        return std::vector<int>{};
    }

    if(targetSum < 0) {
        return std::vector<int>{NULL};
    }

    std::vector<int> shortest {};

    for (int i = 0; i < nums.size(); i++)
    {
        int remainder = targetSum - nums[i];
        auto combination = bestSum(remainder, nums);

        if(combination != std::vector<int>{NULL}) {
            result = combination;
            shortest = combination;

            result.push_back(nums[i]);
            shortest.push_back(nums[i]);

            if(result.size() < shortest.size()) {
                shortest = result;
            }
        }
    }
    
    return shortest;
}


int main()
{
    int targetSum = 8;
    std::vector<int> nums {1, 2, 5};

    std::vector<int> result = bestSum(targetSum, nums);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    
    return 0;
}