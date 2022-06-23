// Q. https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int findKthLargest(std::vector<int>& nums, int k) {
    std::priority_queue<int> maxHeap;

    for (int i = 0; i <= k; i++)
    {
        maxHeap.push((-1) * nums[i]);

        while (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }

    return maxHeap.top();
}

// int findKthLargest(std::vector<int>& nums, int k) {
//     std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         minHeap.push(nums[i]);

//         while (minHeap.size() > k) {
//             minHeap.pop();
//         }
//     }
    
//     return minHeap.top();
// }


int main() {
    std::vector<int> nums {3, 2, 1, 5, 6, 4};
    int k = 2;

    std::cout << findKthLargest(nums, k);
    return 0;
}