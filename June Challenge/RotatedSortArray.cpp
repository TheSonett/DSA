#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int binarySearch(std::vector<int>& nums, int left, int right, int target) {
        if (right >= left) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                return binarySearch(nums, left, mid - 1, target);
            else
                return binarySearch(nums, mid + 1, right, target);
        }
        return -1;
    }

    int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        if (nums[left] == target)
            return left;
        if (nums[right] == target)
            return right;
        if (nums[left] > nums[right])
        {
            if (nums[left] > target)
            {
                while (nums[right] > nums[right - 1])
                {
                    if (nums[right - 1] == target)
                        return right - 1;
                    right--;
                }
            }
            else {
                while (nums[left] < nums[left + 1]) {
                    if (nums[left + 1] == target)
                        return left + 1;
                    left++;
                }
            }
        }
        else
            return binarySearch(nums, left, right, target);
        return -1;
    }

};

int main()
{
    std::vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    int target = 0;

    Solution sol;
    int result = sol.search(nums, target);
    std::cout << result << std::endl;


    std::cin.get();
}