// 16.	WAP to find out Reverse of a given number

#include <iostream>
#include <string>

int main()
{
    int number;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> number;

    int originalNum = number;
    std::string temp = "";

    while(number != 0) {
        int rem = number % 10;
        temp = temp + std::to_string(rem);
        number /= 10;
    }

    std::cout << "The reverse of "<< originalNum << " is: "<< std::stoi(temp);
    std::cin.get();
}