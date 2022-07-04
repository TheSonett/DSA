// Q. https://leetcode.com/problems/sort-an-array/
// Merge Sort Time Complexity -> O(nlongn) in worst time

#include <iostream>
#include <vector>
#include <algorithm>

void Merge(std::vector<int>& nums, int left, int mid, int right) {
    int i, j, k;

    int n1 = mid - left + 1;
    int n2 = right - mid;
 
    // create temp arrays L & R
    std::vector<int> L;
    std::vector<int> R;
    L.reserve(n1);
    R.reserve(n2);
 
    // Copy data to temp arrays L and R
    for (i = 0; i < n1; i++)
        L[i] = nums[left + i];
    for (j = 0; j < n2; j++)
        R[j] = nums[mid + 1+ j];
 

    i = 0; 
    j = 0; 
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            nums[k] = L[i];
            i++;
        }
        else
        {
            nums[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        nums[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        nums[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(std::vector<int>& nums, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        MergeSort(nums, left, mid);
        MergeSort(nums, mid + 1, right);
        Merge(nums, left, mid, right);
    }
}

 std::vector<int> sortArray(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
		
	MergeSort(nums, left, right);
    return nums;
}


int main() {
    std::vector<int> nums{2, 1};
    std::cout << "Before sorting :::\n";
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }
    
    std::vector<int> result = sortArray(nums);

    std::cout << "\nAfter sorting :::\n";
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    return 0;
}