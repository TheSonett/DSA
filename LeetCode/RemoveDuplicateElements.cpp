// 1. Unsorted Vector
// 2. Sorted Vector

#include <iostream>
#include <algorithm>
#include <unordered_map>
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


void RemoveDuplicatesFromUnsortedArray(std::vector<int>& nums) {
    if(nums.size() == 0) {
        return;
    }
    else {
        std::unordered_map<int, bool> hashmap;
        for (int i = 0; i < nums.size(); ++i) {
            // Print the element if it is not there in the hash map
            if (hashmap.find(nums[i]) == hashmap.end()) {
                std::cout << nums[i] << " ";
            }
    
            // Insert the element in the hash map
            hashmap[nums[i]] = true;
        }
    }
}


int main() {

    std::vector<int> nums = {1, 2, 2, 4, 3, 2, 3, 5, 6};
    int size = RemoveDuplicatesFromSortedArray(nums);

    for (int i = 0; i < size; i++)
    {
        std::cout << nums[i] << " ";
    }

    printf("\n\n");
    RemoveDuplicatesFromUnsortedArray(nums);
    
    return 0;
}