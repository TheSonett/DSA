#include <iostream>
#include <vector>

bool check(std::vector<int> &nums) {
    int count = 0;
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        if (nums[i - 1] > nums[i])
        {
            count++;
        }
    }

    // base condition
    if (nums[n - 1] > nums[0]) {
        count++;
    }

    if (count <= 1) {
        return true;
    }
    return false;
}

int main()
{
    std::vector<int> nums{20, 20, 78, 98, 99, 97};
    if (check(nums))
    {
        std::cout << "true\n";
    }
    else
    {
        std::cout << "false\n";
    }
    return 0;
}