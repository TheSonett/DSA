// 56.	WAP to Check if two arrays are the same or not

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> nums1{1, 2, 3, 4, 5};
    std::vector<int> nums2{1, 2, 2, 4, 5};

    if(nums1 == nums2) {
        std::cout << "They both are same!\n";
    }
    else {
        std::cout << "They both are not same!\n";
    }
    return 0;
}