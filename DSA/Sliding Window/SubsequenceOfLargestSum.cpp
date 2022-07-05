// Q. https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

// Find Subsequence of Length K With the Largest Sum

// Time Complexity -> O(N)
// Space Complexity -> O(N^3)


#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>


std::vector<int> maxSubsequence(std::vector<int>& nums, int k) {
    std::vector<int> ans{};

    std::vector<int> temp = nums;
    std::unordered_map<int, int> map;

    std::sort(nums.begin(), nums.end()); // 1, 2, 3, 4, ...
    std::reverse(nums.begin(), nums.end()); // ..., 4, 3, 2, 1

    // storing all the occurrences of the numbers
    for (int i = 0; i < k; i++)
    {
        map[nums[i]]++;   
    }


    for (int i = 0; i < temp.size(); i++)
    {
        if(map[temp[i]] != 0) {
            std::cout << temp[i] << std::endl;
            ans.push_back(temp[i]);
            map[temp[i]]--;
        }
    }

    return ans;
}


int main()
{
    std::vector<int> nums {-1,-2,3,4};
    int k = 3;

    auto ans = maxSubsequence(nums, k);
    std::for_each(ans.begin(), ans.end(), [](int x) {
        std::cout << x << " ";
    });
    return 0;
}