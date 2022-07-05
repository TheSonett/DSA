// Time Complexity: O(N)
// Space Complexity: O(N)


#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

int CountOfAnagram(std::string& string, std::string& pattern) {
    std::unordered_map<char, int> hashmap;
    int ans = 0;

    // counting all the occurrences of characters
    for (int i = 0; i < pattern.size(); i++)
    {
        hashmap[pattern[i]]++;
    }
    
    int i = 0, j = 0;
    int k = pattern.size();
    int count = hashmap.size();

    while (j < string.size())
    {
        // if we found the character in map, then decrement it's occurrence
        if(hashmap.find(string[j]) != hashmap.end()) {
            hashmap[string[j]]--;

            // if any character's occurrence is 0, then we have to decrement count by 1
            if( hashmap[string[j]] == 0) {
                count--;
            }
        }

        // slide the window until we reach to window size
        if((j - i + 1) < k) {
            j++;
        }
        else if((j - i + 1) == k) { // when we reached to the window size, then keep the size by incrementing i & j by 1

            // when count is zero, means we found a answer
            if(count == 0) {
                ans++;
            }

            // After sliding the window we have to remove that first character
            if(hashmap.find(string[i]) != hashmap.end()) {
                hashmap[string[i]]++;

                // if any character's occurrence is 1, then we have to increment count by 1
                if(hashmap[string[i]] == 1) {
                    count++;
                }
            }

            i++;
            j++;
        }
    }

    return ans;
}

int main()
{
    std::string string = "aabaabaa";
    std::string pattern = "aaba";

    std::cout << CountOfAnagram(string, pattern);
    return 0;
}