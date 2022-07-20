// Q. https://leetcode.com/problems/maximum-erasure-value/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int maximumUniqueSubarray(std::vector<int>& nums) {
    std::unordered_map<int, int> hashmap;

    int i = 0;
    int j = 0;

    int sum = 0;
    int maxSum = 0;

    while (j < nums.size())
    {
        // If we found the duplicate element in the map
        if(hashmap[nums[j]]) {
            // reduce the window size from front until we don't have any duplicate elements in the array
            while (hashmap[nums[j]] != 0)
            {
                hashmap[nums[i]]--;
                sum = sum - nums[i]; // removing the element
                i++; // going to point next element;
            }
        }
        // if we don't found any duplicate element in the map, we're gonna add to the window
        else {
            sum += nums[j];
            maxSum = std::max(maxSum, sum); // taking out the max sum of unique elements

            hashmap[nums[j]]++;
            j++;
        }
    }

    return maxSum;
}

int main()
{
    std::vector<int> nums = {5,2,1,2,5,2,1,2,5};
    std::cout << maximumUniqueSubarray(nums);
    return 0;
}