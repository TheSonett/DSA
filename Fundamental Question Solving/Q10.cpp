// 10.	WAP to find out  Greatest of two numbers

#include <iostream>
#include <algorithm>

int main()
{
    int a, b;
    std::cout << "Enter first number: " << "\n";
    std::cin >> a;

    std::cout << "Enter second number: " << "\n";
    std::cin >> b;

    std::cout << "The greater of two numbers is: " << std::max({a, b}) << std::endl;
    return 0;
}