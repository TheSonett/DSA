// Program to find the second largest element in the array

// My apporach is to find the max-value's index to get the second max value's index using the largest value's index

#include <iostream>
#include <vector>

int FindSecondLargest(std::vector<int>& vec) 
{
	int largest = 0;
	int secondLargest = 0;

	// finding the largest value's index
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] > vec[largest]) {
			largest = i;
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		// If we're not finding any same value, then do this if statement to find second largest value
		if (vec[i] != vec[largest]) {
			if (vec[i] > vec[secondLargest]) {
				secondLargest = i;
			}
		}
	}

	return secondLargest;
}


int main()
{
	std::vector<int> vec{ 10, 12, 20, 4, 30, 10, 34, 32, 22, 40, 41 };
	int secondlargestIndex = FindSecondLargest(vec);

	std::cout << "Second largest value is: " << vec[secondlargestIndex] << std::endl;
	std::cin.get();
}