// 9.	WAP to find out GCD of two numbers

#include <iostream>

int main()
{
    int a, b, gcd;
    std::cout << "a: ";
    std::cin >> a;

    std::cout << "b: ";
    std::cin >> b;

    for (int i = 1; i <= a && i <= b; i++)
    {
        if(a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    std::cout << "GCD of " << a << " and " << b << " is: " << gcd << std::endl;

    return 0;
}