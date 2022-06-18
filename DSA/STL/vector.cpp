// NOTES:
// 1. std::vector is a sequence container and also known as Dynamic Array or Array List.
// 2. Its size can grow and shrink dynamically, and no need to provide size at compile time.


#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::string> findDuplicateWords(std::vector<std::string>& words) {
    std::vector<std::string> result{};

    std::sort(words.begin(), words.end());

    for (auto i = 0; i < words.size(); i++) {
        if(words[i] == words[i+1]) {
            if(result.empty())
                result.push_back(words[i]);
            else if(words[i] != result.back()) {
                result.push_back(words[i]);
            }
        }
    }

    if(result.size() == 0) {
        std::cout << "No duplicate words found!\n";
    }
    
    return result;
}


int main()
{
    std::vector<std::string> words {"joy", "rahul", "cpp", "vijay"};
    std::vector<std::string> result = findDuplicateWords(words);

    for (auto i : result)
    {
        std::cout << i << " ";
    }

    // std::vector<int> nums {2, 3, 0, 4, 5, 6, 0, 7, 8};
    
    // //operations
    // std::cout << "last element: " << nums.back() << "\n";
    // std::cout << "First element: " << nums.front() << "\n";
    // std::cout << "Capacity: " << nums.capacity() << "\n";
    // std::cout << "Data: " << *(nums.data() + 1) << "\n"; // data() return a pointer

    // nums.insert(nums.begin() + 1, 1); // position, value

    // // It assigns new values to the vector elements by replacing old ones. It can also modify the size of the vector if necessary.
    // //nums.assign(2, 4); // size, value 

    // nums.emplace_back(90);

    
    // for (int i : nums)
    // {
    //     std::cout << i << " ";
    // }
    
    // printf("\nAfter erasing all the zero's....\n");
    // for(auto it = nums.begin(); it != nums.end(); it++) {
    //     if(*it == 0) {
    //         nums.erase(it);
    //     }
    // }

    // for (int i : nums)
    // {
    //     std::cout << i << " ";
    // }
    

    return 0;
}