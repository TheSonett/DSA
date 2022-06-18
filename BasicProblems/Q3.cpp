// 3.	WAP to find out Ascii values of a character

#include <iostream>

int main()
{
    char ch;
    std::cout << "Enter a character to find it's ASCII value: " << "\n";
    std::cin >> ch;

    std::cout << ch << " 's ASCII value is: " << (int)ch << "\n"; // explicit casting
    return 0;
}