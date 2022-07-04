// 55.	WAP to find out Sum of elements in an array

#include <iostream>
#include <array>
#define SIZE 5

int main()
{
    std::array<int, SIZE> nums{};
    int sum = 0;

    std::cout << "Enter " << SIZE << " elements in this array\n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cin >> nums[i];
    }

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }

    std::cout << "The sum is: " << sum << std::endl;
    return 0;
}