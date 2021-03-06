// Q. https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

std::vector<int> findAnagrams(std::string str, std::string pattern) {
    std::vector<int> result{};
    std::unordered_map<char, int> map;

    // storing the occurrences of characters of patterns
    for (int i = 0; i < pattern.size(); i++)
    {
        map[pattern[i]]++;
    }

    int count = map.size();

    int k = pattern.size();
    int i = 0, j = 0;

    while (j < str.size())
    { 
        if(map.find(str[j]) != map.end()) {
            map[str[j]]--;

            if(map[str[j]] == 0) {
                count--;
            }
        }

        //window size less than k
        if((j - i + 1) < k) {
            j++;
        }
        else if((j - i + 1) == k) {
            if(count == 0) {
                result.push_back(i);
            }

            // removing previous calculations
            if(map.find(str[i]) != map.end()) {
                map[str[i]]++;
                
                if(map[str[i]] == 1) {
                    count++;
                }
            }

            // sliding the window
            i++;
            j++;
        }
    }

    return result;
}

int main()
{
    std::string str = "cbaebabacd";
    std::string pattern = "abc";
    
    std::vector<int> result = findAnagrams(str, pattern);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    
    return 0;
}