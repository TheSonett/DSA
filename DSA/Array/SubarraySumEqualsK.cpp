#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int subarraySum(std::vector<int>& nums, int k) {
    int sum = 0;
    int count = 0;

    std::unordered_map<int, int> hashmap;
    hashmap[sum] = 1;

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        int val = sum - k;

        if(hashmap.find(val) != hashmap.end()) {
            count += hashmap[val];
        }

        hashmap[sum]++;
    }

    return count;
}


int main()
{
    std::vector<int> nums = {1, 1, 1};
    int k = 2;

    std::cout << subarraySum(nums, k);
    return 0;
}