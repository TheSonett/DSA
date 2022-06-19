#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>

// std::vector<std::vector<int>> allConstruct(std::string& target, std::vector<std::string>& words) {
//     std::vector<std::vector<int>> suffixWays{};
//     std::vector<std::vector<int>> result{};

//     if(target.size() == 0) {
//         return std::vector<std::vector<int>>{};
//     }

//     for (int i = 0; i < words.size(); i++)
//     {
//         if(target.find(words[i]) == 0) {
//             auto suffix = target.substr(words[i].size());
//             suffixWays = allConstruct(suffix, words);

//             for (int i = 0; i < suffixWays.size(); i++)
//             {
//                 for (int j = 0; j < suffixWays[i].size(); i++)
//                 {
//                     result[i][j] = suffixWays[i][j];
//                 }
//             }
//         }
//     }

//     return result;
// }


// Tabulation Approach
std::vector<std::vector<std::string>> allConstruct(std::string& target, std::vector<std::string>& wordBank) {
    std::vector<std::vector<std::vector<std::string>>> table; // 3D

    for(int i = 0; i <= target.length(); i++) {
        std::vector<std::vector<std::string>> A = {};
        table.push_back(A);
    }

    std::vector<std::string> A = {};
    table[0].push_back(A);

    for(int i=0;i<=target.length();i++) {
        for(auto j: wordBank) {
            if(target.substr(i,j.length())==j) {
                for(auto combination: table[i]) {
                    std::vector<std::string> A = combination;
                    A.push_back(j);
                    table[i+j.length()].push_back(A);
                }
            }
        }
    }
    return table[target.length()];
}


int main()
{
    std::vector<std::string> words {"ab", "abc", "cd", "def", "abcd", "ef", "c"};
    std::string target = "abcdef";

    // std::vector<std::string> words {"cat", "dog", "mouse"};
    // std::string target = "hello"; // []

    // std::vector<std::string> words {"cat", "dog", "mouse"};
    // std::string target = " "; // [[]]

    std::vector<std::vector<std::string>> result = allConstruct(target, words);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    
    return 0;
}