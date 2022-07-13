// Q. https://leetcode.com/problems/two-sum/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

// std::vector<int> twoSum(std::vector<int> &nums, int &target)
// {
//     std::vector<int> result{};
//     bool isTrue = false;
//     for(int i = 0; i < nums.size(); i++) {
//         for(int j = i+1; j < nums.size(); j++) {
//             if(nums[i] + nums[j] == target) {
//                 result.push_back(i);
//                 result.push_back(j);
//                 isTrue = true;
//                 break;
//             }
//         }
//         if(isTrue) {
//             break;
//         }
//     }

//     return result;
// } // Time Complexity -> O(n^2)


std::vector<int> twoSum(std::vector<int> &nums, int &target)
{
    std::unordered_map<int, int> hashmap;
    std::unordered_map<int, int>::iterator it;
    std::vector<int> vec;

    for (int i = 0; i < nums.size(); i++)
    {
        int difference = target - nums[i]; // 4 - 2 = 2
        if (hashmap.find(difference) != hashmap.end())
        {
            it = hashmap.find(difference);
            vec.push_back(it->second);
            vec.push_back(i);
        }

        hashmap.insert(std::make_pair(nums[i], i)); // val : index -> 2 : 0
    }

    return vec;
} // Time Complexity -> O(n)

int main()
{
    std::vector<int> nums = {2, 1, 5, 3};
    int target = 4;

    std::vector<int> re = twoSum(nums, target);
    std::for_each(re.begin(), re.end(), [](int x) { 
        std::cout << x << " "; 
    });

    return 0;
}