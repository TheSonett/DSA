// 13.	WAP to find out Sum of digits of a number

#include <iostream>

int main()
{
    int num, temp, sum = 0;
    std::cout << "Enter an integer: " << "\n";
    std::cin >> num;

    temp = num;

    while (num > 0)
    {
        // fetching last element
        int rem = num % 10;

        // finding sum
        sum += rem;

        // removing last element
        num /= 10;
    }
    
    std::cout << "Th sum of all digits in " << temp << " is: " << sum << "\n";

    return 0;
}