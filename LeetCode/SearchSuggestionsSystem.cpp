// Q. https://leetcode.com/problems/search-suggestions-system/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>

// class Solution {
// public:
//     std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string>& products, std::string searchWord) {
//         std::vector<std::vector<std::string>> result{};

//         // sorting -> O(nlogn)
//         std::sort(products.begin(), products.end());

//         // pointers
//         int left = 0;
//         int right = products.size() - 1;

//         // compare with each character
//         for (int i = 0; i < searchWord.length(); i++)
//         {
//             std::vector<std::string> temp{};
            
//             int ch = searchWord[i];
//             while (left <= right && products[left].length() <= i || products[left][i] != ch)
//             {
//                 left++;
//             }
            
//             while (left <= right && products[right].length() <= i || products[right][i] != ch)
//             {
//                 right--;
//             }

//             int size = right - left + 1;
//             for (int x = 0; x < std::min(3, size); x++)
//             {
//                 temp.push_back(products[left + x]);
//             }

//             result.push_back(temp);
//         }
        
//         return result;
//     }
// };

class Solution {
public:
    std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string>& products, std::string searchWord) {
        std::vector<std::vector<std::string>> result{};

        // sorting the list
        std::sort(products.begin(), products.end());

        // creating a map
        std::unordered_map<std::string, std::vector<std::string>> hashmap;

        // compare with each character
        for (auto& product : products)
        {
            std::string temp = "";
            // substring of each current products

            for (int i = 0; i < product.size(); i++)
            {
                temp.push_back(product[i]); // m

                if(hashmap[temp].size() < 3) {
                    hashmap[temp].push_back(product);
                }   
            }
        };

        std::string str = "";
        for (int i = 0; i < searchWord.size(); i++)
        {
            str += searchWord[i];
            result.push_back(hashmap[str]);
        }

        return result;
    }
};

int main()
{
    Solution obj;

    std::vector<std::string> products {"mobile","mouse","moneypot","monitor","mousepad"};
    std::string searchWord = "mouse";
    std::vector<std::vector<std::string>> result = obj.suggestedProducts(products, searchWord);

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