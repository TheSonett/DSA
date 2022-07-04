// 61.	WAP to find out Longest palindrome in an array

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

#define N 15

struct Result {
    int numberOfElements;
    int numbers;
} res;

Result LongestPalindromeArray(std::vector<long long>& nums) {
    int low, high;
    int start = 0, end = 1;

    long long result = 0;
    int count = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        // for even part
        low = i - 1;
        high = i;
        while (low >= 0 && high < nums.size() && nums[low] == nums[high])
        {
            if(high - low + 1 > end) {
                start = low;
                end = high - low + 1;
            }

            low--;
            high++;
        }
        
        // for odd part
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < nums.size() && nums[low] == nums[high])
        {
            if(high - low + 1 > end) {
                start = low;
                end = high - low + 1;
            }
            
            low--;
            high++;
        }
    }
    
    for (int i = start; i <= start + end - 1; i++)
    {
        result = (result * 10) + (nums[i] % 10);
        count++;
    }
    
    res.numberOfElements = count;
    res.numbers = result;
    return { res.numberOfElements, res.numbers };
}


int main()
{
    //std::vector<long long> nums{2, 1, 2, 1, 2, 1, 2, 3, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 1};
    //std::vector<long long> nums{2, 1, 2, 5, 4, 5, 4, 5, 1};
    std::vector<long long> nums{2, 1, 2, 1, 2};
    //std::vector<long long> nums{0, 1, 0, 1, 0, 5, 4, 5, 2}; // test case failed!

    LongestPalindromeArray(nums);
    std::cout << "Longest palindrome number is: " << res.numbers << std::endl;
    std::cout << "There are " << res.numberOfElements << " palindrome numbers" << std::endl;

    return 0;
}