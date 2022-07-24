#include <iostream>
#include <string>
#include <unordered_map>

char repeatedCharacter(std::string s) {
    std::unordered_map<char, int> hashmap;
    std::unordered_map<char, int>::iterator it;
    for (int i = 0; i < s.length(); i++) {
        std::cout << (hashmap[s[i]] == 1) << std::endl;
        if(hashmap[s[i]] == 1) {
            return s[i];
        }
        hashmap[s[i]] = 1;
    }

    return 'a';
}

int main()
{
    std::string s = "abccdff";
    std::cout << repeatedCharacter(s);

    return 0;
}