// Q. Write a program to remove vowels of an user given string

#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
#include <vector>

void eraseVowels(std::string& str) {
    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u',
                           'A', 'E', 'I', 'O', 'U'};
    for(int i = 0; i < str.length(); i++) {
        if(std::find(vowels.begin(), vowels.end(), str[i]) != vowels.end()) {
            str = str.replace(i, 1, "");
            i--;
        }
    }    
}

std::string eraseVowels2(std::string& str) {
    std::regex reg ("[aeiouAEIOU]");
    
    return std::regex_replace(str, reg, "");
}


int main()
{
    std::string str;
    std::cout << "Enter a string: ";
    std::cin >> str;

    str = eraseVowels2(str);

    std::cout << str << std::endl;
    std::cin.get();
}