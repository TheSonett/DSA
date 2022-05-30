// Q2. WAP to find the first negative number in every sub-array of size K

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> nums = {12, -1, -7, 8, -15, 30, 16, 28, -3, -7, 4, 4}; // n = 12
    int k = 3;

    int i = 0;
    int j = 0;

    while(j < nums.size()) {
        if(j - i + 1 < k) {
            j++;
        }
        else if(j - i + 1 == k) {
            for(int x = i; x < j; x++) {
                if(nums[x] < 0) {
                    std::cout << nums[x] << " ";
                    break;
                } else if(nums[x] > 0) {
                    if(x == j - 1) {
                        std::cout << 0 << " ";
                        break;
                    }
                }
            }

            i++;
            j++;
        }
    }

    return 0;
}