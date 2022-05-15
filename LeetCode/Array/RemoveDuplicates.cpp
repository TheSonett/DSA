#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int removeDuplicates(std::vector<int>& nums) {
	int left = 1;

	for (int right = 1; right < nums.size(); right++) {
		if (nums[right] != nums[right -1]) {
			nums[left] = nums[right];
			left++;
		}
	}

	return left;
} // Time Complexity - O(n);


int main()
{
	std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	std::cout << removeDuplicates(nums);
	std::cout << ", nums = ";
	for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " ";
	}
	std::cin.get();
}
