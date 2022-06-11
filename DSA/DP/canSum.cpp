// Q. Find a sum of a sub-array which can add up to some K value. return true if it is possible, otherwise false.

#include <iostream>
#include <vector>
#include <unordered_map>

// bool canSum(int targetSum, std::vector<int> nums)
// {   
//     if(targetSum == 0) {
//         return true;
//     }

//     if(targetSum < 0) {
//         return false;
//     }

//     for (int i = 0; i < nums.size(); i++)
//     {
//         int remainder = targetSum - nums[i];
//         if(canSum(remainder, nums) == true) {
//             return true;
//         }
//     }

//     return false;
// }


std::unordered_map<int, bool> map;
bool canSum(int targetSum, std::vector<int> nums)
{   
    if(targetSum == 0) {
        return true;
    }

    if(targetSum < 0) {
        return false;
    }

    if(map.find(targetSum) != map.end()) {
        return map[targetSum];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int remainder = targetSum - nums[i];
        if(canSum(remainder, nums) == true) {
            map.insert(std::pair<int, bool>(targetSum, true));
            return true;
        }
    }

    map.insert(std::pair<int, bool>(targetSum, false));
    return false;
}

int main()
{
    std::cout << canSum(7, {2, 3}) << "\n"; // true
    std::cout << canSum(7, {5, 3, 4, 7}) << "\n"; // true
    std::cout << canSum(300, {7, 14}) << "\n"; // false
    return 0;
}