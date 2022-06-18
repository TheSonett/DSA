// 23.	WAP to identify an user given number is Strong number or not

#include <iostream>
#include <cmath>

int factorial(int num) {
    return (num == 1 || num == 0) ? 1 : num * factorial(num - 1);
}


int main()
{
    int num, sum = 0;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> num;

    int temp = num;

    while (num > 0)
    {
        int rem = num % 10;
        sum += factorial(rem);
        num /= 10;
    }

    (temp == sum) ? std::cout << temp << " is a strong number!\n" 
                  : std::cout << temp << " is not a strong number!\n";

    return 0;
}