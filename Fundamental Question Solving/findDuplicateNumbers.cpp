// Q. Find the duplicate numbers in an user given array.

#include <iostream>
#include <unordered_map>

int main()
{
	const int size = 5;
	int temp[size];

	std::cout << "Enter " << size << " elements: " << std::endl;
	for (int i = 0; i < size; i++) 
	{
		std::cin >> temp[i];
	}

	// TODO: Find duplicate elements & print them
	std::unordered_map<int, int> hashmap;
	for (int i = 0; i < size; i++)
	{
		if (hashmap.find(temp[i]) != hashmap.end()) {
			hashmap[temp[i]]++;
		}
		else {
			hashmap.insert(std::pair<int,int>(temp[i], 1));
		}
	}

	std::cout << "The duplicate elements are: ";
	for (std::unordered_map<int, int>::iterator i = hashmap.begin(); i != hashmap.end(); i++) {
		if (i->second > 1) {
			std::cout << i->first << " ";
		}
	}

	printf("\n");
	std::cout << "The array elements are: ";
	for (int i = 0; i < size; i++) {
		std::cout << temp[i] << " ";
	}

	std::cin.get();
}