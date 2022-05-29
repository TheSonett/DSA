#include <iostream>
#include <vector>
#include <algorithm>

int removeElement(std::vector<int>& nums, int& val) {
	int temp = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != val) {
			nums[temp++] = nums[i];
		}
	}
	return temp;
}

int main()
{
	std::vector<int> nums = { 0,1,2,2,3,0,4,2 };
	int val = 2;
	int result = removeElement(nums, val);
	std::cout << result << ", nums = ";

	std::for_each(nums.begin(), nums.end(), [](int x) {
		std::cout << x << " ";
	});
	std::cin.get();
}