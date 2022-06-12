// 1. Unsorted Vector
// 2. Sorted Vector

#include <iostream>
#include <algorithm>
#include <vector>

int RemoveDuplicatesFromSortedArray(std::vector<int>& nums) {
    if(nums.size() == 0) {
        return nums.size();
    }
    else {
        std::sort(nums.begin(), nums.end());
        int j = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != nums[i+1]) {
                nums[j++] = nums[i];
            }
        }

        nums[j] = nums[nums.size() - 1];
        return j;
    }
}

int maximumUniqueSubarray(std::vector<int>& nums) {
    long long size = RemoveDuplicatesFromSortedArray(nums);
    if(size == 0) {
        return size;
    }
    else {
        long long sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += nums[i];
        }

        return sum;
    }
}

int main() {

    std::vector<int> nums = {1000, 1, 2, 1000};
    std::cout << maximumUniqueSubarray(nums);
    
    return 0;
}