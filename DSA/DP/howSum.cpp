#include <iostream>
#include <vector>

int howSum(int targetSum, std::vector<int>& nums) {
    std::vector<int> vec{};

    if(targetSum == 0)
        return 0;
    if(targetSum < 0)
        return -1;
    
    for (int i = 0; i < nums.size(); i++)
    {
        int remainder = targetSum - nums[i];
        int result = howSum(remainder, nums);

        if(result != -1) {
            vec.push_back(nums[i]);
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    

    return -1;
}

int main()
{
    std::vector<int> nums = {2, 3, 5};
    int targetSum = 8;

    howSum(targetSum, nums);
    
    return 0;
}