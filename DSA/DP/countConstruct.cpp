#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

int countConstruct(std::string& target, std::vector<std::string>& words) {
    std::unordered_map<std::string, int> map;

    if(target.size() == 0) {
        return 1;
    }

    if(target.size() < 0) {
        return -1;
    }

    if(map.find(target) != map.end()) {
        return map[target];
    }

    int count = 0;

    for (int i = 0; i < words.size(); i++)
    {
        if(target.find(words[i]) == 0) {
            auto suffix = target.substr(words[i].length());
            count += countConstruct(suffix, words);
        }
    }
    
    map[target] = count;
    return count;
}


int main()
{
    // std::vector<std::string> words {"ab", "abc", "cd", "def", "abcd"};
    // std::string target = "abcdef";

    // std::vector<std::string> words {"purp", "p", "ur", "le", "purpl"};
    // std::string target = "purple";

    std::vector<std::string> words {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
    std::string target = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef"; // TODO: Still slow!

    std::cout << countConstruct(target, words);
    return 0;
}