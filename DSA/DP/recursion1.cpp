// Q. Use recursion to do exactly same operations

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>


// Loop
std::string removeCharacter(std::string& str, char ch) {
    std::string result;

    if(str == " ") {
        return str;
    }

    for (int i = 0; i < str.size(); i++)
    {
        if(str[i] == ch) {
            continue;
        }

        result.push_back(str[i]);
    }

    str = result;
    return str;
}

// loop
std::string removeWords(std::string& str, std::string& word) {
    size_t location = str.find(word);

    if(location != std::string::npos) {
        str.erase(location, word.length());
    }

    return str;
}

int main()
{
    std::string str = "bbaaccdc";
    char ch = 'a';

    std::cout << removeCharacter(str, ch);

    std::string name = "Joy SSaaaaha";
    std::string word = "Saaa";

    printf("\n");
    std::cout << removeWords(name, word);
    
    return 0;
}