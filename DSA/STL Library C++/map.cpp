#include <iostream>
#include <vector>

// This is a sorted map. Means all the elements are ordered.
// And It is basically a self-balancing binary search tree means a red-black tree.
// Basically in a red-black tree, all the nodes compare to each other with a less than operator
// when we try to insert a new node into that binary tree & stored in the appropriate place.
#include <map> 

#include <unordered_map> // and this map is unordered & is a hash-table.
// It uses a hash function to hash your key & it generates a index to figure out where your actual
// value is present that you're looking for. Thus, by using that index, we retrieve that value.
// It is actually faster than the std::map.

// So, If you don't need a sorted data structure, just use std::unordered_map.

struct Friend
{
    std::string name;
    uint64_t phone_number;
};


int main() 
{
    //std::map<std::string, Friend> friendMap;
    std::unordered_map<std::string, Friend> friendMap;

    friendMap["Joy Saha"] = Friend {"Joy Saha", 907352524};
    friendMap["Rahul Dey"] = Friend {"Rahul Dey", 43673627};
    friendMap["Tanmay Bhatt"] = Friend {"Tanmay Bhatt", 83298473};
    friendMap["Virat Kohli"] = Friend {"Virat Kohli", 20734240};

    if(friendMap.find("Tanmay") != friendMap.end()) {
        Friend& fr = friendMap.at("Tanmay");
        std::cout << fr.phone_number << "\n";
    } 
    else {
        std::cout << "Not found!" << std::endl;
    }

    return 0;
}