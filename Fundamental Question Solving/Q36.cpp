// 36.	WAP Decimal to binary conversion

#include <iostream>
#include <bitset>

int main()
{
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    std::cout << num << "'s 4-bit binary representation is: " << std::bitset<4>(num) << std::endl;
    return 0;
}