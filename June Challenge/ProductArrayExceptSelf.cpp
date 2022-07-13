#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
		std::vector<int> res{ nums };
		int postfix = 1;

		for (int i = 1; i < nums.size(); ++i)
		{
			res[i] *= res[i - 1];
		}

		for (int i = nums.size() - 1; i > 0; --i)
		{
			res[i] = postfix;
			res[i] *= res[i - 1];
			postfix *= nums[i];
		}
		res[0] = postfix;

		return res;
    }
};

int main()
{
    std::vector<int>nums {1, 2, 3, 4};

    Solution sol;
    std::vector<int> res = sol.productExceptSelf(nums);

    std::for_each(res.begin(), res.end(), [](int i) {
        std::cout << i << " ";
    });

    std::cin.get();
}