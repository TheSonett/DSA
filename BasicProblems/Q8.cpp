// 8.	WAP to find out LCM of two numbers

#include <iostream>
#include <numeric>

int main()
{
    int a, b;
    int lcm, gcd;
    std::cout << "Enter first number: " << "\n";
    std::cin >> a;

    std::cout << "Enter second number: " << "\n";
    std::cin >> b;

    
    for (int i = 1; i <= a && i <= b; i++) {
        if(a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    
    lcm = (a * b) / gcd;

    //std::cout << "The LCM of " << a << " and " << b << " is: " << std::lcm(a, b) << std::endl;
    std::cout << "The LCM of " << a << " and " << b << " is: " << lcm << std::endl;
    return 0;
}