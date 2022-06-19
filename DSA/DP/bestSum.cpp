#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

std::vector<int> bestSum(int& targetSum, std::vector<int>& nums) {
    std::vector<int> result{};
    std::vector<int> shortestCombination{NULL};
    std::unordered_map<int, std::vector<int>> hashmap;

    if (targetSum == 0) {
        return std::vector<int>{};
    }

    if(targetSum < 0) {
        return std::vector<int>{NULL};
    }

    if(hashmap.find(targetSum) != hashmap.end()) {
        return hashmap[targetSum];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int remainder = targetSum - nums[i];
        auto combination = bestSum(remainder, nums);

        if(combination != std::vector<int>{NULL}) {
            result = combination;
            result.push_back(nums[i]);

            // if the combination is shorter, than the current shortest, then update it
            if(shortestCombination == std::vector<int>{NULL} || result.size() < shortestCombination.size()) {
                shortestCombination = result;
            }
        }
    }
    
    hashmap[targetSum] = shortestCombination;
    return hashmap[targetSum];
}


int main()
{
    // int targetSum = 8;
    // std::vector<int> nums {1, 4, 5};
    
    // int targetSum = 8;
    // std::vector<int> nums {2, 3, 5};

    int targetSum = 7;
    std::vector<int> nums {5, 3, 4, 7};

    // int targetSum = 100;
    // std::vector<int> nums {1, 2, 5, 25}; // TODO: Have to memoized

    std::vector<int> result = bestSum(targetSum, nums);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    
    return 0;
}