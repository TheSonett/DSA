// TOPIC: STL ALGORITHM std::iota

// NOTES:
// 0. Fills the range [first, last) with sequentially increasing values,
//    starting with value and repetitively evaluating ++value.

#include <iostream>
#include <numeric> // for std::iota
#include <vector>

int main()
{
    std::vector<int> nums(10);
    std::iota(nums.begin(), nums.end(), 100);

    for(auto i : nums) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < nums.size(); i+=2)
    {
        std::cout << nums[i] <<  " ";
    }
    

    return 0;
}