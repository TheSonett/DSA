// Bubble Sort: Compare two elements & if the first element is greater than the second element, then swap it.
// Time Complexity -> O(n^2)
// Space Complexity -> 0(1)

#include <iostream>
#include <algorithm>
#include <vector>

void BubbleSort(std::vector<int>& nums) {
    //std::sort(nums.begin(), nums.end()); // If the array is already sorted, then the best case is O(n)

    for (int i = 0; i < nums.size(); i++)
    {
        bool flag = false;
        for (int j = 0; j < nums.size(); j++)
        {
            // if the current value is greater than the second value, then swap the numbers
            if(nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;

                flag = true;
            }
        }

        if(flag == false) {
            break;
        }
    }
}

int main() {
    std::vector<int> nums {56, 32, 12, 22, 76, 84, 43, 33};
    std::cout << "Before Sorting ::: \n";
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }
    
    BubbleSort(nums);

    std::cout << "\nAfter Sorting ::: \n";
    for (int i = 1; i <= nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }
    return 0;
}