// 12.	WAP to find out Number of digits in an integer

#include <iostream>

int main()
{
    int num, temp, count = 0;
    std::cout << "Enter an integer: " << "\n";
    std::cin >> num;

    temp = num;

    while (num > 0)
    {
        // removing last element
        num /= 10;    
        count++;
    }
    
    std::cout << "Number of digits in " << temp << " is: " << count << "\n";

    return 0;
}