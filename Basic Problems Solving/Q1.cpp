// 1.	WAP to check A character is a vowel or consonant

#include <iostream>

int main() {
    char ch;
    std::cout << "Enter a character: " << "\n";
    std::cin >> ch;

    (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U') ? 
        std::cout << ch << " is a vowel" :
        std::cout << ch << " is a consonant";

    return 0;
}