// Q. https://leetcode.com/problems/merge-sorted-array/

#include <iostream>
#include <vector>
#include <algorithm>

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    for (int i = m, j = 0; i < n, j < n; i++, j++)
    {
        nums1[i] = nums2[j];
    }
    std::sort(nums1.begin(), nums1.end());

    for (int i = 0; i < m + n; i++)
    {
        std::cout << nums1[i] << " ";
    }
}

int main()
{
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};

    int m = nums1.size();
    int n = nums2.size();

    merge(nums1, m, nums2, n);
    return 0;
}