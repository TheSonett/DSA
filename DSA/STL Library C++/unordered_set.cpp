// NOTES:
// 0. Unordered Set is a associative container that contains set of unique objects.
// 1. Search, insertion, and removal have average constant-time complexity.
// 2. Internally, the elements are organized into buckets.
// 3. It uses hashing to insert elements into buckets. 
// 4. This allows fast access to individual elements, since once a hash is computed, 
//    it refers to the exact bucket the element is placed into.
// 5. Sets follow the Binary search tree implementation.
// 6. Insertion of Elements – O(log N)
//    Deletion of Elements – O(log N)


// WHY UNORDERED SET?
// 0. maintain a collection of unique items with fast insertion and removal.

#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <vector>

int main()
{
    std::unordered_set<int> nums {2, 3, 4, 5, 3, 2, 1, 8, 5, 9};
    std::set<int> ordered_set (nums.begin(), nums.end());

    // std::sort(nums.begin(), nums.end()); // will not work!
    for(auto& i : nums) {
        std::cout << i << " ";
    }

    printf("\n");
    
    for(auto& i : ordered_set) {
        std::cout << i << " ";
    }

    // operations
    printf("\n");
    // This function is used to insert a new element into the set container, 
    // only if the element to be inserted is unique and does not already exists in the set.
    ordered_set.emplace(99);

    for(auto& i : ordered_set) {
        std::cout << i << " ";
    }
    printf("\n");

    // check if 2 is present or not returns boolean 1 for true, 0 for false
    std::cout << "count(): " << ordered_set.count(32) << "\n"; 

    
    return 0;
}