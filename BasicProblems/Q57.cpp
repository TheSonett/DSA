// 57.	WAP to find out Sum of positive square elements in an array

/*For this program, we need to find the square of every element and add all these square elements.
Example
Input:       1 2 3 4 5
Square:     1 4 9 16 25
sum:        1+4+9+16+25=55*/


#include <iostream>
#include <array>
#include <cmath>
#define N 5

int main()
{
    std::array<int, N> nums{};
    int sum = 0;

    std::cout << "Enter " << N << " elements in this array.\n";
    for (int i = 0; i < N; i++)
    {
        std::cin >> nums[i];
    }

    for(int i = 0; i < nums.size(); i++) {
        nums[i] = std::pow(nums[i], 2);
    }

    std::cout << "\nAfter converting each element with it's square element, we have, \n";
    for(int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << " ";
    }

    printf("\n");

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }

    std::cout << "\nThe Sum of positive square elements is: " << sum << std::endl;
    return 0;
}