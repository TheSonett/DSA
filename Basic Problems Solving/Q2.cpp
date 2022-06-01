// 2.	WAP to check A character is an alphabet or not

#include <iostream>

int main()
{
    char ch;
    std::cout << "Enter a character: " << "\n";
    std::cin >> ch;

    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        std::cout << ch << " is an alphabet" << "\n";
    } 
    else {
        std::cout << "This is not an alphabet" << "\n";
    }
    return 0;
}