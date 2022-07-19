#include <iostream>
#include <vector>
#include <cstring>

// TC -> O(n^2)
// SC -> O(n)

bool canSum(int targetSum, std::vector<int> nums) {
    bool table[targetSum + 1];
    memset(table, false, sizeof(table));

    table[0] = true;

    for (int i = 0; i <= targetSum; i++)
    {
        if(table[i] == true) {
            for (int j = 0; j < nums.size(); j++)
            {
                table[i + nums[j]] = true;
            }
        }
    }

    return table[targetSum];
}

int main()
{
    if(canSum(7, {5, 3, 4, 7})) {
        std::cout << "true" << std::endl;
    }
    else {
        std::cout << "false" << std::endl;
    }
    return 0;
}