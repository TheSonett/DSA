// Q. https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int i = 0;
    int j = (numbers.size() - 1);

    while (i < j)
    {
        if(numbers[i] + numbers[j] == target) {
            std::vector<int> result {i+1, j+1};
            return result;
        }
        else if(numbers[i] + numbers[j] < target) {
            i++;
        }
        else if(numbers[i] + numbers[j] > target) {
            j--;
        }
    }

    return std::vector<int>{}; // otherwise return empty
}

int main()
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = twoSum(nums, target);

    for (int i = 1; i <= result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    
    return 0;
}