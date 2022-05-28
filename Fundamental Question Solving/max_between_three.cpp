// WAP to find max number between three numbers

#include <iostream>
#include <cmath>
#include <algorithm> // for std::max & std::min

int main()
{
    int a, b, c;
    std::cout << "Enter first number: ";
    std::cin >> a;

    std::cout << "Enter second number: ";
    std::cin >> b;

    std::cout << "Enter third number: ";
    std::cin >> c;

    std::cout << "\nMax number is: " << std::max({a, b, c}) << std::endl;

    return 0;
}