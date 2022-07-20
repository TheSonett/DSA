// Q. https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

int minMoves2(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int moves = 0;
    int middleElement = nums[nums.size() / 2];

    for (int i = 0; i < nums.size(); i++)
    {
        moves += std::abs(nums[i] - middleElement); // (1-2) = -1 // 2-2 = 0 // 3 - 2 = 1 // moves = (-1 + 0 + 1) = 0 
        // If I do get the result as absolute numbers (only positive numbers) then, we get moves = 1 + 0 + 1 = 2
    }
    
    return moves;
}

int main()
{
    std::vector<int> nums = {1,10,2,9};
    std::cout << minMoves2(nums) << std::endl;
    return 0;
}