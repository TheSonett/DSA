// Q. https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <unordered_map>

class Solution {
private:
    std::unordered_map<std::string, int> hashmap;
    int solve(std::vector<int>& nums, int x, int left, int right, int count) {
        if(x == 0) {
            return count;
        }

        if(x < 0 || left > right) {
            return 1e6;
        }

        std::string key = std::to_string(left) + "*" + std::to_string(right) + "*" + std::to_string(count);
        if(hashmap.count(key)) {
            return hashmap[key];
        }

        int l = solve(nums, x - nums[left], left + 1, right, count + 1);
        int r = solve(nums, x - nums[right], left, right - 1, count + 1);

        hashmap[key] = std::min(l, r);
        return hashmap[key];
    }
public:
    int minOperations(std::vector<int>& nums, int x) {
        int ans = solve(nums, x, 0, nums.size() - 1, 0);
        return ans >= 1e6 ? -1 : ans;
    }
};


int minOperations(std::vector<int>& nums, int x) {
    int sum = 0;
    int max_len = 0;
    int current_sum = 0;

    int start = 0;
    int end = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    
    int rest = sum - x;
    bool found = false;

    for(end = 0; end < nums.size(); end++) {
        current_sum += nums[end];

        while(start <= end && current_sum > rest) {
            current_sum -= nums[start];
            start++;
        }

        if(current_sum == rest) {
            found = true;
            max_len = std::max(max_len, end - start + 1);
        }
    }

    return found ? nums.size() - max_len : -1;
}


int main()
{
    Solution obj;

    std::vector<int> nums = {3, 2, 20, 1, 1, 3};
    int x = 10;

    std::cout << obj.minOperations(nums, x) << std::endl;
    std::cout << minOperations(nums, x) << std::endl;
    return 0;
}