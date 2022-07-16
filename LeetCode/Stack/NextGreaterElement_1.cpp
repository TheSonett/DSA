// Q. https://leetcode.com/problems/next-greater-element-i/
// 496. Next Greater Element I

// Time Complexity -> O(m + n)
// Space Complexity -> O(n)

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
	std::vector<int> res{};
	std::stack<int> stack;
	std::unordered_map<int, int> hashmap;


	for (int i = nums2.size() - 1; i >= 0 ; i--) {
		while (!stack.empty() && stack.top() <= nums2[i]) {
			stack.pop();
		}

		if (stack.empty()) {
			hashmap[nums2[i]] = -1;
		}
		else {
			hashmap[nums2[i]] = stack.top();
		}

		stack.push(nums2[i]);
	}

	for (int i = 0; i < nums1.size(); i++) {
		res.push_back(hashmap[nums1[i]]);
	}

	return res;
}

int main()
{

	std::vector<int> nums1{ 4, 1, 2 };
	std::vector<int> nums2{ 1, 3, 4, 2 };
	std::vector<int> res = nextGreaterElement(nums1, nums2);

	std::for_each(res.begin(), res.end(), [](int x) {
		std::cout << x << " ";
	});
	std::cin.get();
}