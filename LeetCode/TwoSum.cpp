// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.


#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int& target) {
        std::unordered_map<int, int> hashmap;
        std::unordered_map<int, int>::iterator it;
        std::vector<int> vec;

        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i]; // 2
            if (hashmap.find(difference) != hashmap.end()) {
                it = hashmap.find(difference);
                vec.push_back(it->second);
                vec.push_back(i);
            }

            hashmap.insert(std::make_pair(nums[i], i));
        }

        return vec;
    }
};  // Time Complexity -> O(n)


int main()
{
    std::vector<int> nums = {2, 1, 5, 3};
    int target = 4;

    Solution sou;
    std::vector<int> re = sou.twoSum(nums, target);
    
    std::for_each(re.begin(), re.end(), [](int x) {
        std::cout << x << " ";
    });
    
	return 0;
}