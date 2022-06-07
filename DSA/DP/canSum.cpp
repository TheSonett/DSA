#include <iostream>
#include <vector>

bool cache[100];

bool canSum(int targetSum, std::vector<int>& nums)
{
    // TODO:
    // if(cache[targetSum] && !cache[targetSum]) {
    //     return cache[targetSum];
    // }
    
    if(targetSum == 0) {
        return true;
    }

    if(targetSum < 0) {
        return false;
    }


    for (int i = 0; i < nums.size(); i++)
    {
        int remainder = targetSum - nums[i];
        if(canSum(remainder, nums)) {
            cache[targetSum] = true;
            return true;
        }
    }
    
    cache[targetSum] = false;
    return false;
}

int main()
{
    std::vector<int> nums = {5, 3, 1};
    int targetSum = 300;

    if(canSum(targetSum, nums)) {
        std::cout << "True\n";
    } 
    else {
        std::cout << "False\n";
    }
    return 0;
}