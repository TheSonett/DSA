// 6.	WAP to Swap two numbers without third variable

#include <iostream>

int main()
{
    int a, b;
    std::cout << "Enter number a: ";
    std::cin >> a;

    std::cout << "Enter number b: ";
    std::cin >> b;

    // swaping
    a = a + b;
    b = a - b;
    a = a - b;

    std::cout << "After swaping two numbers...\n";
    std::cout << "a : " << a << " , " << "b : " << b << "\n"; 

    return 0;
}