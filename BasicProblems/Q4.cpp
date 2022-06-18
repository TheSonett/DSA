// 4.	WAP to identify A number is positive or negative

#include <iostream>

int main()
{
    int num;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> num;

    if(num > 0) {
        std::cout << "It is positive!" << "\n";
    }
    else if(num < 0) {
        std::cout << "It is negative!" << "\n";
    }
    else {
        std::cout << "It is neither positive nor negative!" << "\n";
    }
    return 0;
}