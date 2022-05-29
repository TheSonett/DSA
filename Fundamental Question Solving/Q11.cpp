// 11.	WAP to find out Greatest of three numbers

#include <iostream>
#include <algorithm>

int main()
{
    int a, b, c;
    std::cout << "Enter first number: " << "\n";
    std::cin >> a;

    std::cout << "Enter second number: " << "\n";
    std::cin >> b;

    
    std::cout << "Enter third number: " << "\n";
    std::cin >> c;

    std::cout << "The greater of three numbers is: " << std::max({a, b, c}) << std::endl;
    return 0;
}