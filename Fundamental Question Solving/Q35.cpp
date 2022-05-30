// 35.	WAP Binary to decimal conversion

#include <iostream>
#include <bitset>

int main()
{
    std::bitset<4> num;
    std::cout << "Enter a binary number: ";
    std::cin >> num;

    std::cout << "Decimal representation of " << num << " is: " <<  num.to_ulong() << std::endl;
    return 0;
}