#include <iostream>
#include <vector>
#include <algorithm>

// Time Complexity -> O(logn)
// Space Complexity -> O(1)
int BinarySearch(std::vector<int>& nums, int& val) {
    if(nums.size() == 0) {
        return -1;
    }

    if(nums.size() == 1) {
        return nums[0];
    }

    std::sort(nums.begin(), nums.end());

    int left = 0;
    int right = nums.size() - 1;
    bool flag = false;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // value is on the right side. So, left pointer should go to the right side
        if(nums[mid] < val) {
            left = mid + 1;
        }

        // value is on the left side. So, right pointer should go to the left side
        if(nums[mid] > val) {
            right = mid - 1;
        }

        if (nums[mid] == val) {
            flag = true;
            return nums[mid];
            break;
        }
    }
    
    if(!flag) {
        return -1;
    }
    else {
        return val;
    }
}

int main()
{
    std::vector<int> nums {1, 3, 3, 4, 10, 5, 7, 8, 9};
    int val = 2;
    if (BinarySearch(nums, val) == val) {
        std::cout << "Value Found!\n";
    }
    else {
        std::cout << "Value NOT Found!\n";
    }
    return 0;
}