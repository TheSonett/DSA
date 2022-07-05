// 128. Longest Consecutive Sequence

// Explanation:

// 1. Insert all the elements of the array into set.
// 2. Check if the previous number (nums[i] - 1) is present in the set, if it is then that number (nums[i]) is not the starting of the sequence.
// 3. If previous number is not present, that means that number is the starting of the sequence.
// 4. Make a count variable to count the length of the sequence and current variable to store the current number.
// 5. Now in a while loop, traverse and keep searching for consecutive elements until the condition is false.
// 6. Now store the maximum of longest_sequence and current length of the sequence.

#include <iostream>
#include <vector>
#include <unordered_set>

// int longestConsecutive(std::vector<int>& nums) {
//     std::unordered_set<int> numSet(nums.begin(), nums.end());
//     int longest = 0;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         // check if the current element is the start of a sequence
//         // If is not then set the length first
//         if (numSet.find(nums[i] - 1) == numSet.end()) {
//             int length = 0;
            
//             while (numSet.find(nums[i] + length) != numSet.end())
//             {
//                 length++;
//             }
            
//             longest = std::max(length, longest);
//         }
//     }
//     return longest;
// }

int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> set (nums.begin(), nums.end());
    int ans = 0;

    for (int i : nums){
        if(set.find(i) == set.end()) {
            continue;
        }

        int prev = i - 1, next = i + 1;
        while (set.find(prev) != set.end())
        {
            prev--;
        }
        
        while (set.find(next) != set.end())
        {
            next++;
        }

        ans = std::max(ans, next-prev-1);
        set.erase(i);
    }

    return ans;
}

int main()
{
    std::vector<int> nums {100, 4, 200, 1, 3, 2};
    std::cout << longestConsecutive(nums);
    return 0;
}