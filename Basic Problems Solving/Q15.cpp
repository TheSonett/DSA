// 15.	WAP to find out Sum of numbers in a given range

#include <iostream>

int main()
{
    int start, end, sum = 0;

    std::cout << "Enter starting number: " << "\n";
    std::cin >> start;

    std::cout << "Enter ending number: " << "\n";
    std::cin >> end;

    for (int i = start; i <= end; i++)
    {
        sum += i;
    }

    std::cout << "The sum from " << start << "-" << end << " is: " << sum << "\n";
    return 0;
}