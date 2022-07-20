// Q. https://leetcode.com/problems/maximum-average-subarray-i/

#include <iostream>
#include <algorithm>
#include <vector>

double findMaxAverage(std::vector<int>& nums, int k) {
    std::vector<double> temp{};

    int i = 0;
    int j = 0;
    double sum = 0;

    while (j < nums.size())
    {
        sum += nums[j];

        if(j - i + 1 < k) {
            j++;
        }
        else if(j - i + 1 == k) {
            temp.push_back(sum);

            sum -= nums[i];
            i++;
            j++;
        }
    }

    double maxValue = *std::max_element(temp.begin(), temp.end());
    return (maxValue / k );
}

int main()
{
    std::vector<int> nums {1, 12, -5, -6, 50, 3};
    int k = 4;

    std::cout << findMaxAverage(nums, k);
    return 0;
}