// 22.	WAP to identify an user given number is Armstrong number or not

#include <iostream>
#include <cmath>

int main()
{
    int number;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> number;

    int temp = number;
    int i = number;

    int count = 0;
    int sum = 0;


    // finding how many digits are there
    while(i != 0) {
        i /= 10;
        count++;
    }

    // calculation of armstrong number
    while(number != 0) {
        int rem = number % 10;
        sum += std::pow(rem, count);

        // removing last number
        number /= 10;
    }

    (sum == temp) ? std::cout << "Armstrong Number Found!" << std::endl
                  : std::cout << "Not an armstrong number!" << std::endl; 

    std::cin.get();
}