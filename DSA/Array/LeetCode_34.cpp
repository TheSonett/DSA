// Q. https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <iostream>
#include <vector>
#include <algorithm>

int firstPosition(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int pos = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] < target) {
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid - 1;
        }
        else if (nums[mid] == target) {
            pos = mid;
            // finding on the left part of mid
            right = mid - 1;
        }
    }

    return pos;
}

int lastPosition(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int pos = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] < target) {
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid - 1;
        }
        else if (nums[mid] == target) {
            pos = mid;
            // finding on the right part of mid
            left = mid + 1;
        }
    }

    return pos;
}

std::vector<int> searchRange(std::vector<int>& nums, int target) {
    std::vector<int> ans{};
    ans.push_back(firstPosition(nums, target));
    ans.push_back(lastPosition(nums, target));

    return ans;
}

int main()
{
    std::vector<int> nums {5, 7, 7, 8, 8, 10};
    int target = 6;

    std::vector<int> ans = searchRange(nums, target);
    for(int i : ans) {
        std::cout << i << " ";
    }
    return 0;
}