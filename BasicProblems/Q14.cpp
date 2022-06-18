// 14.	WAP to find out Sum of N natural numbers

#include <iostream>

int main()
{
    int num, sum = 0;
    std::cout << "Enter a number: " << "\n";
    std::cin >> num;

    for (int i = 1; i <= num; i++)
    {
        sum += i;
    }

    std::cout << "The sum of 1-" << num << " natural numbers is: " << sum << "\n";
    
    return 0;
}