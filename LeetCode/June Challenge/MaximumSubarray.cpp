// Given an integer array nums, find the contiguous subarray(containing at least one number) which has the largest sum and return its sum.
// A subarray is a contiguous part of an array.

#include <iostream>
#include <vector>
#include <limits>

/*int maxSubArray(std::vector<int>& nums) {
	int max_sum = INT_MIN;

	for (int i = 0; i < nums.size(); i++) {
		int sum = 0;
		for (int j = i; j < nums.size(); j++) {
			sum += nums[j];
			max_sum = std::max(max_sum, sum);
		}
	}

	return max_sum;
} //  Brute force -> O(n^2)*/ 
// Worst time complexity can be O(n^3)


int maxSubArray(std::vector<int>& nums) {
	int max_sum = nums[0];
	int current_sum = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (current_sum < 0) {
			current_sum = 0;
		}
		current_sum += nums[i];
		max_sum = std::max(max_sum, current_sum);
	}

	return max_sum;
} // kadane's algorithm -> O(n)

int main()
{
	std::vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int result = maxSubArray(nums);

	std::cout << result << std::endl;
	std::cin.get();
}