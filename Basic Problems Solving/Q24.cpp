// 24.	WAP to identify an user given number is Perfect number or not
#include <iostream>
#include <cmath>

int main()
{
    int num, temp, sum = 0;
    std::cout << "Enter a number: ";
    std::cin >> num;

    temp = num;

    for(int i = 1; i < num; i++) {
        if(num % i == 0) {
            sum += i;
        }
    }

    if(temp == sum) {
        std::cout << num << " is a perfect number!\n";
    }
    else {
        std::cout << num << " is not a perfect number!\n";
    }

    return 0;
}