// Given an array of integers arr & find the duplicate numbers in this array
// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

#include <iostream>
#include <array>
#include <unordered_map>

bool containsDuplicate(std::vector<int>& nums)
{
	std::unordered_map<int, int> hashmap; // Key, value pair
	std::unordered_map<int, int>::iterator it; // making a map iterator

	for (int i = 0; i < nums.size(); i++) {
		int a = nums[i];
		hashmap[a]++;

	}

	for (it = hashmap.begin(); it != hashmap.end(); it++) {
		if (it->second > 1) {
			return true;
		}
	}

	return false;

} // Time Complexity - O(n) worst case - O(n^2)


void findDuplicateElements(int arr[], int& size) 
{
	std::unordered_map<int, int> hashmap; // Key, value pair
	std::unordered_map<int, int>::iterator it; // making a map iterator
	bool isduplicate = false;

	for (int i = 0; i < size; i++) {
		int a = arr[i];
		hashmap[a]++;
		
	}

	for (it = hashmap.begin(); it != hashmap.end(); it++) {
		if (it->second > 1) {
			std::cout << it->first << " ";
			isduplicate = true;
		}
	}

} // Time Complexity - O(n) worst case - O(n^2)


int main()
{
	//std::vector<int> arr = { 12, 3, 4, 6, 4};
	int arr[] = {12, 3, 4, 6, 4};
	int size = sizeof(arr) / sizeof(arr[0]);

	findDuplicateElements(arr, size);
	//std::cout << containsDuplicate(arr);

	std::cin.get();
}